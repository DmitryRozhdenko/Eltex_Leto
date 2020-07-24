#include <stdio.h>
#include <ctype.h>
 #include <pthread.h>
 #include <sys/types.h>


void * func(void * param)  
{
   int*ptr;
   ptr=(int *)param;  
   printf("I %d thread \n",*ptr);
   return (void*)0;		
}


 int main() 
 { 
	unsigned  char i; 
	pthread_t tid[5];
	for(i=0;i<5;i++) 
	 {
		pthread_create(&tid[i],NULL,func, &i);
	 }	 
	 for(i=0;i<5;i++) 
	 {
		pthread_join(tid[i],NULL);  // вернуть может ошибки,а если вместо NULL статус был,то вернёт значение функции которую запустил  creat в потоке
	 }	
	 
	 return 0;
 }	 
