#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <linux/udp.h>

           

int main()
{
		int sock;
	////	int i,t;
		socklen_t len;
		struct sockaddr_in addr;
	    struct udphdr *udp;
		char rcv[1024+28];
		memset(rcv, 0, sizeof(rcv));  //обнулить приёмный буфер
	
		udp=(struct udphdr *)rcv;
		sock = socket(AF_INET,SOCK_RAW ,IPPROTO_UDP); //// создаем точку соединения(сокет) и дискриптор сокета RAW
			if(sock < 0)
			{
			perror("socket");
			exit(1);
			}
	//  заполняем структуру, задающей параметры  сокета RAW		
	
	//	addr.sin_family = AF_INET;
	//	addr.sin_addr.s_addr = htonl(INADDR_ANY);   
	    len =sizeof(addr);
	 
	while(1)
     {
		recvfrom(sock,rcv,28+1024,0,(struct sockaddr *)&addr,&len); //трансп(8)+сетевой(20)+приемные данные
	 udp = (struct udphdr *)((char *)rcv + 20);//указатель udp указать на приёмный буфер,включая транспортный уровень,минуя заголовок сетевого уровня			   
        printf("dest %d  \n ",(ntohs(udp->dest) ));    //порт назначения
        printf("source %d  \n ",(ntohs(udp->source) )); //порт источника
     	printf("\n");
	 }	
		close(sock);
     return 0;

}



