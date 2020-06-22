#include <stdio.h>

#define N 9///строки
//#define M 3///столбцы

int main() {
	unsigned char a[N][N];
     unsigned char i,y,temp;
     printf("исходный массив %d",N);
     printf("x%d\n",N);
   for(i=0;i<N;i=i+1)
   {
        for(y=0;y<N;y=y+1)
        {
			if((N-y)>(i+1))a[i][y]=0;
			 else a[i][y]=1;			
         printf(" %d",a[i][y]); 
        }
        printf(" \n");
    } 
    
     for(i=0;i<(N-1);i=i+1)
      {
        for(y=0;y<(N-i-1);y=y+1)
        {
		  temp= a[i][y]; 
		  a[i][y]=a[N-y-1][N-i-1];
		 a[N-y-1][N-i-1]=temp;	  				        
        }       
     }  
     printf(" \n");
     for(i=0;i<N;i=i+1)
      {
        for(y=0;y<N;y=y+1)
        {  
       printf(" %d",a[i][y]); 
      
        }
         printf(" \n");
       }
} 


