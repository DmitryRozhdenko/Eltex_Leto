#include <stdio.h>

#define N 3///строки
#define M 3///столбцы

int main() {
	unsigned char a[N][M];
     unsigned char i,y,count;
     count=0;
   for(i=0;i<N;i=i+1)
   {
        for(y=0;y<N;y=y+1)
        {
			count=count+1;
          a[i][y]=count;
         printf(" %d",a[i][y]); 
        }
        printf(" \n");
    }    
} 
 
  
