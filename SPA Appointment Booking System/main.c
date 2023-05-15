#include <stdio.h>
#include <stdlib.h>
void login();
void view_appointment();
void book_appointment();
void cancel_appointment();
void edit_price();
void change_password();
int pass;
int main()
{
    login();
    int choice;
    while(1)
    {
        printf("1. View Appointment\n");
        printf("2. Book Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Edit Price Of Services\n");
        printf("5. Change Password\n");
        printf("6. Exit\n");
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
                edit_price();
                break;
            }
            case 5:
            {
                change_password();
                break;
            }
            case 6:
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
    /*printf("Enter Password");
    scanf("%d",&pass);*/
}

void view_appointment()
{
    system("pause");
    system("cls");
}

void book_appointment()
{
    system("cls");
}

void cancel_appointment()
{
    system("cls");
}

void edit_price()
{
    system("cls");
}

void change_password()
{
    system("cls");
}
