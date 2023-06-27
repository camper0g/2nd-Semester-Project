#include "headers.h"

void book_appointment()
{

    struct book b;
    struct customerinfo c;
    char choice;
    int ch;

    system("cls");
    printf("||===========================================================================||\n");
    printf("||***************************** SERVICE AVAILABLE ***************************||\n");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    bookf = fopen("service1.txt", "r");
    if(bookf == NULL)
    {
        printf("||                         NO SERVICE RECORDS FOUND!                        ||\n");
        printf("\n");
    }
    else{
        fscanf(bookf,"%s %d", b.service, &b.price);
    }
    printf("||  PRESS [1] => %s \n\t\t PRICE -> RS.%d\n", b.service, b.price);
    printf("\n");
    fclose(bookf);

    bookf = fopen("service2.txt", "r");
    if(bookf == NULL)
    {
        printf("||                         NO SERVICE RECORDS FOUND!                        ||\n");
        printf("\n");
    }
    else{
        fscanf(bookf,"%s %d", b.service, &b.price);
    }
    printf("||  PRESS [2] => %s \n\t\t PRICE -> RS.%d\n", b.service, b.price);
    printf("\n");
    fclose(bookf);

    bookf = fopen("service3.txt", "r");
    if(bookf == NULL)
    {
        printf("||                         NO SERVICE RECORDS FOUND!                        ||\n");
        printf("\n");
    }
    else{
        fscanf(bookf,"%s %d", b.service, &b.price);
    }
    printf("||  PRESS [3] => %s \n\t\t PRICE -> RS.%d\n", b.service, b.price);
    printf("\n");
    fclose(bookf);

    printf("||  PRESS [4] => RETURN BACK\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    choice:
    {
        printf("||  ENTER YOUR CHOICE => ");
        scanf("%d",&ch);
        fflush(stdin);
    }


    if(ch == 1){
        bookf = fopen("service1.txt", "r");
    }
    else if(ch == 2){
        bookf = fopen("service2.txt", "r");
    }
    else if(ch == 3){
        bookf = fopen("service3.txt", "r");
    }
    else if(ch == 4){
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                          NO PROBLEM! VISIT US AGAIN                       ||\n");
        printf("||             YOU'LL BE RETURNED BACK TO MAIN MENU IN A FEW SECONDS         ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        Sleep(2000);
        system("cls");
        return;
    }
    else{
        printf("** IVALID OPTION \n");
        goto choice;
    }
    if(bookf == NULL)
    {
        printf("||                         NO SERVICE RECORDS FOUND!                        ||\n");
        printf("\n");
        Sleep(750);
        book_appointment();
    }    
    else
    {
        system("cls");
        fscanf(bookf,"%s %d", b.service, &b.price);
        for( i = 0; i < 7; i++){
            fscanf(bookf,"\n%d",&b.time[i]);
        }
        fclose(bookf);
        printf("||===========================================================================||\n");
        printf("||**************************** AVAILABLE SCHEDULES **************************||\n");
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
            printf("||  04PM - 05PM => BOOKED                                                    ||\n");
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
        if(ch == 1){
            bookf = fopen("service1.txt","r");
        }
        else if(ch == 2){
            bookf = fopen("service2.txt","r");
        }
        else{
            bookf = fopen("service3.txt","r");
        }
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
                                b.time[i] = 0;
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
                b.sn = ch;

                cusf = fopen("customerinfo.txt","r");
                if(cusf == NULL){
                    c.tid = 0;
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
                    printf("||  Scheduled at  ==> 10AM - 11AM\n");
                }
                else if(c.sn == 2){
                    printf("||  Scheduled at  ==> 11AM - 12PM\n");
                }
                else if(c.sn == 3){
                    printf("||  Scheduled at  ==> 12AM - 1PM\n");
                }
                else if(c.sn == 4){
                    printf("||  Scheduled at  ==> 1PM - 2PM\n");
                }
                else if(c.sn == 5){
                    printf("||  Scheduled at  ==> 2PM - 3PM\n");
                }
                else if(c.sn == 6){
                    printf("||  Scheduled at  ==> 3PM - 4PM\n");
                }
                else if(c.sn == 7){
                    printf("||  Scheduled at  ==> 4PM - 5PM\n");
                }
                printf("||  Total Amount  ==> %d\n", c.total);

                printf("||===========================================================================||\n");
                cusf = fopen("customerinfo.txt","a");

                if(cusf == NULL){
                    printf("File Not Found!\n");
                }
                else{
                    fprintf(cusf,"%s %s %lld %d %s %d %d %d\n", c.fname, c.lname, c.mobile, b.sn, b.service, c.sn, c.total, c.tid);
                }
                fclose(cusf);

                if(ch == 1){
                    bookf = fopen("service1.txt","w");
                }
                else if(ch == 2){
                    bookf = fopen("service2.txt","w");
                }
                else{
                    bookf = fopen("service3.txt","w");
                }
                fprintf(bookf,"%s %d",b.service, b.price);
                for (i =0; i < 7; i++){
                    fprintf(bookf,"\n%d",b.time[i]);
                }
                fclose(bookf);

                printf("||  PRESS ANY KEY TO CONTINUE");
                getch();
                system("cls");
            }
        }
        else if(choice == 'n'){
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                          NO PROBLEM! VISIT US AGAIN                       ||\n");
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
            book_appointment();
        }
    }
}

void cancel_appointment() 
{
    
    system("cls");
    
    struct book b;
    struct customerinfo c;

    int tid;
    long long int mobile;
    char choice;

    printf("||===========================================================================||\n");
    printf("||**************************** CANCEL APPOINTMENT ***************************||\n");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||      DO YOU WANT TO CANCEL AN APPOINTMENT?                                ||\n");
    printf("||      Press [Y/y] => YES                                                   ||\n");
    printf("||      Press [N/n] => NO                                                    ||\n");
    printf("||===========================================================================||\n");

    printf("||      Enter Your Choice ==> ");
    scanf("%c", &choice);
    fflush(stdin);

    tolower(choice);
    if(choice == 'y'){
        printf("||============================= Fill Details ================================||\n");

        printf("||  Enter Your Ticket ID ==> ");
        scanf("%d", &tid);

        i = 0;
        mobile:{
            if( i < 3){
                printf("||  Enter Your Mobile Number For Verification ==> ");
                scanf("%lldd", &mobile);
                i++;
            }
            else{
                system("cls");
                printf("||===========================================================================||\n");
                printf("||                                                                           ||\n");
                printf("||                           TOO MANY ATTEMPTS!!!                            ||\n");
                printf("||                                                                           ||\n");
                printf("||===========================================================================||\n");
                printf("||                        RETURNING BACK TO MAIN MENU IN FEW SECONDS");
                Sleep(1500);
                system("cls");
                return;
            }
        }

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

            while(fscanf(cusf,"%s %s %lld %d %s %d %d %d\n", c.fname, c.lname, &c.mobile, &b.sn, b.service, &c.sn, &c.total, &c.tid) != EOF){
                if(tid == c.tid){
                    if(mobile == c.mobile){
                        break;
                    }
                    else{
                        printf("**  MOBILE NUMBER VERIFICATION FAILED\n");
                        goto mobile;
                    }
                }
            }
            if(tid != c.tid){
                printf("**  ENTER VALID TICKET ID\n");
                cancel_appointment();
            }
            fclose(cusf);
            
            if(b.sn == 1){
                bookf = fopen("service1.txt","r");
            }
            if(b.sn == 2){
                bookf = fopen("service2.txt","r");
            }
            else{
                bookf = fopen("service3.txt","r");
            }
            if(bookf == NULL)
            {
                system("cls");
                printf("||===========================================================================||\n");
                printf("||                                                                           ||\n");
                printf("||                         NO SERVICES RECORDS FOUND!                        ||\n");
                printf("||                                                                           ||\n");
                printf("||===========================================================================||\n");
                printf("                       PRESS ANY KEY TO RETURN TO MAIN MENU");
                getch();
                system("cls");
                return;
            }
            fscanf(bookf,"%s %d", b.service, &b.price);
            for( i = 0; i < 7; i++){
                fscanf(bookf,"\n%d",&b.time[i]);
            }
            fclose(bookf);
            
            if(b.sn == 1){
                bookf = fopen("service1.txt","w");
            }
            if(b.sn == 2){
                bookf = fopen("service2.txt","w");
            }
            else{
                bookf = fopen("service3.txt","w");
            }
            fprintf(bookf,"%s %d",b.service, b.price);
            for (i =0; i < 7; i++){
                if(c.sn == i+1){
                    if(b.time[i] == 0){
                        b.time[i] = 1;
                        fprintf(bookf,"\n%d", b.time[i]);
                    }
                }
                else{
                    fprintf(bookf,"\n%d",b.time[i]);
                }
            }
            fclose(bookf);
        }

        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                    APPOINTMENT CANCELLED SUCCESSFULLY                     ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("                       PRESS ANY KEY TO CONTINUE");
        getch();
        system("cls");
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
        cancel_appointment();
    }
}

void edit_appointment(){}
