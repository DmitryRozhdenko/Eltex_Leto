/* #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> */
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
 int listener,i;  //sock, 
 struct sockaddr_in servaddr,clientaddr;
 char buf[1024];
 int bytes_read;
 socklen_t len;
 memset(buf, 0, sizeof(buf));
	listener = socket(AF_INET, SOCK_DGRAM, 0);  //// создаем точку соединения(сокет) и дискриптор сокета
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
		////  заполняем структуру, задающей параметры  сокета для отправки клиенту 	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(3425);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		if(bind(listener, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) //// связывание сокета с end-point
		{
		  perror("bind");
		  exit(2);
		}
	
	
		len =sizeof(clientaddr);
		while(1)
		{ 
		  bytes_read = recvfrom(listener , buf, 1024, 0,(struct sockaddr *)&clientaddr,&len);  // ожидаем сообщение от клиента
		  
		/* printf("%d \n",bytes_read );*/
		
		  for(i=0;i<64;i++)       // выводим принятое сообщение
	      {
	       printf("%c",buf[i]);
	      }
	      printf("\n");
		 if(bytes_read <= 0) break;  
		 
		  buf[1]='Z';	
		/*   for(i=0;i<64;i++)
	       {
	        printf("%c",buf[i]);
	       }
	     printf("\n"); */
	     // отправляем изменённое сообщение клиенту
		  sendto(listener , buf, bytes_read, 0, (struct sockaddr *)&clientaddr,sizeof(clientaddr));
		  sleep(5);
		}
		
	    	close(listener );
return 0;
}

