#include <stdio.h>

#define N 5///строки
//#define M 3///столбцы


int main() {
	unsigned char a[N][N];
     unsigned char i;  //строки 
     unsigned char y;   //столбцы
     unsigned char prochod,count;   //

       count=0;
   for(prochod=0;prochod<N/2+1;prochod=prochod+1)
    {       i=prochod;
		   for(y=prochod;y<(N-prochod);y=y+1)
		   {   count=count+1;
				a[i][y]=count;						 								
			} 
				
			y=N-prochod-1;					
			 for(i=prochod+1;i<N-prochod;i=i+1)
		   {   count=count+1;
				a[i][y]=count;						 							
			} 
			 i=N-prochod-1;
		   for(y=N-prochod-2;y>prochod;y=y-1)
		   {   count=count+1;
				a[i][y]=count;		
				
			} 
			y=prochod;					
			 for(i=N-prochod-1;i>prochod;i=i-1)
		   {   count=count+1;
				a[i][y]=count;						 							
			} 

	}		 
     
     for(i=0;i<N;i=i+1)
      {
        for(y=0;y<N;y=y+1)
        {  
       printf(" %d",a[i][y]); 
      
        }
         printf(" \n");
       }
} 


