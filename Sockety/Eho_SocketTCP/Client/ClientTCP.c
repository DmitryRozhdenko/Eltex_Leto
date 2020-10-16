#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char message[] = "Hello !\n";
char buf[sizeof(message)];
int main()
{
		int sock;
		struct sockaddr_in addr;
		sock = socket(AF_INET, SOCK_STREAM, 0);// создаем точку соединения(сокет) и дискриптор потокового сокета SOCK_STREAM
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}
		// заполняем поля структуры адреса, задающей параметры сокета
		addr.sin_family = AF_INET; //Протоколы интернет IPv4
		addr.sin_port = htons(3425); // преобразование в сетевой порядок номера порта,по которому идёт передача
		addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // преобразование в сетевой порядок IP-адрес
		
		if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)  // установить соединение с сервером
		{
		perror("connect");
		exit(2);
		}
		send(sock, message, sizeof(message), 0); //отправить данные Hello ! к серверу
		recv(sock, buf, sizeof(message), 0);// ожидаем приходящие данные от сервера
		printf("%s",buf);   //вывести принятые данные
		while(1);
		close(sock);
return 0;

}


