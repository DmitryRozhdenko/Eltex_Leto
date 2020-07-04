#include <stdio.h>
#include <ctype.h>
    struct Abonent
	  {
		unsigned  int Nomer[10]; //
		 unsigned char Famil[10];
		 unsigned char Name[10];
    	 unsigned char DlinNom;		 
	  };

 int main() 
 {    
	 unsigned int t,vcOper;
	 unsigned char vcCountCyfr,vcRabota,i,k;
	  unsigned char CntAb;	
	  unsigned char DelNomAbn[2]; 
	  unsigned char TempFamil[10]; 
		  
	 struct Abonent Chel[10]; 
	 struct Abonent	*ptr;
	 
	  for(i=0;i<10;i++)
	   {  
		   TempFamil[i]=0; 
		   ptr=&Chel[i];
		  for(k=0;k<10;k++) 
		   {
			   ptr->Nomer[k]=0;
			   ptr->Famil[k]=0;
			   ptr->Name[k]=0;
			   ptr->DlinNom=0;
		   }
	   }	   
	    CntAb=0;  
	   vcRabota=0;
	   vcCountCyfr=0;
	  
	while(1)
	 { 
		
	   switch  (vcRabota)
        {
		   case 0:    ///  МЕНЮ СПРАВОЧНИКА
				   
				printf("	 МЕНЮ справочника \n");
				printf("			 \n");
				printf("1 - добавить абонента \n");
				printf("2 - просмотреть список абонентов \n");
				printf("3-  удалить абонента  \n");
				printf("4-  найти абонента  \n");
				printf("5 - завершить  \n");
				printf("			 \n");
				printf("введите пункт меню \n");
				vcRabota=1;
			   vcCountCyfr=0;
		   break;
		  case 1:     /// ВВОД КОМАНДЫ МЕНЮ
		   
		    t=getchar();
			  if(t>=49 && t<53 && vcCountCyfr==0)
			  {
				 vcOper=t-48; 
				 vcCountCyfr=1;
	
			  }
			  else if(t==10)
			  {	
				  
				if(vcOper!=5)
				{ vcRabota=2;}
				  else { vcRabota=10; printf("завершено  \n");	}			  				
			  }
	   
		   break;
		   
		   case 2:     /// НАЧАЛО ОБРАБОТКИ КОМАНД МЕНЮ
					  switch (vcOper)
				     { 
					   case 1:
					   if(CntAb<10) 
					    { printf("введите телефон добавляемого абонента (не больше 10знаков) \n");							
						  
						  for(i=0;i<10;i++)
						    {  ptr=&Chel[i];
								if((ptr->Name[0])==0) {vcRabota=3;CntAb=CntAb+1; break;	}				      
					        }
						}
					     else {printf("превышено количество добавляемых абонентов  \n");vcRabota=0;}
					      
					   break;						   				   
					   case 2:							    							  						  		     
					     printf("список абонентов\n");
					     for(i=0;i<10;i++)
					      {
							 ptr=&Chel[i];
							 printf("%d.  ",i+1);
							 for(k=0;k<ptr->DlinNom;k++)
							  {	
								  printf("%d",ptr->Nomer[k]);
								 
							  }  
							   printf("			 \n"); 
							    printf("  "); 
							  for(k=0;k<10;k++)
							  {	
								 if(isalpha(ptr->Famil[k]))
								  {printf("%c",ptr->Famil[k]);}
								  
							  }  
							   printf("			 \n"); 
							      printf("  "); 
							  for(k=0;k<10;k++)
							  {	
								 if(isalpha(ptr->Name[k]))
								  printf("%c",ptr->Name[k]);
								  
							  }  
							  printf("			 \n"); 
						  }	  
						  	vcRabota=0;		     
					   break;					   
					   case 3:							   			    
					     printf("введите порядковый номер абонента в справочнике,которого нужно удалить\n");
					     vcRabota=6;
					   break;	
					   case 4:							   			    
					     printf("введите фамилие абонента (не больше 10 знаков),которого нужно найти\n");
					     vcRabota=7;
					   break;
					   
					   				   					 
					 }		        
		           vcCountCyfr=0;
		     break;
		   
             case 3:    /// ВВОД НОМЕРА ТЕЛЕФОНА АБОНЕНТА                 
					      t=getchar();
							  if(isdigit(t) && (vcCountCyfr<10))
							  {
								ptr->Nomer[vcCountCyfr]=t-48;
								vcCountCyfr=vcCountCyfr+1; 						
							  }
							  else if(t==10)
					          {	
								  ptr->DlinNom=	vcCountCyfr;				        
						         printf(" введите фамилие абонента\n"); 
						          vcRabota=4;
						          vcCountCyfr=0;						       
					          } 					    					
             break;
             case 4: /// ВВОД ФАМИЛИИ АБОНЕНТА
                           t=getchar();
							  if(isalpha(t) && (vcCountCyfr<10))
							  {
								ptr->Famil[vcCountCyfr]=t;
								vcCountCyfr=vcCountCyfr+1; 						
							  }
							  else if(t==10)
					          {										  				        
						         printf(" введите Имя абонента\n"); 
						          vcRabota=5;
						          	 vcCountCyfr=0;					       
					          } 
                         
             
              break;
              case 5:    /// ВВОД ИМЕНИ АБОНЕНТА
                           t=getchar();
							  if(isalpha(t) && (vcCountCyfr<10))
							  {
								ptr->Name[vcCountCyfr]=t;
								vcCountCyfr=vcCountCyfr+1; 						
							  }
							  else if(t==10)
					          {		
								   vcRabota=0;
								  if(vcCountCyfr==0){ printf(" введите Имя абонента\n");vcRabota=5; }			        					         						           
						          vcCountCyfr=0;						       
					          } 
             
             
              break;
              case 6: /// ВВОД ПОРЯДКОВОГО НОМЕРА УДАЛЯЕМОГО АБОНЕНТА В СПРАВОЧНИКЕ
					   t=getchar();
					        if(isdigit(t) && (vcCountCyfr<2))
							  {
								DelNomAbn[vcCountCyfr]=t-48;
								vcCountCyfr=vcCountCyfr+1; 						
							  }
							  else if(t==10)
								  {	
									 if(vcCountCyfr==2) i=(DelNomAbn[0]*10+DelNomAbn[1])-1;
									  else i=DelNomAbn[0]-1;
									 ptr=&Chel[i];
									  for(k=0;k<10;k++) 
									   {
										   ptr->Nomer[k]=0;
										   ptr->Famil[k]=0;
										   ptr->Name[k]=0;
										   ptr->DlinNom=0;
									   }	
									  vcRabota=0;
						             vcCountCyfr=0;  
						             DelNomAbn[0]=0;
						             DelNomAbn[0]=0;	
						             if(CntAb>0)CntAb=CntAb-1;									  				
								  }
              break;
              
              case 7:    ///ПОИСК АБОНЕНТА
                              t=getchar();
							  if(isalpha(t) && (vcCountCyfr<10))
							  {
								TempFamil[vcCountCyfr]=t;
								vcCountCyfr=vcCountCyfr+1; 						
							  }
							  else if(t==10)
					          {	
								  
								  for(i=0;i<10;i++)
								   { vcCountCyfr=0;
									 ptr=&Chel[i];  
									  for(k=0;k<10;k++)
									   { if(TempFamil[k]==ptr->Famil[k])
									     vcCountCyfr=vcCountCyfr+1;
								       }
								       if(vcCountCyfr==10)
								       {
										 printf("абонент есть в списке\n"); 
											printf("%d.  ",i+1);
											 for(k=0;k<ptr->DlinNom;k++)
											  {	
												  printf("%d",ptr->Nomer[k]);
												 
											  }  
											   printf("			 \n"); 
												printf("  "); 
											  for(k=0;k<10;k++)
											  {	
												 if(isalpha(ptr->Famil[k]))
												  {printf("%c",ptr->Famil[k]);}
												  
											  }  
											   printf("			 \n"); 
												  printf("  "); 
											  for(k=0;k<10;k++)
											  {	
												 if(isalpha(ptr->Name[k]))
												  printf("%c",ptr->Name[k]);
												  
											  }  
											  printf("			 \n"); 
											  vcRabota=15;
									         break;
									   }
									   
								   }   									  				        
						        for(i=0;i<10;i++){TempFamil[i]=0; }
						       if(vcRabota!=15) printf("абонента нет в списке\n"); 
						          vcRabota=0;
						          	 vcCountCyfr=0;					       
					          } 
              
              break;
                           
		  }
     }  
 } 



