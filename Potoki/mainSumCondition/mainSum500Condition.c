#include <stdio.h>
#include <ctype.h>
 #include <pthread.h>
 #include <sys/types.h>

 pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t con=PTHREAD_COND_INITIALIZER;

void * func(void * param)  
{
	 
	long i;
	long tmp;
//	long *  ptr=(long *) param; 
	long *  ptr;
	 ptr= (long *) param; 

			  
		for(i=0;i<100000;i++)
		 {	
		   pthread_mutex_lock(&mutex);		
		  pthread_cond_wait(&con,&mutex); 	 
			  tmp=*ptr; 
			  tmp++;
			  *ptr=tmp; 
		   pthread_mutex_unlock(&mutex); 
		     
		 } 	 
	
	 
   return (void*)0;		
}

void * func1()  
{   unsigned  int k;
	while(1)
	{
	   k=k+1;
      if(k==2) {pthread_cond_signal(&con);k=0;}
    }  	 
}

 int main() 
 { 
	
	unsigned  int i; 
	
	long param=0;
	pthread_t tid[500];
	pthread_t Count;
	
	pthread_mutex_init;
	pthread_cond_init;
	
	pthread_create(&Count,NULL,func1, NULL);
	
	for(i=0;i<500;i++) 
	 {
		pthread_create(&tid[i],NULL,func, &param);
	 }	 
	 for(i=0;i<500;i++) 
	 {		  
		pthread_join(tid[i],NULL);
	 }	
	  pthread_cancel(Count);
	 printf("%ld \n", param);
	 return 0;
 }	 
