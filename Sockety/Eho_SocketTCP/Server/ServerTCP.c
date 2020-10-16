#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
 int sock, listener;
 struct sockaddr_in addr;
 char buf[1024];
 int bytes_read;
 
	listener = socket(AF_INET, SOCK_STREAM, 0); // создаем точку соединения(сокет) и дискриптор потокового сокета SOCK_STREAM
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
		// заполняем поля структуры адреса, задающей параметры сокета
	addr.sin_family = AF_INET;   //Протоколы интернет IPv4 
	addr.sin_port = htons(3425);  // преобразование в сетевой порядок номера порта,по которому идёт передача
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // преобразование в сетевой порядок IP-адрес
		if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)  // связывание сокета с end-point
		{
		  perror("bind");
		  exit(2);
		}
	listen(listener,1); // позволяет потоковому сокету SOCK_STREAM принимать входящие соединения от других сокетов;размер
  //             очереди входящих подключений равен 1
		while(1)
		{
		  sock = accept(listener, NULL, NULL);  // создаём слушающий сокет
		if(sock < 0)
		{
		  perror("accept");
		  exit(3);
		}
		while(1)
		{
		  bytes_read = recv(sock, buf, 1024, 0); // ожидаем приходящие данные от клиента
		  if(bytes_read <= 0) break;
		  
		  buf[0]=' ';	 //заменяю пробелом 0-ой байт в принятых данных
		  send(sock, buf, bytes_read, 0);  // отправляем принятые данные клиенту
		}
	    	close(sock);
		}
return 0;
}
