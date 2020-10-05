#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <linux/udp.h>
#include <linux/ip.h>
 #include <linux/if_packet.h>
 #include <net/ethernet.h>
 #include <linux/if_ether.h>

int checkSum(char*buffer);

char message[] = "Hello !\0";
            
int main()
{
	   
		int sock,val;
		int i,t;
		socklen_t len;
		struct sockaddr_ll addr;
	  // struct udphdr *udp;
		char buf[90];  
		char rcv[92];
		memset(buf, 0, sizeof(buf));
		memset(rcv, 0, sizeof(rcv));
		buf[50]='A';
		
		// заполнение полей заголовка  уровня связи
		
		addr.sll_family=AF_PACKET;
		addr.sll_halen=ETH_ALEN;
		addr.sll_ifindex=if_nametoindex("enp1s0");  // eth0
		
		sock = socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL));//// создаем точку соединения(сокет) и дискриптор сокета RAW
			if(sock < 0)
			{
			perror("socket");
			exit(1);
			}
		struct  ether_header * ethh = (struct ether_header *) buf; // указатель buf ориентировать на структуру struct ether_header(канал.заголовок)	
		
			ethh->ether_dhost[0]=0x52;	/* destination eth addr	*/
			ethh->ether_dhost[1]=0x54;
			ethh->ether_dhost[2]=0x00;
			ethh->ether_dhost[3]=0xe5;
			ethh->ether_dhost[4]=0x72;
			ethh->ether_dhost[5]=0x0d ;
				/* source ether addr	*/
            ethh->ether_shost[0]=0x98; 
            ethh->ether_shost[1]=0x29;
            ethh->ether_shost[2]=0xA6;
            ethh->ether_shost[3]=0x49;
            ethh->ether_shost[4]=0x13;
            ethh->ether_shost[5]=0xD5;
            	
            ethh->ether_type=ETH_P_IPX;	//0x8137		/* Internet Protocol packet	*/ //	/* IPX over DIX	ETH_P_IP;	// 0x0800	
            
	/*		//  заполняем структуру end-point для отправки серверу 		
		addr.sin_family = AF_INET;
    	addr.sin_port = htons(3425);
		addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); 
			val=1;
			//установить параметр IP_HDRINCL,чтобы заполнять вручную некоторые поля сетевого уровня
		 if(setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &val, sizeof(val)) < 0) 
		  {
             perror("setsockopt() error");
             exit(2);
          }	
	 */
	    len =sizeof(addr);
	   struct iphdr *ip = (struct iphdr *)(buf+ sizeof(struct ether_header)); // указатель (buf+14) ориентировать на структуру struct iphdr
	     //  заполняем сетевой уровень для отправки серверу 
			ip->ihl      = 5;
			ip->version  = 4;
			ip->tos      = 0; 
			ip->tot_len  =90;
			ip->frag_off =0x00;
			ip->id       = 0;
			ip->ttl      = 64; 
			ip->protocol = 17; // UDP			
			ip->saddr = htonl(INADDR_LOOPBACK);  //0;
			ip->daddr = htonl(INADDR_LOOPBACK); // htonl(INADDR_ANY);
			ip->check =checkSum(buf); 
			// указатель (buf+34) ориентировать на структуру struct udp
		 struct udphdr *udp = (struct udphdr *) (buf + sizeof(struct ether_header) + sizeof(struct iphdr));
	 //  заполняем транспортный уровень для отправки серверу 	   
	    udp->dest = htons(3425); //порт сервера,приводим в формат сетевой
	    udp->source = htons(3000);//порт клиента,приводим в формат сетевой
	    udp->check = 0;	     
	    udp->len = htons(64);// длина посылки 
	    // printf("%ld",strlen(message));
	    strncpy(buf+42,message,strlen(message)); // добавить к заголовку канального+сетевого+транспортного  уровня передаваемое сообщение
	 /*   for(i=0;i<64;i++)
	    {
	    printf("%c",buf[i]);
	} */
		sendto(sock, buf,1024 , 0,(struct sockaddr *)&addr,sizeof(addr));  // отправить сообщение Hello !   // 64
	while(1)
     {
		t=recvfrom(sock, rcv, 42+64,0,(struct sockaddr *)&addr,&len); //канальный(14)+сетевой(20)трансп(8)+приемные данные
		udp = (struct udphdr *)((char *)rcv + 34);//указатель udp указать на приёмный буфер минуя заголовок канального и сетевого уровня 
		if(ntohs(udp->dest) == 3000)break;	// слушать порт,который настроен на приём
			
     }
  //   printf("%d",t);
	//	printf("AAA\n");

	   for (i = 42; i < 92;i ++)
	    { // выводить приёмный буфер, минуя канальный(14) сетевой (20 байт) и транспортный уровень (8 байт)
			printf("%c",rcv[i]);
		
		}
		printf("\n");
		close(sock);
return 0;

}

int checkSum(char*buffer)
 {   int tmp;
	 char i;
	int csum=0;
	short*ptr;
	ptr=(short*)buffer;
	for(i=0;i<10;i++) 
	 {
		csum=csum+ptr;
		ptr++; 
	 }	
	 tmp=csum>>16;
	 csum=csum+tmp;
	 csum=~csum;
	 return csum; 
 }	 

