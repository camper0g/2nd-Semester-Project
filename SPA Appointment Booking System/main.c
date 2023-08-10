#include "./includes/headers.h"
#include "./includes/declaration.h"
#include "./includes/login.h"
#include "./includes/user.h"
#include "./includes/admin.h"

void rlogin();
void alogin();
void rmenu();
void amenu();
void book_appointment();
void cancel_appointment();
void edit_appointment();
void view_transactions();
void delete_transactions();
void edit_services();
void change_password();

int main(){
    system("mkdir Appdata");
    int choice;
    system("cls");
    printf("||===========================================================================||\n");
    printf("||************************* SELECT USER TYPE ********************************||\n");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||  PRESS [1] => REGULAR USER                                                ||\n");
    printf("||  PRESS [2] => ADMINISTRATOR                                               ||\n");
    printf("||  PRESS [3] => EXIT                                                        ||\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    choice:{
        printf("|| SELECT USER TYPE => ");
        scanf("%d", &choice);
        fflush(stdin);
    }
    if( choice == 1){
        rmenu();
    }
    else if( choice == 2){
        amenu();
    }
    else if(choice == 3){
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                     THANK YOU FOR USING THE SYSTEM                        ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("                       ENTER ANY KEY TO EXIT");
        getch();
        exit(0);
    }
    else{
        printf("** IVALID OPTION \n");
        goto choice;
    }
    getch();
    return 0;
}


void rmenu(){
    rlogin();
    system("cls");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||                              LOGIN SUCCESSFUL                             ||\n");
    printf("||                           WELCOME TO THE SYSTEM                           ||\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    printf("                             LOADING MAIN MENU");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    system("cls");
    int choice;
    while(1)
    {
        printf("||===========================================================================||\n");
        printf("||********************** SPA APPOINTMENT BOOKING SYSTEM *********************||\n");
        printf("||---------------------------------------------------------------------------||\n");
        printf("||****************************** USER PANEL *********************************||\n");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [1] => BOOK APPOINTMENT                                            ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [2] => CANCEL APPOINTMENT                                          ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [3] => SHIFT SCHEDULE                                              ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [4] => SIGN OUT                                                    ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("||ENTER YOUR CHOICE => ");
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
                edit_appointment();
                break;
            }
            case 4:
            {
                system("cls");
                printf("||===========================================================================||\n");
                printf("||                                                                           ||\n");
                printf("||                                SIGNING OUT                                ||\n");
                printf("||                                                                           ||\n");
                printf("||===========================================================================||\n");
                Sleep(1500);
                main();
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

void amenu(){
    alogin();
    system("cls");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||                              LOGIN SUCCESSFUL                             ||\n");
    printf("||                           WELCOME TO THE SYSTEM                           ||\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    printf("                             LOADING MAIN MENU");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    system("cls");
    int choice;
    while(1)
    {
        printf("||===========================================================================||\n");
        printf("||********************** SPA APPOINTMENT BOOKING SYSTEM *********************||\n");
        printf("||---------------------------------------------------------------------------||\n");
        printf("||************************** ADMINISTRATOR PANEL ****************************||\n");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [1] => VIEW TRANSACTIONS                                           ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [2] => DELETE TRANSACTIONS                                         ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [3] => ADD/ UPDATE SERVICES                                        ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [4] => CHANGE LOGIN INFORMATION                                    ||\n");
        printf("||                                                                           ||\n");
        printf("||  PRESS [5] => SIGN OUT                                                    ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("||ENTER YOUR CHOICE => ");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice)
        {
            case 1:
            {
                view_transactions();
                break;
            }
            case 2:
            {
                delete_transactions();
                break;
            }
            case 3:
            {
                edit_services();
                break;
            }
            case 4:
            {
                change_password();
                break;
            }
            case 5:
            {
                system("cls");
                printf("||===========================================================================||\n");
                printf("||                                                                           ||\n");
                printf("||                                SIGNING OUT                                ||\n");
                printf("||                                                                           ||\n");
                printf("||===========================================================================||\n");
                Sleep(1500);
                main();
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