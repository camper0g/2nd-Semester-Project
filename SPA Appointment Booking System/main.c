#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void login();
void view_appointment();
void book_appointment();
void cancel_appointment();
void view_transactions();
void delete_transactions();
void edit_price();
void change_password();
int main()
{
    login();
    system("cls");
    printf("\n\n\t\t\t   LOGIN SUCCESSFUL\n\n\t\t\tWELCOME TO OUR SYSTEM\n\n");
    printf("\t\t\t");
    system("pause");
    system("cls");
    int choice;
    while(1)
    {
        printf("1. View Appointment\n");
        printf("2. Book Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. View Transaction\n");
        printf("5. Delete Transactions\n");
        printf("6. Edit Price Of Services\n");
        printf("7. Change Password\n");
        printf("8. Exit\n");
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
                change_password();
                printf("\n\n\t\t YOUR PASSWORD HAS BEEN SUCCESSFULLY CHANGED");
                printf("\n\n\t\t ENTER ANY KEY TO CONTINUE");
                getch();
                system("cls");
                break;
            }
            case 8:
            {
                system("cls");
                printf("\n\n\t\t THANK YOU FOR USING OUR SYSTEM");
                printf("\n\n\t\t ENTER ANY KEY TO EXIT");
                getch();
                return 0;
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
	int a=4,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    do
    {   
        printf("\n=========================  LOGIN INFO  =========================");
        printf("\n\t\t\tENTER USERNAME:-");
        scanf("%s", &uname); 
        printf("\t\t\tENTER PASSWORD:-");
        while(i<10)                                  //loop to get the password for every address in the array
        {
            pword[i]=getch();                        //get the password
            c=pword[i];                              //stores the input in c to check if the user has entred enter key or not
            if(c == 13)                              // ascii 13 is for carrige return, checks if the user has pressed enter key
            {
                break;                                          
            }
            else
            {
                printf("*");                         //prints astrick in every input character
            }
            i++;                                     //increases the value of i
        }
        pword[i]='\0';                               //This line adds a null terminator ('\0') at the end of the pword array to mark the end of the password string.
        i=0;                                         //This line resets the value of i to 0 to reuse it for further input tries.

        // Open the file in read mode (in binary mode)
        FILE *file = fopen("login", "rb");

        if (file == NULL) 
        {
            printf("\n\n\t\tERROR OPENING FILE.\n");
            system("pause");
            system("cls");
        }

        // Read username and password from the file
        char fileUsername[10];
        char filePassword[10];
        fscanf(file, "%s %s", fileUsername, filePassword);

        // Close the file
        fclose(file);

        if(strcmp(uname,fileUsername)==0 && strcmp(pword,filePassword)==0)
        {
            break;
        }
        else
        {
            system("cls");
            printf("\n\n\t\t\tWRONG USERNAME/PASSWORD");
            a--;                                  // variable for number of tries 
            printf("\n\n\t\t\tYOU HAVE %d TRIES LEFT\n\n",a);
            printf("\t\t\t");
            system("pause");
            system("cls");                        //clears the screen for every tries
        }
    }while(a>=1);

	if (a <= 1)
	{
        system("cls");
		printf("\n\n\t\tYOU HAVE EXCEEDED THE INPUT LIMIT!!!");
        printf("\n\n\t\t\t PRESS ANY KEY TO EXIT");
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

void change_password()
{
    system("cls");
    printf("\n=======================  ENTER CURRENT  ========================");
    login();
    system("cls");
    int i = 0;
    char pword[10], uname[10], c= ' ';
    FILE *file = fopen("login", "wb");
    if (file == NULL) 
    {
        printf("\n\n\t\tERROR OPENING FILE.\n");
        system("pause");
    }
    printf("\n\t\t\tNEW USERNAME:-");
    scanf("%s", &uname);
    printf("\t\t\tNEW PASSWORD:-");
    while(i<10)                            //loop to get the password for every address in the array
    {
        pword[i]=getch();                  //get the password
        c=pword[i];                        //stores the input in c to check if the user has entred enter key or not
        if(c == 13)                        // ascii 13 is for carrige return, checks if the user has pressed enter key
        {
            break;                                          
        }
        else
        {
            printf("*");                    //prints astrick in every input character
        }
        i++;                                //increases the value of i
    }
    pword[i]='\0';
    fprintf(file, "%s %s",uname ,pword);
    fclose(file);
}