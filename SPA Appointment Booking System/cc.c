#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void login();
void book_appointment();
void cancel_appointment();
void view_transactions();
void delete_transactions();
void edit_price();
void change_password();

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
    login();
    system("cls");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||                              LOGIN SUCCESSFUL                             ||\n");
    printf("||                           WELCOME TO OUR SYSTEM                           ||\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    printf("                             LOADING MAIN MENU");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
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

void login()
{
	int a=4,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    do
    {   
        printf("||=======================  LOGIN INFO  =======================||\n");
        printf("||  ENTER USERNAME => ");
        scanf("%s", &uname); 
        printf("||  ENTER PASSWORD => ");
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
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                         NO LOGIN RECORDS FOUND!                           ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("                       PRESS ANY KEY TO EXIT");
        getch();
        system("cls");
        exit(1);
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
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                         WRONG USERNAME/PASSWORD                           ||\n");
            a--;
            printf("||                         YOU HAVE %d TRIES LEFT!                            ||\n",a);
            printf("||===========================================================================||\n");
            Sleep(1500);
            system("cls");
        }
    }while(a>=1);

	if (a <= 0)
	{
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                     YOU HAVE EXCEEED THE INPUT LIMIT!                     ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("                             ENTER ANY KEY TO EXIT");
        getch();
        system("cls");
        exit(1);	
	}
}

void book_appointment()
{

    struct book b;
    struct customerinfo c;
    FILE *bookf;
    FILE *cusf;
    int i, j, k;
    char choice;

    bookf = fopen("data.txt", "r");

    if(bookf == NULL)
    {
        printf("File not found!\n");
        return;
    }

    else
    {
        system("cls");

        bookf = fopen("data.txt","r");
        fscanf(bookf,"%s %d", b.service, &b.price);
        for( i = 0; i < 7; i++){
            fscanf(bookf,"\n%d",&b.time[i]);
        }
        fclose(bookf);
        printf("||===========================================================================||\n");
        printf("||***************************** SERVICE AVAILABLE ***************************||\n");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||  AVAILABLE SERVICE => %s\n", b.service);
        printf("||                                                                           ||\n");
        printf("||  SERIVE PRICE => %d\n", b.price);
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("||**************************** AVAILABLE SCHEDULES *************************||\n");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        if(b.time[0] == 1){
            printf("||  PRESS [1] => 10AM - 11PM                                                 ||\n");
        }
        else{
            printf("||  10AM - 11PM => BOOKED                                                    ||\n");
        }
        if(b.time[1] == 1){
            printf("||  PRESS [2] => 11AM - 12PM                                                 ||\n");
        }
        else{
            printf("||  11AM - 12PM => BOOKED                                                    ||\n");
        }
        if(b.time[2] == 1){
            printf("||  PRESS [3] => 12PM - 01PM                                                 ||\n");
        }
        else{
            printf("||  12PM - 01PM => BOOKED                                                    ||\n");
        }
        if(b.time[3] == 1){
            printf("||  PRESS [4] => 01PM - 02PM                                                 ||\n");
        }
        else{
            printf("||  01PM - 02PM => BOOKED                                                    ||\n");
        }
        if(b.time[4] == 1){
            printf("||  PRESS [5] => 02PM - 03PM                                                 ||\n");
        }
        else{
            printf("||  02PM - 03PM => BOOKED                                                    ||\n");
        }
        if(b.time[5] == 1){
            printf("||  PRESS [6] => 03PM - 04PM                                                 ||\n");
        }
        else{
            printf("||  03PM - 04PM => BOOKED                                                    ||\n");
        }
        if(b.time[6] == 1){
            printf("||  PRESS [7] => 04PM - 05PM                                                 ||\n");
        }
        else{
            printf("|| 04PM - 05PM => BOOKED                                                     ||\n");
        }
    }
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");

    k=0;
    for(i = 0; i < 7; i++){
        if(b.time[i] == 1){
            k = 1;
            break;
        }
    }

    if(k != 1){
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                         The Appointments are full!                        ||\n");
        printf("||                           Visit Us After Few Days                         ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("                       PRESS ANY KEY TO RETURN TO MAIN MENU");
        getch();
        system("cls");
        return;
    }
    else

    goto choose;

    choose:
    {
        bookf = fopen("data.txt","r");
        fscanf(bookf,"%s %d", b.service, &b.price);
        for( i = 0; i < 7; i++){
            fscanf(bookf,"\n%d",&b.time[i]);
        }
        fclose(bookf);
        printf("||      DO YOU WANT TO RESERVE AN APPOINTMENT?                               ||\n");
        printf("||      Press [Y/y] => YES                                                   ||\n");
        printf("||      Press [N/n] => NO                                                    ||\n");
        printf("||===========================================================================||\n");

        printf("||      Enter Your Choice ==> ");
        scanf("%c", &choice);
        fflush(stdin);
        tolower(choice);
        if(choice == 'y'){
            printf("||============================= Fill Details ================================||\n");

            name:
            {
                printf("||  Enter your name (First Name<space>Last Name) ==> ");
                scanf("%s %s", c.fname, c.lname);

                for( i = 0; i<strlen(c.fname); i++){
                    int j = c.fname[i];
                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92)){
                        continue;
                    }
                    else{
                        printf("\n**  INVALID FIRST NAME\n");
                        goto name;
                    }
                }
                for( i = 0; i<strlen(c.lname); i++){
                    int j = c.lname[i];
                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92)){
                        continue;
                    }
                    else{
                        printf("\n**  INVALID LAST NAME\n");
                        goto name;
                    }
                }

            }

            number:
            {
                c.mobile = 0;
                printf("||  Enter Your Mobile Number ==> ");
                scanf("%lld", &c.mobile);
                fflush(stdin);

                if(c.mobile<=9000000000 || c.mobile>=9999999999){
                    printf("**  INVALID MOBILE NUMBER\n");
                    goto number;
                }
                else{
                    goto appointments;
                }
            }

            appointments:
            {
                printf("||  Select Schedule Number ==> ");
                scanf("%d", &c.sn);

                if(c.sn > 0 && c.sn < 8){
                    for(i = 0; i < 7; i++){
                        if(c.sn == i+1){
                            if(b.time[i] == 1){
                                b.time[i]--;
                                break;
                            }
                            else{
                                printf("**  BOOKED ALREADY\n");
                                goto appointments;
                            }
                        }
                    }
                }
                else{
                    printf("**  INVALID INPUT\n");
                    goto appointments;
                }
            }

            booking:
            {
                c.total = b.price + c.total;

                cusf = fopen("customerinfo.txt","r");
                if(cusf == NULL){
                    printf("Error Opening File\n");
                }
                else{
                    fseek(cusf, -3, SEEK_END);
                    fscanf(cusf, "%d", &c.tid);
                }

                fclose(cusf);

                c.tid = c.tid + 1;
                system("cls");
                printf("||===========================================================================||\n");
                printf("||****************** Appointment Reserved Successfully **********************||\n");
                printf("||===========================================================================||\n");
                printf("||******************************* BILL **************************************||\n");
                printf("||===========================================================================||\n");
                printf("||  Tikcet ID     ==> %d\n", c.tid);
                printf("||  Name          ==> %s %s\n", c.fname, c.lname);
                printf("||  Mobile Number ==> %lld\n", c.mobile);
                printf("||  Service Name  ==> %s\n", b.service);
                if(c.sn == 1){
                    printf("||  Scheduled at 10AM - 11AM\n");
                }
                else if(c.sn == 2){
                    printf("||  Scheduled at 11AM - 12PM\n");
                }
                else if(c.sn == 3){
                    printf("||  Scheduled at 12AM - 1PM\n");
                }
                else if(c.sn == 4){
                    printf("||  Scheduled at 1PM - 2PM\n");
                }
                else if(c.sn == 5){
                    printf("||  Scheduled at 2PM - 3PM\n");
                }
                else if(c.sn == 6){
                    printf("||  Scheduled at 3PM - 4PM\n");
                }
                else if(c.sn == 7){
                    printf("||  Scheduled at 4PM - 5PM\n");
                }
                printf("||  Total Amount: %d\n", c.total);

                printf("||===========================================================================||\n");
                system("cls");

                cusf = fopen("customerinfo.txt","a");

                if(cusf == NULL){
                    printf("File Not Found!\n");
                }
                else{
                    fprintf(cusf,"%s %s %lld %s %d %d %d\n", c.fname, c.lname, c.mobile, b.service, c.sn, c.total, c.tid);
                }
                fclose(cusf);

                bookf = fopen("data.txt","w");
                fprintf(bookf,"%s %d",b.service, b.price);
                for (i =0; i < 7; i++){
                    fprintf(bookf,"\n%d",b.time[i]);
                }
                fclose(bookf);

                printf("||  PRESS ANY KEY TO CONTINUE");
                getch();
            }
        }
        else if(choice == 'n'){
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                          NO PROBLEM! VISIT US AGAIN                       ||\n");
            printf("||              YOU'LL BE RETURNED BACK TO MAIN MENU IN 3 SECONDS            ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            Sleep(3000);
            system("cls");
            return;
        }
        else{
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                              ENTER VALID INPUT                            ||\n");
            printf("||                 PLEASE RE-CONSIDER YOUR INPUT IN 3 SECONDS                ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            Sleep(3000);
            system("cls");
            book_appointment();
        }
    }
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
    printf("||=====================  ENTER CURRENT  ======================||\n");
    login();
    system("cls");
    int i = 0;
    char pword[10], uname[10], c= ' ';
    printf("||===================== UPDATE LOGIN INFO  ====================||\n");
    printf("||  NEW USERNAME => ");
    scanf("%s", &uname); 
    printf("||  NEW PASSWORD => ");
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
    FILE *file = fopen("login", "wb");
    if (file == NULL) 
    {
        printf("\n\n\t\tERROR OPENING FILE.\n");
        system("pause");
    }
    fprintf(file, "%s %s",uname ,pword);
    fclose(file);

    system("cls");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||                     LOGIN INFO UPDATED SUCCESSFULLY                       ||\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    printf("                       ENTER ANY KEY TO CONTINUE");
    getch();
    system("cls");
}