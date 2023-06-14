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

struct customer_info{
    char name[50];
    long long int number;
    int time;
    int id;
}cs[300];

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
        printf("||===========================================================================||\n");
        printf("||********************** SPA APPOINTMENT BOOKING SYSTEM *********************||\n");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [1] => View Appointment                                            ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [2] => Book Appointment                                            ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [3] => Cancel Appointment                                          ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [4] => View Transaction                                            ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [5] => Delete Transactions                                         ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [6] => Edit Price Of Services                                      ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [7] => Change Password                                             ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [8] => Exit                                                        ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("||Enter Your choice: ");
        scanf("%d",&choice);
        fflush(stdin);

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
        while(i<10)
        {
            pword[i]=getch();                       
            c=pword[i];                 
            if(c == 13)              
            {
                break;                                          
            }
            else
            {
                printf("*");                        
            }
            i++;                      
        }
        pword[i]='\0';                        
        i=0;                                      

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

	if (a <= 0)
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
    // system("pause");
    // system("cls");
    printf("Services available: ");
    printf("HotStone Massage \t Price:");


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