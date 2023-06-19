#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void login(){};
void book_appointment(){};
void cancel_appointment(){};
void view_transactions(){};
void delete_transactions();
void edit_price(){};
void change_password(){};

FILE *bookf;
FILE *cusf;
int i, j, k;
struct book{
    char service[50];
    int price;
    int time[7];
};

struct customerinfo{
    char fname[25];
    char lname[25];
    long long int mobile;
    int total;
    int sn;
    int tid;
};

int main()
{
    system("cls");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||                              LOGIN SUCCESSFUL                             ||\n");
    printf("||                           WELCOME TO OUR SYSTEM                           ||\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    printf("                             LOADING MAIN MENU");
    // Sleep(500);
    // printf(".");
    // Sleep(500);
    // printf(".");
    // Sleep(500);
    // printf(".");
    // Sleep(500);
    system("cls");
    int choice;
    while(1)
    {
        printf("||===========================================================================||\n");
        printf("||********************** SPA APPOINTMENT BOOKING SYSTEM *********************||\n");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [1] => Book Appointment                                            ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [2] => Cancel Appointment                                          ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [3] => View Transaction                                            ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [4] => Delete Transactions                                         ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [5] => Edit Price Of Services                                      ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [6] => Change Password                                             ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [7] => Exit                                                        ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("||Enter Your choice: ");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice)
        {
            case 1:
            {
                book_appointment();
                break;
            }
            case 2:
            {
                cancel_appointment();
                break;
            }
            case 3:
            {
                view_transactions();
                break;
            }
            case 4:
            {
                delete_transactions();
                break;
            }
            case 5:
            {
                edit_price();
                break;
            }
            case 6:
            {
                change_password();
                break;
            }
            case 7:
            {
                system("cls");
                printf("||===========================================================================||\n");
                printf("||                                                                           ||\n");
                printf("||                     THANK YOU FOR USING OUR SYSTEM                        ||\n");
                printf("||                                                                           ||\n");
                printf("||===========================================================================||\n");
                printf("                       ENTER ANY KEY TO EXIT");
                getch();
                return 0;
            }
            default:
            {
                system("cls");
                printf("||===========================================================================||\n");
                printf("||                                                                           ||\n");
                printf("||                      RE-CONSIDER YOUR CHOICE                              ||\n");
                printf("||                                                                           ||\n");
                printf("||===========================================================================||\n");
                printf("                       ENTER ANY KEY TO CONTINUE");
                getch();
                system("cls");
                break;
            }
        }
    }
}

void delete_transactions()
{
    system("cls");
    char choice;
    printf("||===========================================================================||\n");
    printf("||******************** DELETE ALL APPOINTMENT RECORDS ***********************||\n");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||      DO YOU WANT TO DELETE ALL APPOINTMENT RECORDS?                       ||\n");
    printf("||      Press [Y/y] => YES                                                   ||\n");
    printf("||      Press [N/n] => NO                                                    ||\n");
    printf("||===========================================================================||\n");

    printf("||      Enter Your Choice ==> ");
    scanf("%c", &choice);
    fflush(stdin);
    tolower(choice);

    if(choice == 'y'){
        cusf = fopen("customerinfo.txt", "w");

        if(cusf == NULL)
        {
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                         NO CUSTOMERS RECORDS FOUND!                       ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            printf("                       PRESS ANY KEY TO RETURN TO MAIN MENU");
            getch();
            system("cls");
            return;
        }
        else{
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                         RECORDS CLEARED SUCCESSFULLY                      ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            printf("                       PRESS ANY KEY TO RETURN TO MAIN MENU");
            getch();
            system("cls");
        }
        fclose(cusf);
    }

    else if(choice == 'n'){
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                                 NO PROBLEM!                               ||\n");
        printf("||             YOU'LL BE RETURNED BACK TO MAIN MENU IN A FEW SECONDS         ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        Sleep(2000);
        system("cls");
        return;
    }
        else{
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                              ENTER VALID INPUT                            ||\n");
        printf("||                PLEASE RE-CONSIDER YOUR INPUT IN A FEW SECONDS             ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        Sleep(1500);
        system("cls");
        delete_transactions();
    }
    system("cls");
}
