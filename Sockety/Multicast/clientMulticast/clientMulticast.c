#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
 #include <netinet/ip.h> 
#include <netinet/in.h> 


   char buf[1024]; 
int main()
{  	 
	   struct ip_mreqn  imr; // объявили структуру многоадресной группы
		int sock;
		socklen_t len;
		struct sockaddr_in addr;// объявить структуру, задающей параметры для связи сокета
		 
		//printf("Hi! \n	");	
		sock = socket(AF_INET, SOCK_DGRAM, 0);// создаем точку соединения(сокет) и дискриптор датаграммного сокета SOCK_DGRAM
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}	
		// заполняем поля структуры адреса, задающей параметры сокета 	
		addr.sin_family = AF_INET;//Протоколы интернет IPv4
		addr.sin_port = htons(3345);// преобразование в сетевой порядок номера порта,по которому идёт передача
		addr.sin_addr.s_addr = htons(INADDR_ANY); // преобразование в сетевой порядок IP-адрес 
	 if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)// связывание сокета с end-point
	     {
		   perror("bind");
		   exit(2);
		 }	
		// заполняем поля структуры , задающей параметры многоадресной группы 	
	      imr.imr_multiaddr.s_addr =inet_addr("225.0.0.1");  /* IP-адрес группы */  
          imr.imr_address.s_addr = htons(INADDR_ANY);// (INADDR_ANY); /* IP локального интерфейса */   
          imr.imr_ifindex=0;   /* индекс интерфейса */	 
         setsockopt(sock,IPPROTO_IP,IP_ADD_MEMBERSHIP,&imr,sizeof(imr)); //Присоединиться к многоадресной группе
       	
		   
        len =sizeof(addr);
		recvfrom(sock, buf,1024,0,(struct sockaddr *)&addr,&len); 	// ожидаем приходящие данные от сервера 	
	//	printf("%ld",strlen(buf));
	printf("%s",buf); //вывести принятые данные

		close(sock); 
return 0;

}



