#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "variables.c"
char username, password, uname, pass;
void login();
void view_appointment();
void book_appointment();
void cancel_appointment();
void view_transactions();
void delete_transactions();
void edit_price();
int main()
{
    login();
    int choice;
    while(1)
    {
        printf("1. View Appointment\n");
        printf("2. Book Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. View Transaction\n");
        printf("5. Delete Transactions\n");
        printf("6. Edit Price Of Services\n");
        printf("7. Exit\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                view_appointment();
                break;
            }
            case 2:
            {
                book_appointment();
                break;
            }
            case 3:
            {
                cancel_appointment();
                break;
            }
            case 4:
            {
                view_transactions();
                break;
            }
            case 5:
            {
                delete_transactions();
                break;
            }
            case 6:
            {
                edit_price();
                break;
            }
            case 7:
            {
                return 0;
                break;
            }
            default:
            {
                printf("Please Enter Valid Choice\n");
                system("cls");
                break;
            }
        }

    }
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
    {
        system("cls");
        
        printf("\n  =========================  LOGIN FORM  =========================  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname); 
        printf(" \n                       ENTER PASSWORD:-");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';
        //char code=pword;
        i=0;
        //scanf("%s",&pword); 
            if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
        {
        printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
        printf("\n\n\n\t\t\t\tPress any key to continue...");
        getch();//holds the screen
        break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
            
            getch();//holds the screen
            
        }
    }while(a<=3);

	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
        exit(0);
		
	}
}


void view_appointment()
{
    system("pause");
    system("cls");
}

void book_appointment()
{
    system("pause");
    system("cls");
}

void cancel_appointment() 
{
    system("pause");
    system("cls");
}

void view_transactions()
{
    system("pause");
    system("cls");
}

void delete_transactions()
{
    system("pause");
    system("cls");
}

void edit_price()
{
    system("pause");
    system("cls");
}
