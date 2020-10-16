

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

char message[] = "Hello !\n";
char buf[sizeof(message)];


int main()
{
	   
		int sock;
		socklen_t len;
		struct sockaddr_in addr;// объявить структуру, задающей параметры для связи сокета
		sock = socket(AF_INET, SOCK_DGRAM, 0);// создаем точку соединения(сокет) и дискриптор датаграммного сокета SOCK_DGRAM
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}
	
		
		// заполняем поля структуры адреса, задающей параметры сокета 
		addr.sin_family = AF_INET;//Протоколы интернет IPv4
		addr.sin_port = htons(7777);// преобразование в сетевой порядок номера порта,по которому идёт передача
		addr.sin_addr.s_addr = inet_network("255.255.255.255");   // // преобразование в сетевой порядок IP-адрес BROADCAST 
        if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)// связывание сокета с end-point
	     {
		   perror("bind");
		   exit(2);
		 }
	   len =sizeof(addr);
	
		recvfrom(sock, buf,1024,0,(struct sockaddr *)&addr,&len); // ожидаем приходящие данные от сервера 	
	//	printf("%ld",strlen(buf));
		printf("%s",buf);  //вывести принятые данны

		close(sock);
return 0;

}



