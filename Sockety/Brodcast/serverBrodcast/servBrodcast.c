
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

int main()
{
 char message[] = "Hello !\0";
 int listener,val;  //sock, servaddr,
 struct sockaddr_in clientaddr;// объявить структуру, задающей параметры для связи сокета
 
 //socklen_t len;
 
	listener = socket(AF_INET, SOCK_DGRAM, 0); // создаем точку соединения(сокет) и дискриптор датаграммного сокета SOCK_DGRAM
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
		val=1;
	setsockopt(listener,SOL_SOCKET,SO_BROADCAST,&val,sizeof(val));	//Разрешить отправку широковещательных пакетов
		
	// заполнение структуры 
	clientaddr.sin_family = AF_INET;//Протоколы интернет IPv4
	clientaddr.sin_port = htons(7777);// преобразование в сетевой порядок номера порта,по которому идёт передача
	clientaddr.sin_addr.s_addr = inet_network("255.255.255.255"); // преобразование в сетевой порядок IP-адрес BROADCAST 
	
	
		  sendto(listener ,message, strlen(message), 0, (struct sockaddr *)&clientaddr,sizeof(clientaddr));		//
	  
		close(listener );
return 0;
}

