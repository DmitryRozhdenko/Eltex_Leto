
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
 int listener; 
 struct sockaddr_in clientaddr; 

// int bytes_read;
// socklen_t len;

	listener = socket(AF_INET, SOCK_DGRAM, 0);// создаем точку соединения(сокет) и дискриптор датаграммного сокета SOCK_DGRAM
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
	// заполняем поля структуры , задающей параметры сокета 	 
	clientaddr.sin_family = AF_INET;//Протоколы интернет IPv4
	clientaddr.sin_port = htons(3345);// преобразование в сетевой порядок номера порта,по которому идёт передача
	clientaddr.sin_addr.s_addr = inet_addr("225.0.0.1");// преобразование в сетевой порядок IP-адрес 
	
	
 sendto(listener ,message, strlen(message), 0, (struct sockaddr *)&clientaddr,sizeof(clientaddr));	//отправить данные Hello ! клиенту
	  
		close(listener );
return 0;
}

