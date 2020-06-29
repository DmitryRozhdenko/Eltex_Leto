#include <stdio.h>

 //int Slozhit(unsigned int Op1,unsigned int Op2);

int Slozhit( int Op1, int Op2)
 { 
    int Result;   //unsigned 
     Result=Op1+Op2;
	return  Result;
 }
 
int Vichest(int Op1, int Op2)
 {
	int Result;   //unsigned 
     Result=Op1-Op2;
	return  Result; 
 }	 
 
int Proizv(int Op1, int Op2)
 { 
     int Result;  //unsigned
     Result=Op1*Op2;
	return  Result; 
 }
 
int Delenie(int Op1, int Op2)
 {	 
	 int Result;  //unsigned
     Result=Op1/Op2;
	return  Result;
 }	 
 
int Preobrazovat(unsigned char cn,unsigned char zn,unsigned char * massiv)
 {
	 int  result;   //  unsigned
	 switch (cn)
        {
		   case 1:
		    result=massiv[0];
		   break;
		   case 2:
		    result=massiv[0]*10+massiv[1];		    
		   break;
		   case 3:
		    result=massiv[0]*100+massiv[1]*10+massiv[2];
		   break;
		   case 4:
		    result=massiv[0]*1000+massiv[1]*100+massiv[2]*10+massiv[3];
		   break;
		   case 5:
		    result=massiv[0]*10000+massiv[1]*1000+massiv[2]*100+massiv[3]*10+massiv[4];
		   break;
		}  
		if(zn==1)result=-result;
		return result;
 }	 

 int main() 
 {    
	 int Result;
	 unsigned int t,vcOper;
	 unsigned char vcCountCyfr,vcRabota,i;
	 struct chislo
	  {
		 int ChisloOp; //unsigned 
		 unsigned char countCifr;
		 unsigned char Cifra[5];
		 unsigned char znak;		 
	  };
	  
	 struct chislo Operand1; 
	 struct chislo Operand2;
	 

	   vcRabota=0;
	   vcCountCyfr=0;
	   Operand1.countCifr=0;
	   Operand2.countCifr=0;
	while(1)
	 { 
		
	   switch  (vcRabota)
        {
		   case 0:
				   
				printf("			МЕНЮ \n");
				printf("			 \n");
				printf("1 - сложить  \n");
				printf("2 - вычесть  \n");
				printf("3-  умножить  \n");
				printf("4 - разделить  \n");
				printf("5 - завершить  \n");
				printf("			 \n");
				printf("введите код операции \n");
				vcRabota=1;
			
		   break;
		   case 1:
		   
		    t=getchar();
			  if(t>=49 && t<54 && vcCountCyfr==0)
			  {
				 vcOper=t-48; 
				 vcCountCyfr=1;
	
			  }
			  else if(t==10)
			  {	
				 if(vcOper!=5)
				{ vcRabota=2; printf("введите первый операнд (не больше 5 знаков) \n");}
				  else  vcRabota=4; 
				
			  }
	   
		   break;
   
		   case 2:
	   
				  t=getchar();
				  if(t>=48 && t<58 && Operand1.countCifr<5)
				  {
					Operand1.Cifra[Operand1.countCifr]=t-48;
					Operand1.countCifr= Operand1.countCifr+1; 
			
				  }
				  else if(t==45 && Operand1.countCifr==0)Operand1.znak=1;
					  else if(t==10)
					  {
						Operand1.ChisloOp=Preobrazovat(Operand1.countCifr,Operand1.znak,Operand1.Cifra);
						printf(" введите второй операнд (не больше 5 знаков)\n"); 
						vcRabota=3; 
					  } 
			 
		 break;
   
		 case 3:
	   
			  t=getchar();
			  if(t>=48 && t<58 && Operand2.countCifr<5)
			  {
				 Operand2.Cifra[Operand2.countCifr]=t-48;
				 Operand2.countCifr= Operand2.countCifr+1; 				  
				
			  }
			  else if(t==45 && Operand2.countCifr==0)Operand2.znak=1;
			    else if(t==10) 
				 {	
					Operand2.ChisloOp = Preobrazovat(Operand2.countCifr,Operand2.znak,Operand2.Cifra);
					 
					 vcRabota=4; 	 
				 }
		 break;
     
           case 4:
          
				    switch  (vcOper)
				     {
					   case 1:
					    Result=Slozhit(Operand1.ChisloOp,Operand2.ChisloOp);
					     printf("сумма %d\n", Result);
					   break;						   				   
					   case 2:
					     Result=Vichest(Operand1.ChisloOp,Operand2.ChisloOp);
					     printf("разность %d\n", Result);
					   break;					   
					   case 3:
					    Result=Proizv(Operand1.ChisloOp,Operand2.ChisloOp);
					     printf("произведение %d\n", Result);
					   break;					   
					   case 4:
					     Result=Delenie(Operand1.ChisloOp,Operand2.ChisloOp);
					     printf("деление %d\n", Result);
					   break;					   
					   case 5:
					     vcRabota=6; 
					     printf("завершено \n"); 
					   break;
					}
					if(vcRabota!=6)
					 {
						vcRabota=5;  
						vcCountCyfr=0;
						Operand1.countCifr=0;
						Operand2.countCifr=0;
						Operand1.znak=0;
						Operand2.znak=0;
						for(i=0;i<5;i++)
						 {
							Operand1.Cifra[i]=0; 
							Operand2.Cifra[i]=0; 
					     }	
					     printf("             \n");	
					     printf("нажмите enter\n");	 
				     }		 
              break;
              
              case 5:
                t=getchar();
				  if(t==10)
				  {
					vcRabota=0; 
				  }
              break;
		  }
     }
 } 



