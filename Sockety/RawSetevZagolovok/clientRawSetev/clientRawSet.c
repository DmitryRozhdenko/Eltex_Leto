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
#include <linux/*.h>

char message[] = "Hello !\0";
            
int main()
{
		int sock,val;
		int i,t;
		socklen_t len;
		struct sockaddr_in addr;
	  // struct udphdr *udp;
		char buf[64];  
		char rcv[92];
		memset(buf, 0, sizeof(buf));
		memset(rcv, 0, sizeof(rcv));
		buf[50]='A';
		
		struct iphdr *ip = (struct iphdr *) buf; // указатель buf ориентировать на структуру struct iphdr
       
		//udp=(struct udphdr *)buf;
		sock = socket(AF_INET,SOCK_RAW ,IPPROTO_UDP);//// создаем точку соединения(сокет) и дискриптор сокета RAW
			if(sock < 0)
			{
			perror("socket");
			exit(1);
			}
			//  заполняем структуру end-point для отправки серверу 		
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
	 
	    len =sizeof(addr);
	   
	     //  заполняем сетевой уровень для отправки серверу 
			ip->ihl      = 5;
			ip->version  = 4;
			ip->tos      = 0; 
			ip->tot_len  =0;
			ip->frag_off =0x00;
			ip->id       = 0;
			ip->ttl      = 0; 
			ip->protocol = 17; // UDP
			
			ip->saddr = 0;
			ip->daddr = htonl(INADDR_LOOPBACK); // htonl(INADDR_ANY);
			ip->check =0;  
		 struct udphdr *udp = (struct udphdr *) (buf + sizeof(struct iphdr));// указатель (buf+20) ориентировать на структуру struct udp
	 //  заполняем транспортный уровень для отправки серверу 	   
	    udp->dest = htons(3425); //порт сервера,приводим в формат сетевой
	    udp->source = htons(3000);//порт клиента,приводим в формат сетевой
	    udp->check = 0;	     
	    udp->len = htons(64);// длина посылки 
	    // printf("%ld",strlen(message));
	    strncpy(buf+28,message,strlen(message)); // добавить к заголовку транспортного + сетевого уровня передаваемое сообщение
	 /*   for(i=0;i<64;i++)
	    {
	    printf("%c",buf[i]);
	} */
		sendto(sock, buf,1024 , 0,(struct sockaddr *)&addr,sizeof(addr));  // отправить сообщение Hello !
	while(1)
     {
		t=recvfrom(sock, rcv, 28+64,0,(struct sockaddr *)&addr,&len); //трансп(8)+сетевой(20)+приемные данные
		udp = (struct udphdr *)((char *)rcv + 20);//указатель udp указать на приёмный буфер минуя заголовок сетевого уровня
		if(ntohs(udp->dest) == 3000)break;	// слушать порт,который настроен на приём
			
     }
  //   printf("%d",t);
	//	printf("AAA\n");

	   for (i = 28; i < 92;i ++)
	    { // выводить приёмный буфер, минуя сетевой (20 байт) и транспортный уровень (8 байт)
			printf("%c",rcv[i]);
		
		}
		printf("\n");
		close(sock);
return 0;

}



