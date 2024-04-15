//saz's diner
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdlib.h>
#include <windows.h> 

/*
What does What?
1. Generates the bill
{
    struct menutemplate  
    struct payable
    genhead()
    genbody()
    genbill()
    genfoot()

}

2.Ask the user for inputs & create a interface
{
  gendash()
  getorder()
  genmenu()
}

3.Provide transitions to program
{
  USING  system("cls"); [which is part of the stdlib.h]
}

4.File handling
{
  fwrite(addressof str var,sizeof(str var),no of instances, filepointer) 
  fread(addressof str var,sizeof(str var),no of instances, filepointer)
  
  note:-
  This program writes the structures to the files as structures themselves and not as strings. Same goes for reading.
}
*/

struct menutemplate
{
   char name[100];
   int price;
};
//this structure just serves the purpose of having place fillers name and price of food items 

struct payable
{
    char item[100];
    char date[100];
    int price;
    int qty; 
    int total;
} ;
//this structure serves the purpose of being the tamplate of list of items which should be paid for

struct menutemplate menulist[100]={
    {"MOMO", 100},
    {"Chatpate", 50},
    {"Khaja set", 300},
    {"Chowmein", 150},
    {"Sekuwa", 100},
    {"Alu platter", 350},
    {"Cold Lemon", 30},
    {"Hot lemon", 30},
    {"Cold drinks", 70},
    {"Spring water", 50}
};
// manual initialization of menulist with items and their prices


void genhead(char date[],char customer[])
{
  // printf("\t\t\tSaz's diner\n");
  printf("\n\t\t\t\t\t\t\t\t---------------------------------------");
  printf("\n\t\t\t\t\t\t\t\t\t\t\033[1;34mSaz's Diner\n\033[0m");
  printf("\t\t\t\t\t\t\t\t---------------------------------------\n");
  printf("\t\t\t\t\t\t\t\tDate:%s\n",date);
  printf("\t\t\t\t\t\t\t\tInvoice to:%s\n",customer ); 
  printf("\t\t\t\t\t\t\t\t---------------------------------------\n");
}
//this function generates the head of the bill

void genbody(struct payable items[], int ordersize, int *subtotal) 
{
*subtotal=0;
printf("\n\t\t\t\t\t\t\t\tItems\t\tQty\tprice\tTotal\n");
printf("\t\t\t\t\t\t\t\t---------------------------------------\n");
for(int i=1;i<=ordersize;i++)
{
  printf("\n\t\t\t\t\t\t\t\t%12s\t%d\t%d\t%d",items[i-1].item,items[i-1].qty,items[i-1].price,items[i-1].total);
  *subtotal+=items[i-1].total;
}
 printf("\n\t\t\t\t\t\t\t\t---------------------------------------\n");
}
//this funciton generates the body of the bill which consists of the table of particulars and the qty,price and total cost

void genbill(int *subtotal)
{
  float tax,servicecharge,grandtotal;
  tax=0.16*(*subtotal);
  servicecharge=0.1*(*subtotal);
  grandtotal=(*subtotal)+tax+servicecharge;
  printf("\t\t\t\t\t\t\t\tSubtotal\t\t%d",(*subtotal));
  printf("\n\t\t\t\t\t\t\t\tTax @ 16%%\t\t%f",tax);  
  printf("\n\t\t\t\t\t\t\t\tservice charge @10%%\t%f",servicecharge);
   printf("\n\t\t\t\t\t\t\t\t---------------------------------------\n");
  printf("\n\t\t\t\t\t\t\t\tGrand total\t\t%f",grandtotal);
   printf("\n\t\t\t\t\t\t\t\t---------------------------------------\n");
}
//this function does the arithmetic calculation part and generates the actual grand total after the calculation

void genfoot()
{
  printf("\n\t\t\t\t\t\t\t\t\t\tThank you");
   printf("\n\t\t\t\t\t\t\t\t---------------------------------------\n\n\n\n");

}
//this function generates the end of the invoice (displays a thank you message and option for users to save the bill or not)

void genmenu(struct menutemplate menulist[])
{
  printf("\n\n\n\t\t\t\033[46mDate:%s\033[0m\n",__DATE__);
  printf("\n\t\t\t\t\t\t-------------------------------------------------------------\n");
  printf("\n\t\t\t\t\t\t\033[31mFood-list(Press the corresponding number to select the item)\033[0m");
  printf("\n\t\t\t\t\t\t-------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t\t\033[1mSN\t\t\tName\t\tPrice\n\033[0m");
  for(int i=0;i<10;i++)
  {
    printf("\t\t\t\t\t\t\t%d\t\t%12s\t\t%d\n",i+1,menulist[i].name,menulist[i].price);
  }
  printf("\n\t\t\t\t\t\t-------------------------------------------------------------\n");
}
//generates a menu list of the items available in the restaurant with their corresponding prices using the menulist structure var

void gendash(int *choice)
{
  system("cls");
  printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\033[1;31mWelcome to \033[1;94mSaz's Diner\033[1;31m\n");
  printf("\t\t\t\t\t\t\t\t\t----------------------\n");
  printf("\n\t\t\t\t\t\t\t1.Generate invoice\n\t\t\t\t\t\t\t2.Search Invoice\n\t\t\t\t\t\t\t3.Show all Invoices\n\t\t\t\t\t\t\t4.exit");
  printf("\n\n\t\t\t\t\t\t\t\t\t\033[32mEnter your choice:\033[0m");
  scanf("%d",choice);
  fgetc(stdin);//this consumes the newline pressed at the end so that the later fgets doesnt register the newline as the first character

}//generates main dashboard of the invoice system interface
//generates the dashboard initially displayed on the screen

void getorder(struct payable items[],int *ordersize, char customer[])
{
  int itemno;
  printf("\n\n\n\n\n\n\t\t\t\033[46mDate:%s\033[0m",__DATE__);
  printf("\n\t\t\t\t\t\t\t\t\t\033[32mEnter name of customer:\033[0m");
  scanf("%s",customer);
  fgetc(stdin);
  //the guy uses a file i/o function why?
  printf("\t\t\t\t\t\t\t\t\t\033[32mEnter the size of order:\033[0m");
  scanf("%d",ordersize);
  fgetc(stdin);
  system("cls");
  printf("\t\t\t\t\t\t\t\t\t\033[32mEnter the order:\033[0m");
  genmenu(menulist);
  for(int i=0;i<*ordersize;i++)
  {
    strcpy(items[i].date,__DATE__); 
    printf("\n\t\t\t\t\t\t\t\t\t\033[32mEnter the item number:\033[0m");
    scanf("%d",&itemno);
    fgetc(stdin);
    if(itemno<=10)
    {
    strcpy(items[i].item,menulist[itemno-1].name);
    items[i].price=menulist[itemno-1].price;
    printf("\t\t\t\t\t\t\t\t\t\033[32mEnter the quantity:\033[0m");
    scanf("%d",&items[i].qty);
    fgetc(stdin);
    items[i].total=items[i].price*items[i].qty;
    }
    else
    {
      i--;
      printf("\t\t\t\t\t\t\t\t\t\033[91mInvalid input(Enter the order again)\033[0m");
    }
  }
}//This function takes the record of all the orders of the customer along with their name
//takes the input from the bill system operator 

int main()
{

/*
  VAR DECLARATION 
*/
struct payable items[100]; //payable strucutre variable to store the items to be billed

int choice,ordersize,subtotal; //miscellaneous int vars needed during the operation

char customer[100]; //string var for storing the name of the customer

char response; //response var to check if bill is to be saved or not

FILE *fp; //file pointer var used in all file operations

struct filestruct 
{
  // int date;
  char customerfile[100];
  struct payable itemsfile[100];
  int subtotalfile,ordersizefile;
}filestr; //this var is used to hold all the vlaues needed to be stored in the file as the payable struct lacks few of the int vars  

char namecheck[100]; //this var holds the name of the customer to be checked if it exists in the file

int namecheckflag=0; //this flag determines if the required name of customer was found during iteration through the record
/*
VAR DECLARATION ENDS
*/

start: //This label enables operators to continue working without relaunching pgm for each new operation.
gendash(&choice); //Generates initial dashboard scrn

 switch(choice) //calls the required function based on the choice made by the operator
  {
    
    case 1:
      system("cls");
      getorder(items,&ordersize,customer);
      system("cls");
      genhead(items[0].date,customer);
      genbody(items,ordersize,&subtotal);
      genbill(&subtotal);
      genfoot();
      printf("\t\t\t\t\t\t\t\t\033[32mDo you want to save the bill(Y/N)?\n\t\t\t\t\t\t\t\t\t\033[0m");
      scanf("%c",&response);
      fgetc(stdin);
      if(response=='Y'|| response=='y')
      {
        fp=fopen("bill1.txt","a");
        //opens the record file in append mode
        if(fp!=NULL)
        {
          strcpy(filestr.customerfile,customer);
          filestr.subtotalfile=subtotal;
          filestr.ordersizefile=ordersize;
          for(int i=0;i<ordersize;i++)
          {
            filestr.itemsfile[i]=items[i];
          }//how can i copy thedata in items to itemsfile?

         fwrite(&filestr,sizeof(struct filestruct),1,fp);
        
          printf("\n\t\t\t\t\t\t\t\t\033[32mSuccesfully saved");
          fclose(fp);
        }
        else
        {
          printf("\n\t\t\t\t\t\t\t\t\t\033[32merror in locating/opening file");
        }
      }
        else
        {
          printf("\t\t\t\t\t\t\t\t\t\033[32mbill was not saved\033[0m");
        }
       printf("\n\t\t\t\t\t\t\t\t\033[90mPress any key to go to dashboard....\033[0m");
       getch();
       goto start; // redirects program execution back to start of main(), allows operators to continue working without relaunching the pgm.
    break;
    
    
    case 2:
      system("cls");
      printf("\t\t\t\t\t\t\t\t\t\033[32mEnter the name of customer:\033[0m");
      scanf("%s",namecheck);
      fp=fopen("bill1.txt","r");
      if(fp!=NULL)
      {
      while(fread(&filestr,sizeof(struct filestruct) ,1,fp))//reads the strucutures and reinitilizes the file strucutre to values read from file
      {
        if(strcmp(namecheck,filestr.customerfile)==0)
        {
      genhead(filestr.itemsfile[0].date,filestr.customerfile);
      genbody(filestr.itemsfile,filestr.ordersizefile,&filestr.subtotalfile);
      genbill(&filestr.subtotalfile);
      genfoot();
      namecheckflag++;
        }
      }
      if(namecheckflag==0)
      {
        printf("\n\t\t\t\t\t\t\t\t\t\033[31mno valid match found\033[0m");
      }
      fclose(fp);
      }
    else
    {
      printf("\t\t\t\t\t\t\t\t\t\033[31merror in locating/opening file\033[0m");
    }
    printf("\n\t\t\t\t\t\t\t\t\033[90mpress any key to return to dashboard....\033[0m");
    getch();
    goto start;
    break;
    
    case 3:
    system("cls");
    printf("\t\t\t\t\t\t\t\t\t\033[31mAll the other bills are\n:\033[0m");
    fp=fopen("bill1.txt","r");
    if(fp!=NULL)
    {
    while(fread(&filestr,sizeof(struct filestruct) ,1,fp))//reads the strucutures and reinitilizes the file strucutre to values read from file
    {
      genhead(filestr.itemsfile[0].date,filestr.customerfile);
      genbody(filestr.itemsfile,filestr.ordersizefile,&filestr.subtotalfile);
      genbill(&filestr.subtotalfile);
      genfoot();
    }
    fclose(fp);
    
    }
    else
    {
    printf("\t\t\t\t\t\t\t\t\t\033[31merror in locating/opening file\033[0m");
    }
    printf("\\t\t\t\t\t\t\t\t\t\033[90mPress any key to return to dashboard\033[0m");
    getch();
    goto start;
    break;
    
    
    case 4:
       system("cls");
       printf("\t\t\t\t\t\t\t\t\t\033[1;3;31mADIOS :)\033[0m");
       getch();
       exit(0);
    break;
    
    default:
    printf("\t\t\t\t\t\t\t\t\t\033[31minvalid choice\033[0m");
    getch();
    goto start;
    break;
}
return 0;
}