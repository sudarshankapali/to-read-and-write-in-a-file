/******************************************************** Cafeteria Management System Project ******************************************************/ 
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void food();
void list();
void lib();
void del();
void menu();
void income();
struct menu{
int id;
int da;
int pay;
char info;
int total;
int xday;
int xmonth;
int xyear;
}s;
FILE *p,*q;
int paidamt=0,order=0,clramt=0,so=0,clrid=0,calcclr=0,delid,seada=0,seaid=0,dueamt=0,sum=0,retamt,totalamt=0,expamt=0,billamt=0,prf=0,ch1=0,ch2=0,cho=0,ch3=0,cp=0;
char ch,next;
char another=0;
SYSTEMTIME stime;
int main()
{
	char y1;
	GetSystemTime(&stime);
	s.xday=stime.wDay;
	s.xmonth=stime.wMonth;
	s.xyear=stime.wYear;
	char password[55],pass[]="1234";      /*********************************************** For password ************************************************/ 
	int x=0,z=0;                          /************************************************ For password ***********************************************/
                       /******************************************* To order from another food category ******************************/
	fold:
	p=fopen("C:\\tyu.txt","r+");
	if(p==NULL)
	{
		p=fopen("C:\\tyu.txt","w+");
		if(p==NULL)
		{
			printf("Error");
			exit(0);
		}
		fclose(p);
		goto fold;
	}
	printf("\n\n\n\n\n\n\n\t\t\t\t\t______________________________________");
	printf("\n\t\t\t\t\tEnter Password:");
	do{ 
        password[z]=getch(); 
        if(password[z]!='\r')
		{ 
            printf("*"); 
        } 
        z++; 
    }while(password[z-1]!='\r'); 
	password[z-1]='\0'; 
    for(z=0;pass[z]!='\0';z++)
    {
    	if(pass[z]!=password[z])
    	{
    		x++;
		}
	}
	if(x==0)
	{
		menu();
	}
	else
	{
		printf("\n\t\t\t\t\tWrong password");
		exit(0);
	}
	getch();
}
void menu()
{
while(1)
		{
			//opt :
			system("cls");
			printf("___________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
			printf("\t\t\t\t\t\t*..........................*\n");
			printf("\t\t\t\t\t\t\tKIST CAFETERIA\n");
   			printf("___________________________________________________________________________________________________________________________________________________________________________________________________________________");					
			printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWe have following menu:\n\n");
			printf("\t\t\t\t\t\t1. Food and Drinks\n");
			printf("\t\t\t\t\t\t2. View List\n");
			printf("\t\t\t\t\t\t3. Liability List\n");
			printf("\t\t\t\t\t\t4. Delete record\n");
			printf("\t\t\t\t\t\t5. Income and expense\n");
			printf("\t\t\t\t\t\t6. Exit\n");
			printf("\t\t\t\t\t\tChoose from the above list: ");
			ch=getche();
			switch(ch)
			{
				/************************************************************ Food Category ***************************************************************************/
				case '1':
				{
					food();
					break;
				}
			/************************************************* VIEW LIST *************************************************************************/
			case '2':			
			{
				list();
				break;
			}
			/************************************************** LIABITIES LIST *************************************************************/
		case '3' :
		{
			lib();
			break;
		}
			/****************************************************** DELETE LIST **************************************************************/
			case '4':
			{
				del();
				break;
			}
		/**************************************************** INCOME\EXPENSES ****************************************************************/	
			case '5':
				{
				 	income();
				 	break;
				}
			case '6':
			exit(0);
				break;
				default :
				system("cls");
				printf("Not viable option.Press any button: ");
				getch();
				//goto opt;
			}
		}
}
/************************************************************************* [FUNCTION] *****************************************************************************/
/**************************************************** INCOME\EXPENSES ****************************************************************/
		void income()
		{
			
			system("cls");
			printf("Input how much was just expense today ?: ");
			scanf("%d",&expamt);
			rewind(p);
			printf("Daily Profit/Loss\n");
			while(fread(&s,sizeof(s),1,p)==1)
	 		{
				if(s.xday==stime.wDay && s.xmonth==stime.wMonth && s.xyear==stime.wYear)
				{	
					totalamt=totalamt+s.pay;
				}
			}
			printf("Total amount earned today=%d",totalamt);
			prf=totalamt-expamt;
			if(prf>0)
			{
				printf("\nProfit=%d",prf);
			}
			else if(prf<0)
			{
				printf("\nLoss=%d",-1*prf);
			}
			else
			{
				printf("\nThere was neither profit or loss");
			}
			getch();
	}
	/****************************************************** DELETE LIST **************************************************************/
	void del()
	{
	
	system("cls");
			fflush(stdin);
			printf("Enter the id of the record you want ot delete: ");
			scanf("%d",&delid);
			q=fopen("C:\\dele.txt","w+");
			if(p==NULL)
			{
				printf("\nError");
			}
			rewind(p);
			while(fread(&s,sizeof(s),1,p)==1)
			{
				if(s.id!=delid)
				{
					fwrite(&s,sizeof(s),1,q);
				}
			}
			fclose(p);
			fclose(q);
			remove("C:\\tyu.txt");
			rename("C:\\dele.txt","c:\\tyu.txt");
			printf("\nRecord Deleted");
			p=fopen("C:\\tyu.txt","r+");
			getch();
		}
			/************************************************** LIABITIES LIST *************************************************************/
			void lib()
			{
			
			system("cls");	
		rewind(p);	
			printf("1. View Student List\n");
		printf("2. View Teacher List\n");
		printf("3. view a specific record from the list\n");
		scanf("%d",&ch3);
		switch(ch3)
			{
				case 1:
				{
					while(fread(&s,sizeof(s),1,p)==1)	
					{
						if(s.info=='s'||s.info=='S')
						{
							if(s.da>0)
							{
								printf("Id=%d\t",s.id);
								printf("Amt=%d\n",s.da);
							}
						}
					}
				}
				break;
				case 2:
				{
					while(fread(&s,sizeof(s),1,p)==1)
					{
						if(s.info=='t'||s.info=='T')
						{
							if(s.da>0)
							{
								printf("Id=%d\t",s.id);
								printf("Amount=%d\n",s.da);
							}
						}
					}
				}break;
				case 3:
					{
					
					printf("input the id you want to search:\n");
					scanf("%d",&seaid);
					while(fread(&s,sizeof(s),1,p)==1)
					{
						if(seaid==s.id)
						{
							seada=seada+s.da;
						}
					}
					printf("id=%d\t",seaid);
					printf("due amount=%d",seada);
				}
		break;			
		}
			getch();
	}
	/************************************************* VIEW LIST *************************************************************************/
	void list()
	{
	system("cls");	
			rewind(p);	
			printf("1. View Student List\n");
			printf("2. View Teacher List\n");
			printf("3. View all list\n");
			scanf("%d",&ch2);
			switch(ch2)
			{
				/********************************************* STUDENT LIST **************************************************************************/
				case 1:
				while(fread(&s,sizeof(s),1,p)==1)
				{
					if(s.info=='s'|| s.info=='S')
					{
						printf("id=%d\t\t",s.id);
						if(s.da<0)
						{
							s.da=0;
							printf("Due Amount=%d\t\t",s.da);
						}
						else
						{
							printf("Due Amount=%d\t\t",s.da);
						}
						printf("Paid Amount=%d\t\t",s.pay);
						printf("Total Amount=%d ",s.total);
						printf("\t\tDate=%d//%d//%d\n",s.xday,s.xmonth,s.xyear);
					}
				}
				getch();	
	break;
			
			/********************************************************** TEACHER LIST ****************************************************************/
			case 2 :
				{
				
			while(fread(&s,sizeof(s),1,p)==1)
			{
				if(s.info=='t'|| s.info=='T')
				{
					printf("id=%d\t",s.id);
					if(s.da<0)
				{
					s.da=0;
					printf("Due Amount=%d\t",s.da);
				}
				else
				{
					printf("Due Amount=%d\t",s.da);
				}
				printf("Paid Amount=%d\t",s.pay);
				printf("Total Amount=%d\t",s.total);
				printf("Date=%d//%d//%d\n",s.xday,s.xmonth,s.xyear);
			}
		}
	}
	getch();	
	break;
		/*************************************** All list **************************************************/
		case 3 :
			{
system("cls");	
			rewind(p);		
			while(fread(&s,sizeof(s),1,p)==1)
			{
				printf("id=%d\t",s.id);
				if(s.da<0)
				{
					s.da=0;
					printf("due amount=%d\t",s.da);
				}
				else
				{
					printf("due amount=%d\t",s.da);
				}
				printf("paid amount=%d\t",s.pay);
				printf("total amount=%d\t",s.total);
				printf("date=%d//%d//%d\n",s.xday,s.xmonth,s.xyear);
			}	
	}
	
		printf("Press any key to go to Main Menu:");
		getch();	
	break;
	}
}
	/*********************************************************************************************************************/
	void food()
	{
		system("cls");
				fseek(p,0,SEEK_END);
				printf("Enter 'S' for Student or 'T'for teacher(S/T): ");
				scanf("%s",&s.info);
				start:
				another=0; 
				next='y';
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEnter your food category\n");
				printf("\t\t\t\t\t\t1.Veg\n");
				printf("\t\t\t\t\t\t2.Non-veg\n");
				printf("\t\t\t\t\t\t3.Drinks\n");
				printf("\t\t\t\t\t\t4.Snacks\n");
		        printf("\t\t\t\t\t\t5.Dessert\n");
				printf("\t\t\t\t\t\tChoose an option ");
				scanf("%d",&cho);
				if(cho==2)
				{
					/************************************************* Non-Veg Food Menu ************************************************************************/ 
					system("cls");
					printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWe have following menu:\n\n");
					printf("\t\t\t\t\t1.Chicken Momo-.............................Rs 90\n");
					printf("\t\t\t\t\t2.Chicken Chowmein-.........................Rs 80\n");
					printf("\t\t\t\t\t3.Chicken Burger-...........................Rs 70\n");
					printf("\t\t\t\t\t4.Chicken Biriyani-.........................Rs 100\n");
					printf("\t\t\t\t\t5.Buff Momo-................................Rs 70\n");
					printf("\t\t\t\t\t6.Pork Momo-................................Rs 70\n");
					printf("\t\t\t\t\t7.Buff/Chicken Sausage-.....................Rs 30\n");
					printf("\t\t\t\t\t8.Egg Kattiroll-............................Rs 120\n");
					printf("\t\t\t\t\t9.Chicken Kattiroll-........................Rs 150\n");
					printf("\t\t\t\t\t10.Chicken Drumstick-.......................Rs 70\n");
					printf("\t\t\t\t\t11.Chicken pizza-...........................Rs 110\n");
					printf("\t\t\t\t\t12.Buff Friedrice-..........................Rs 70\n");
					printf("\t\t\t\t\t13.Chicken Friedrice-.......................Rs 80\n");
					printf("\t\t\t\t\t14.Sausage Pizza-...........................Rs 100\n");
					printf("\t\t\t\t\t15.Chicken Tandori-.........................Rs 200\n");
					while(next=='y' || next=='Y')
					{
 						printf("\n\t\t\t\t\tPlease Enter Your Order: ");
 						scanf("%d",&order);
 						ch1=order;
						switch(ch1)
 						{
  							case 1:
  							sum=sum+90;
  							break;
  							case 2:
							sum=sum+80;
  							break;
  							case 3:
							sum=sum+70;
							break;
							case 4:
  							sum=sum+100;
  							break;
  							case 5:
  							sum=sum+70;
  							break;
  							case 6:
  							sum=sum+70;
  							break;
  							case 7:
  							sum=sum+30;
  							break;
  							case 8:
  							sum=sum+120;
  							break;
  							case 9:
  							sum=sum+150;
  							break;
  							case 10:
  							sum=sum+70;
  							break;
  							case 11:
  							sum=sum+110;
  							break;
  							case 12:
  							sum=sum+70;
  							break;
  							case 13:
  							sum=sum+80;
  							break;
  							case 14:
  							sum=sum+100;
  							break;
  							case 15:
  							sum=sum+200;
  							break;
  							default:
  							printf("\n\t\t\t\t\tWrong Choice");
  							//goto opt;
						}
						printf("\t\t\t\t\tDo you want another order?\n\t\t\t\t\tIf Yes then please press 'Y' else press 'N': ");
 						next=getche();
 						fflush(stdin);
 						
					}
					printf("\n\t\t\t\t\tDo you want to order from another category?\n");
					printf("\t\t\t\t\tIf Yes then Please Enter 'y' else Enter 'n':");
					another=getche();
					
					if(another=='y'|| another=='Y')
					{
						goto start;
					}
				}
				else if(cho==1)
			{
				/************************************************************** Veg-Food Menu ***********************************************************************/ 
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWe have following menu:\n\n");
				printf("\t\t\t\t\t1.Garlic Potato-.......................Rs 60\n");
				printf("\t\t\t\t\t2.Veg Chowmein-........................Rs 50\n");
				printf("\t\t\t\t\t3.Veg Momo-............................Rs 60\n");
				printf("\t\t\t\t\t4.Potato Chips-........................Rs 50\n");
				printf("\t\t\t\t\t5.Burger-..............................Rs 90\n");
				printf("\t\t\t\t\t6.Sandwitch-...........................Rs 70\n");
				printf("\t\t\t\t\t7.Puri Tarkari-........................Rs 80\n");
				printf("\t\t\t\t\t8.Alu Paratha-.........................Rs 60\n");
				printf("\t\t\t\t\t9.French Fry-..........................Rs 50\n");
				printf("\t\t\t\t\t10.Samosa Tarkari-.....................Rs 80\n");
				printf("\t\t\t\t\t11.Alu Chana-..........................Rs 40\n");
				printf("\t\t\t\t\t12.Pasta-..............................Rs 50\n");
				printf("\t\t\t\t\t13.Veg Burger-.........................Rs 60\n");
				printf("\t\t\t\t\t14.Veg Kattiroll-......................Rs 70\n");
				printf("\t\t\t\t\t15.Paneer Friedrice-...................Rs 80\n");
				while(next=='y' || next=='Y')
				{
					 printf("\n\t\t\t\t\tPlease Enter Your Order: ");
					 scanf("%d",&order);
					ch1=order;
					switch(ch1)
 					{
  						case 1:
 	 					sum=sum+60;
  						break;
						case 2:
						sum=sum+50;
						break;
						case 3:
						sum=sum+60;
						break;
  						case 4:
  						sum=sum+50;
  						break;
  						case 5:
  						sum=sum+90;
  						break;
  						case 6:
  						sum=sum+70;
  						break;
  						case 7:
  						sum=sum+80;
  						break;
  						case 8:
  						sum=sum+60;
  						break;
  						case 9:
  						sum=sum+50;
  						break;
  						case 10:
  						sum=sum+80;
  						break;
  						case 11:
  						sum=sum+40;
  						break;
  						case 12:
  						sum=sum+50;
  						break;
  						case 13:
  						sum=sum+60;
  						break;
  						case 14:
  						sum=sum+70;
  						break;
  						case 15:
  						sum=sum+80;
  						break;
  						default:
						printf("\nWrong Choice");
						//goto opt;
					}
					printf("\n\t\t\t\t\tDo you want another order?\n\t\t\t\t\tIf Yes then please press 'Y' else press 'N':  ");
					next=getche();
					fflush(stdin);
				}
				printf("\n\t\t\t\t\tDo you want to order from another category?\n");
					printf("\t\t\t\t\tIf Yes then Please Enter 'y' else Enter 'n':");
					another=getche();
					
					if(another=='y'|| another=='Y')
					{
						goto start;
					}
			}
			else if(cho==3)
			{
				/********************************************************** Drinks Menu *******************************************************************/ 
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWe have following menu:\n\n");
				printf("\t\t\t\t\t1.Coffee-..............................Rs 50\n");
				printf("\t\t\t\t\t2.Cold Drinks-.........................Rs 40\n");
				printf("\t\t\t\t\t3.Milk Tea-............................Rs 25\n");
				printf("\t\t\t\t\t4.Fruit Juice-.........................Rs 35\n");
				printf("\t\t\t\t\t5.Chocolate Milk-......................Rs 30\n");
				printf("\t\t\t\t\t6.Capuccino-...........................Rs 50\n");
				printf("\t\t\t\t\t7.Americano-...........................Rs 60\n");
				printf("\t\t\t\t\t8.Espresso-............................Rs 50\n");
				printf("\t\t\t\t\t9.Latte-...............................Rs 80\n");
				printf("\t\t\t\t\t10.Mocha-..............................Rs 70\n");
				printf("\t\t\t\t\t11.Coconut Juice-......................Rs 40\n");
				printf("\t\t\t\t\t12.Smoothies-..........................Rs 100\n");
				printf("\t\t\t\t\t13.Green Tea-..........................Rs 30\n");
				printf("\t\t\t\t\t14.Red Bull-...........................Rs 90\n");
				printf("\t\t\t\t\t15.Frooti-.............................Rs 25\n");
				while(next=='y' || next=='Y')
				{
					printf("\n\t\t\t\t\tPlease Enter Your Order: ");
 					scanf("%d",&order);
 					ch1=order;
					switch(ch1)
					{
  						case 1:
  						sum=sum+50;
  						break;
						case 2:
						sum=sum+40;
						break;
  						case 3:
						sum=sum+25;
						break;
						case 4:
						sum=sum+35;
						break;
						case 5:
						sum=sum+30;
						case 6:
  						sum=sum+50;
  						break;
  						case 7:
  						sum=sum+60;
  						break;
  						case 8:
  						sum=sum+50;
  						break;
  						case 9:
  						sum=sum+80;
  						break;
  						case 10:
  						sum=sum+70;
  						break;
  						case 11:
  						sum=sum+40;
  						break;
  						case 12:
  						sum=sum+100;
  						break;
  						case 13:
  						sum=sum+30;
  						break;
  						case 14:
  						sum=sum+90;
  						break;
  						case 15:
  						sum=sum+25;
  						break;
						default:
						printf("\nWrong Choice");
						//goto opt;
					}
					printf("\t\t\t\t\tDo you want another order?\n\t\t\t\t\tIf Yes then please press 'Y' else press 'N' ");
					next=getche();
 					fflush(stdin);
				}
				printf("\n\t\t\t\t\tDo you want to order from another category?\n");
					printf("\t\t\t\t\tIf Yes then Please Enter 'y' else Enter 'n':");
					another=getche();
					
					if(another=='y'|| another=='Y')
					{
						goto start;
					}
			}
			else if(cho==4)
			{
				/************************************************************* Snacks Menu **********************************************************************/ 
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWe have following menu:\n\n");
				printf("\t\t\t\t\t1.Chatpate-..............................Rs 50\n");
				printf("\t\t\t\t\t2.Pop Corn-..............................Rs 50\n");
				printf("\t\t\t\t\t3.Fruit Salad-...........................Rs 65\n");
				printf("\t\t\t\t\t4.Jelly Cup with Fruit-..................Rs 75\n");
				printf("\t\t\t\t\t5.Cookies-...............................Rs 60\n");
				printf("\t\t\t\t\t6.Muffins-...............................Rs 50\n");
				printf("\t\t\t\t\t7.Chips-.................................Rs 40\n");
				printf("\t\t\t\t\t8.Current Noodles-.......................Rs 60\n");
				printf("\t\t\t\t\t9.Nimkin/Dalmot-.........................Rs 40\n");
				printf("\t\t\t\t\t10.Pickelets-............................Rs 80\n");
				printf("\t\t\t\t\t11.Toast-................................Rs 50\n");
				printf("\t\t\t\t\t12.Bread Omlet-..........................Rs 70\n");
				printf("\t\t\t\t\t13.Hot Dog-..............................Rs 90\n");
				printf("\t\t\t\t\t10.Alu Chop-.............................Rs 60\n");
				printf("\t\t\t\t\t10.Pakoda-...............................Rs 50\n");
				while(next=='y' || next=='Y')
				{
					printf("\n\t\t\t\t\t\tPlease Enter Your Order: ");
 					scanf("%d",&order);
 					ch1=order;
					switch(ch1)
					{
  						case 1:
  						sum=sum+50;
  						break;
						case 2:
						sum=sum+50;
						break;
  						case 3:
						sum=sum+65;
						break;
						case 4:
						sum=sum+75;
						break;
						case 5:
						sum=sum+60;
						break;
						case 6:
						sum=sum+50;
						break;
						case 7:
						sum=sum+40;
						break;
						case 8:
						sum=sum+60;
						break;
						case 9:
						sum=sum+40;
						break;
						case 10:
						sum=sum+80;
						break;
						case 11:
  						sum=sum+50;
  						break;
  						case 12:
  						sum=sum+70;
  						break;
  						case 13:
  						sum=sum+90;
  						break;
  						case 14:
  						sum=sum+60;
  						break;
  						case 15:
  						sum=sum+50;
  						break;
						default:
						printf("\nWrong Choice");
						//goto opt;
					}
					printf("\t\t\t\t\tDo you want another order?\n\t\t\t\t\tIf Yes then please press 'Y' else press 'N': ");
					next=getche();
					fflush(stdin);
				}
				printf("\n\t\t\t\t\tDo you want to order from another category?\n");
					printf("\t\t\t\t\tIf Yes then Please Enter 'y' else Enter 'n':");
					another=getche();
					
					if(another=='y'|| another=='Y')
					{
						goto start;
					}
			}
			else if(cho==5)
			{
				/************************************************** Dessert Food Menu **************************************************************************/ 
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWe have following menu:\n\n");
				printf("\t\t\t\t\t1.Ice Cream-..................................Rs 70\n");
				printf("\t\t\t\t\t2.Black/White Forest-.........................Rs 90\n");
				printf("\t\t\t\t\t3.Waffle-.....................................Rs 75\n");
				printf("\t\t\t\t\t4.Cream Doughnut-.............................Rs 50\n");
				printf("\t\t\t\t\t5.Fruit Pie-..................................Rs 60\n");
				printf("\t\t\t\t\t6.Stawberry Sundae-...........................Rs 80\n");
				printf("\t\t\t\t\t7.Pastry-.....................................Rs 60\n");
				printf("\t\t\t\t\t8.Peanut Butter Bread-........................Rs 90\n");
				printf("\t\t\t\t\t9.Fruit Cake-.................................Rs 100\n");
				printf("\t\t\t\t\t10.Gulab Jamun-...............................Rs 20\n");
				printf("\t\t\t\t\t11.Kaju Barfi-................................Rs 25\n");
				printf("\t\t\t\t\t12.Jerry-.....................................Rs 15\n");
				printf("\t\t\t\t\t13.Laalmon-...................................Rs 30\n");
				printf("\t\t\t\t\t14.Soan Papdi-................................Rs 60\n");
				printf("\t\t\t\t\t15.Haluwa-....................................Rs 60\n");
				while(next=='y' || next=='Y')
				{
					printf("\n\t\t\t\t\tPlease Enter Your Order: ");
 					scanf("%d",&order);
 					ch1=order;
					switch(ch1)
					{
  						case 1:
  						sum=sum+70;
  						break;
						case 2:
						sum=sum+90;
						break;
  						case 3:
						sum=sum+75;
						break;
						case 4:
						sum=sum+50;
						break;
						case 5:
						sum=sum+60;
						break;
						case 6:
						sum=sum+80;
						break;
						case 7:
						sum=sum+60;
						break;
						case 8:
						sum=sum+90;
						break;
						case 9:
						sum=sum+100;
						break;
						case 10:
						sum=sum+20;
						break;
						case 11:
						sum=sum+25;
						break;
						case 12:
						sum=sum+15;
						break;
						case 13:
						sum=sum+30;
						break;
						case 14:
						sum=sum+60;
						break;
						case 15:
						sum=sum+60;
						break;
						default:
						printf("\nWrong Choice");
						//goto opt;
					}
					printf("\t\t\t\t\tDo you want another order?\n\t\t\t\t\tIf Yes then please press 'Y' else press 'N' ");
					next=getche();
 					fflush(stdin);
				}
				printf("\n\t\t\t\t\tDo you want to order from another category?\n");
					printf("\t\t\t\t\tIf Yes then Please Enter '1' else Enter any key:");
					another=getche();
					
					if(another=='y'|| another=='Y')
					{
						goto start;
					}
			}
			else
			{
				system("cls");
				printf("\n\t\t\t\t\t\tWrong Choice:");
			}
			/********************************************************************* BILL SECTION *******************************************************/
			printf("\n\t\t\t\t\tEnter ID: ");
			scanf("%d",&s.id);
			printf("\t\t\t\t\tYour bill amount:%d \n",sum);
			printf("\t\t\t\t\tPaid Amount: ");
			scanf("%d",&paidamt);
			s.total=sum;
			dueamt=sum-paidamt;
			if(dueamt<0)
			{
				s.da=0;
			}
			else
			s.da=dueamt;
			s.pay=paidamt;
			if(s.pay>sum)
			{
				retamt=s.pay-sum;
				s.pay=s.pay-retamt;
			}
			else
			{
				retamt=0;
			}
			fwrite(&s,sizeof(s),1,p);
			sum=0;
			/****************************************************** DUE AMOUNT **********************************************************************/
			if(dueamt>0)
			{
				printf("\t\t\t\t\tDue Amount: %d\n\t\t\t\t\tRetamt=%d",s.da,retamt);
			}
			else
			{
				s.da=0;
				printf("\t\t\t\t\tDue Amount=%d\n\t\t\t\t\tReturn amount=%d\n",s.da,retamt);
			}
			getch();
			}

