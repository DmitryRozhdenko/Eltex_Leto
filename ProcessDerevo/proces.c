 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>
#include <stdio.h>

       pid_t pid[5];


 int main() 
 {   
	  int i;
	 
	 printf ("Мой идентификатор процесс с pid=%d!\n",getpid());
	 printf ("Идентификатор родителя с ppid=%d \n",getppid());
	 
	 pid[0]=fork();
	 
	 if(pid[0] == 0)   //  дочерний процесс
	  {
		 printf ("Мой ppid1=%d!\n",getppid());
		 printf ("Мой pid1=%d!\n",getpid());
		 pid[1]=fork();
		// 
		  if(pid[1] == 0)
	      {
			printf ("Мой ppid4=%d!\n",getppid());
		    printf ("Мой pid4=%d!\n",getpid());
		   //  wait(&i);   
	      }	  
		 else //if(pid[4] == 0)
		   {
			    pid[4]=fork(); 
			   if(pid[4] == 0)
			   {
			    printf ("Мой pid5=%d!\n",getpid());
			     printf ("Мой ppid5=%d!\n",getppid()); 
			  //   wait(&i);
			   } 
			   else{
				    wait(&i);        
		             wait(&i);
			       } 
			       
		   }   
		           // wait(&i);        
		           //  wait(&i);
	  }
     else if(pid[0] != 0)  // родительский процесс
	   {
	    // printf ("Мой pid4=%d!\n",getpid());
	    // printf ("Мой ppid4=%d!\n",getppid());
	     pid[2]=fork(); 
	     if(pid[2] == 0)
	      {
	        printf ("Мой ppid2=%d!\n",getppid());
	        printf ("Мой pid2=%d!\n",getpid());
	        pid[3]=fork(); 
	        if(pid[3]==0)
	        {
				 printf ("Мой ppid3=%d!\n",getppid());
	              printf ("Мой pid3=%d!\n",getpid());
	          //   	             
			}
			else  wait(&i); 
		//	wait(&i); 
	      } else wait(&i); 
	   // wait(&i); 
	  //  wait(&i); 
       }
	 
	  
	
	 
	 return 0;
 } 
 

