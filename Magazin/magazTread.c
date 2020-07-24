 #include <stdio.h>
 #include <ctype.h>
 #include <pthread.h>
 #include <sys/types.h>
 #include <unistd.h>


 unsigned  int Magazin[5];
  pthread_mutex_t mutex[5] = PTHREAD_MUTEX_INITIALIZER;
 
 struct Buy
	  {		
		 unsigned char Buyer;
		 unsigned  int Tovar;		 
	  };



void * Shopping(void * param)  
{
	unsigned char i,man;
    unsigned  int tovar; 
	 struct Buy * ptr;
	
	 ptr= (struct Buy *)  param; 	
	 tovar=ptr->Tovar;
	 man=ptr->Buyer;
	 	    
	while(tovar<10000)
	 {
		sleep(2);
		for(i=0;i<5;i++)
		 {
			if(pthread_mutex_trylock(&mutex[i])!=0)
			 { 
			 if(Magazin[i]>0)	 
	           {
				   if((10000-tovar)>Magazin[i]){tovar=tovar+Magazin[i];Magazin[i]=0;}
				 else { Magazin[i]=Magazin[i]-(10000-tovar); tovar=10000;} 
				 printf("в магазин %d зашёл покупатель с номером %d ,у него стало товара %d \n",i+1,man,tovar);	
				 
			   }      
			   else printf("в магазин %d зашёл покупатель с номером %d он не купил ничего \n",i+1,man);
		       
		      
		        pthread_mutex_unlock(&mutex[i]);
		       break;  
		       	      
		     }				     		      
		 }
	 
	 }	 		 
   return (void*)0;		
}

void * Loading()  // void * param1
 {
	unsigned char i;
   
	 	    
	while(1)
	 {
		sleep(1);
		for(i=0;i<5;i++)
		 {
			if(pthread_mutex_trylock(&mutex[i])!=0)
			 { 
	           Magazin[i]=Magazin[i]+500;		  
		       printf("в магазин  %d ,загрузили товар,стало %d \n",i+1,Magazin[i]);	
		       pthread_mutex_unlock(&mutex[i]);
		       	break;      
		     }			
		 }
	 
	 }	 		 
   return (void*)0;	 
 }


int main() 
 { 
	unsigned  int i;    
    	
	struct Buy  TovarBuyer[3];
    
	pthread_t Pokupatel[3];
	pthread_t Pogruzchik;
	
	  pthread_mutex_init;
	for(i=0;i<5;i++)
	 {
	   Magazin[i]=500;
	 
	 }
	 	   
	for(i=0;i<3;i++) 
	 {
		TovarBuyer[i].Buyer=i+1;
		TovarBuyer[i].Tovar=0;
		pthread_create(&Pokupatel[i],NULL,Shopping, &TovarBuyer[i]);
	 }	
	  pthread_create(&Pogruzchik,NULL,Loading , NULL);
	  
	  
	 for(i=0;i<3;i++) 
	 {
		pthread_join(Pokupatel[i],NULL);
	 }	
	 pthread_cancel(Pogruzchik);
	 
	
	 return 0;
 }	 
