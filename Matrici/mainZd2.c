#include <stdio.h>

#define N 5///


int main() {
	unsigned char a[N]={1,2,3,4,5};
     unsigned char i,temp,temp2;
     
   for(i=0;i<N;i=i+1)
   {
	   if(i<((N-1)-i))
	   {
         temp=a[(N-1)-i]; 
         temp2=a[i];
       a[i]=temp;
      a[N-1-i]=temp2;

       }
      printf(" %d",a[i]); 
    }   	
   
} 
