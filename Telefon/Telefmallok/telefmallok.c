#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
    struct Abonent
	  {
		unsigned  char Nomer[10]; 
		 unsigned char Famil[10];
		 unsigned char Name[10];
    	 unsigned char DlinNom;		 
	  };

 int main() 
 {    
	 unsigned char t,vcOper;
	 unsigned char vcCountCyfr,vcRabota,i,k,y;
	  unsigned char CntAb;	
	  unsigned char DelNomAbn[2]; 
	  unsigned char TempFamil[10]; 
	    char *ptr1;
	      
		  
	// struct Abonent Chel;
	 struct Abonent	*ptr;
//	 ptr1= (char*)malloc(60);
//	 ptr1= (char*)malloc(50);
     ptr1= (char*)calloc(31, sizeof(char));     
     ptr=(struct Abonent *)ptr1;
           
     for(i=0;i<10;i++)
	   {  
		   TempFamil[i]=0; 		  
	   }	
	   
	    CntAb=0;  
	   vcRabota=0;
	   vcCountCyfr=0;
	  
	while(1)
	 { 
		if(vcRabota==10)break;
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
			  if(t>=49 && t<54 && vcCountCyfr==0)
			  {
				 vcOper=t-48; 
				 vcCountCyfr=1;
	
			  }
			  else if(t==10)
			  {	
				  
				if(vcOper!=5)
				{ vcRabota=2;}
				  else { vcRabota=10; printf("завершено  \n");free(ptr1);	}	//	free(ptr1);	  				
			  }
	   
		   break;
		   
		   case 2:     /// НАЧАЛО ОБРАБОТКИ КОМАНД МЕНЮ
					  switch (vcOper)
				     { 
					   case 1:
					   printf("введите телефон добавляемого абонента (не больше 10знаков) \n");
					   if(CntAb==0) 
					    { 							
						  CntAb=CntAb+1;
						  vcRabota=3;					  
						}
					  else 
					   {CntAb=CntAb+1;
						    ptr1 = (char*)realloc(ptr1,31*CntAb);						       
                            ptr=(struct Abonent *)ptr1;	
                            	
                           ptr=ptr+CntAb-1;	 
                           for(k=0;k<10;k++) 
							   {
								   ptr->Nomer[k]=0;
								   ptr->Famil[k]=0;
						    	   ptr->Name[k]=0;								   
							   }
							   ptr->DlinNom=0;
							   								     						    
						   vcRabota=3;
						   
					   }
					      
					   break;						   				   
					   case 2:							    							  						  		     
					     printf("список абонентов\n");
					     if(CntAb==0) printf("пуст\n");
					     else
					     {  ptr=(struct Abonent *)ptr1;
							 for(i=0;i<CntAb;i++)
							  {							 
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
							     ptr=ptr+1;
							  }	
							}    
						  	vcRabota=0;		     
					   break;					   
					   case 3:							   			    
					     printf("введите порядковый номер абонента в справочнике(не больше 99),которого нужно удалить\n");
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
									  else {if(DelNomAbn[0]!=0)i=DelNomAbn[0]-1;
										     else {printf("неправильный номер\n"); vcRabota=0;break; }
									  }
								if(CntAb>1)	  
								 {
								   for(y=i;y<(CntAb-1);y++)	 
								    {ptr=((struct Abonent *)ptr1+y);
										  for(k=0;k<10;k++) 
										   {
											   ptr->Nomer[k]= (ptr+1)->Nomer[k];
											   ptr->Famil[k]=(ptr+1)->Famil[k];
											   ptr->Name[k] =(ptr+1)->Name[k];
											  
										   }
									   	 ptr->DlinNom =(ptr+1)->DlinNom;	
									 } 	
									ptr1 = (char*)realloc(ptr1,31*CntAb);	 
								 } 
								 else 
								   {  ptr=(struct Abonent *)ptr1;
									  for(k=0;k<10;k++) 
										   {
											   ptr->Nomer[k] = 0;
											   ptr->Famil[k] = 0;
											   ptr->Name[k] = 0;											  
										   }
									   	 ptr->DlinNom =0; 
								   }   
									 if(CntAb>0)CntAb=CntAb-1;	
									  						   	 
									 vcRabota=0;
						             vcCountCyfr=0;  
						             DelNomAbn[0]=0;
						             DelNomAbn[0]=0;	
						             								  				
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
								  ptr=(struct Abonent *)ptr1;								  
								  for(i=0;i<CntAb;i++)
								   { vcCountCyfr=0;
									 ptr=((struct Abonent *)ptr1)+i;  
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
						          for( i=0;i<10;i++){TempFamil[i]=0; }
						       if(vcRabota!=15) printf("абонента нет в списке\n"); 
						          vcRabota=0;
						          	 vcCountCyfr=0;					       
					          } 
              
              break;  
                       
		  }
     } 
     return 0; 
 } 



