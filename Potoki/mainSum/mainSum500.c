#include <stdio.h>
#include <ctype.h>
 #include <pthread.h>
 #include <sys/types.h>


void * func(void * param)  
{
	long i;
	long tmp;
//	long *  ptr=(long *) param; 
	long *  ptr;
	 ptr= (long *) param; 
	
	for(i=0;i<10000000;i++)
	 {
	  tmp=*ptr; 
	  tmp++;
	  *ptr=tmp;   
	 } 	 
   return (void*)0;		
}


 int main() 
 { 
	unsigned  int i; 
	long param=0;
	pthread_t tid[500];
	for(i=0;i<500;i++) 
	 {
		pthread_create(&tid[i],NULL,func, &param);
	 }	 
	 for(i=0;i<500;i++) 
	 {
		pthread_join(tid[i],NULL);
	 }	
	 
	 printf("%ld \n", param);
	 return 0;
 }	 
