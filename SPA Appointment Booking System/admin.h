#include "headers.h"

void view_transactions(){

    system("cls");
    char sn[50];
    struct customerinfo c;
    struct book b;
    cusf = fopen("customerinfo.txt", "r");

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

        printf("||==============================================================================================||\n");
        printf("||********************************** LIST OF BOOKINGS RECORDED *********************************||\n");
        printf("||==============================================================================================||\n");
        printf("||                                                                                              ||\n");
        printf("||  TICKET ID\tNAME \t\tMOBILE NUMBER\tSERVICE \tSCHEDULE APPOINTED\tAMOUNT  ||\n");
        printf("||                                                                                              ||\n");
        while(fscanf(cusf,"%s %s %lld %s %d %d %d\n",c.fname, c.lname, &c.mobile, b.service, &c.sn, &c.total, &c.tid) != EOF){
            if (c.sn == 1) {
                strcpy(sn, "10AM - 11AM");
            } else if (c.sn == 2) {
                strcpy(sn, "11AM - 12PM");
            } else if (c.sn == 3) {
                strcpy(sn, "12PM - 01PM");
            } else if (c.sn == 4) {
                strcpy(sn, "01PM - 02PM");
            } else if (c.sn == 5) {
                strcpy(sn, "02PM - 03PM");
            } else if (c.sn == 6) {
                strcpy(sn, "03PM - 04PM");
            } else {
                strcpy(sn, "04PM - 05PM");
            }
            printf("||  %d\t\t%s %s\t%lld\t%s  %s\t\t%d    \n",c.tid, c.fname, c.lname, c.mobile, b.service, sn, c.total);
        }
        fclose(cusf);
        printf("||                                                                                              ||\n");
        printf("||==============================================================================================||\n");
        printf("||                             ENTER ANY KEY TO RETURN TO MAIN MENU");
        getch();
        system("cls");
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
        bookf = fopen("data.txt", "r+");

        if(cusf == NULL && bookf == NULL)
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

            struct book b;
            char ch;

            while((ch = fgetc(bookf)) != EOF){
                fscanf(bookf, "%s %d\n", b.service, &b.price);
                fprintf(bookf, "%s %d\n", b.service, b.price);
                for (i = 0; i < 7; i++){
                    b.time[i] = 1;
                    fprintf(bookf, "%d\n", b.time[i]);
                }
            }
        }
        fclose(bookf);
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

void edit_services()
{
    system("pause");
    system("cls");
}
