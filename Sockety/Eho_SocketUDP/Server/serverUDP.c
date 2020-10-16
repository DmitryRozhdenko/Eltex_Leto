
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
 int listener;  //sock, 
 struct sockaddr_in servaddr,clientaddr;
 char buf[1024];
 int bytes_read;
 socklen_t len;
 
	listener = socket(AF_INET, SOCK_DGRAM, 0); // создаем точку соединения(сокет) и дискриптор датаграммного сокета SOCK_DGRAM
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
	// заполняем поля структуры адреса, задающей параметры сокета 
	servaddr.sin_family = AF_INET;  //Протоколы интернет IPv4 
	servaddr.sin_port = htons(3425); // преобразование в сетевой порядок номера порта,по которому идёт передача
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);// преобразование в сетевой порядок IP-адрес
		if(bind(listener, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)// связывание сокета с end-point
		{
		  perror("bind");
		  exit(2);
		}
	
		while(1)
		{
	
		len =sizeof(clientaddr);
		while(1)
		{
		  bytes_read = recvfrom(listener , buf, 1024, 0,(struct sockaddr *)&clientaddr,&len);// ожидаем приходящие данные от клиента  
		
		  buf[0]=' ';	  //заменяю пробелом 0-ой байт в принятых данных
		  sendto(listener , buf, bytes_read, 0, (struct sockaddr *)&clientaddr,sizeof(clientaddr));// отправляем принятые данные клиенту
		}
	    	close(listener );
		}
return 0;
}

