#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

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

int main()
{
    //login();
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
                system("pause");
                system("cls");
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
                printf("\n\n\t\t YOUR PASSWORD HAS BEEN SUCCESSFULLY CHANGED");
                printf("\n\n\t\t ENTER ANY KEY TO CONTINUE");
                getch();
                system("cls");
                break;
            }
            case 7:
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

	if (a <= 0)
	{
        system("cls");
		printf("\n\n\t\tYOU HAVE EXCEEDED THE INPUT LIMIT!!!");
        printf("\n\n\t\t\t PRESS ANY KEY TO EXIT");
		getch();
        exit(0);	
	}
}

void book_appointment()
{

    struct book b;
    FILE *bookf;
    FILE *cusf;
    int total_amount, uinput_sn, temp_sin, i, j, k;
    long long int mobile;
    char fname[15], lname[15];
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
        printf("||                                                                           ||\n");
        if(b.time[1] == 1){
            printf("||  PRESS [2] => 11AM - 12PM                                                 ||\n");
        }
        else{
            printf("||  11AM - 12PM => BOOKED                                                    ||\n");
        }
        printf("||                                                                           ||\n");
        if(b.time[2] == 1){
            printf("||  PRESS [3] => 12PM - 1PM                                                   ||\n");
        }
        else{
            printf("||  12PM - 1PM => BOOKED                                                     ||\n");
        }
        printf("||                                                                           ||\n");
        if(b.time[3] == 1){
            printf("||  PRESS [4] => 1PM - 2PM                                                   ||\n");
        }
        else{
            printf("||  1PM - 2PM => BOOKED                                                      ||\n");
        }
        printf("||                                                                           ||\n");
        if(b.time[4] == 1){
            printf("||  PRESS [5] =>  2PM - 3PM                                                  ||\n");
        }
        else{
            printf("||  2PM - 3PM => BOOKED                                                      ||\n");
        }
        printf("||                                                                           ||\n");
        if(b.time[5] == 1){
            printf("||  PRESS [6] => 3PM - 4PM                                                   ||\n");
        }
        else{
            printf("||  3PM - 4PM => BOOKED                                                      ||\n");
        }
        printf("||                                                                           ||\n");
        if(b.time[6] == 1){
            printf("||  PRESS [7] => 4PM - 5PM                                                   ||\n");
        }
        else{
            printf("|| 4PM - 5PM => BOOKED                                                       ||\n");
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
        printf("\n\n\t\tThe Appointments are full!\nVisit Us After Few Days");
        system("pause");
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
        printf("\t\tDo you want to reserve an appontment? \n\t\tPress [Y/y] => YES \n\t\tPress [N/n] => NO\n");
        printf("||===========================================================================||\n");

        printf("\nEnter Your Choice: ==>");
        scanf("%c", &choice);
        tolower(choice);
        if(choice == 'y'){
            printf("===Fill Details===\n");

            name:
            {
                printf("Enter your name (First Name<space>Last Name):");
                scanf("%s %s", fname, lname);

                for( i = 0; i<strlen(fname); i++){
                    int j = fname[i];
                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92)){
                        continue;
                    }
                    else{
                        printf("First name is invalid! Enter alphabets only!!!\n");
                        goto name;
                    }
                }
                for( i = 0; i<strlen(lname); i++){
                    int j = lname[i];
                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92)){
                        continue;
                    }
                    else{
                        printf("Last name is invalid! Enter alphabets only!!!\n");
                        goto name;
                    }
                }

            }

            number:
            {
                mobile = 0;
                printf("Enter Your Mobile Number:");
                scanf("%lld", &mobile);
                fflush(stdin);

                if(mobile<=9000000000 || mobile>=9999999999){
                    printf("Invalid Mobile Number\n");
                    goto number;
                }
                else{
                    goto appointments;
                }
            }

            appointments:
            {
                printf("Select Schedule Number==> ");
                scanf("%d", &uinput_sn);
                temp_sin = uinput_sn;

                if(uinput_sn > 0 && uinput_sn < 8){
                    for(i = 0; i < 7; i++){
                        if(uinput_sn == i+1){
                            if(b.time[i] == 1){
                                b.time[i]--;
                                break;
                            }
                            else{
                                printf("Already Booked\n");
                                goto appointments;
                            }
                        }
                    }
                }
                else{
                    printf("Invalid Input\n");
                    goto appointments;
                }
            }

            booking:
            {
                total_amount = b.price;
                printf("\nAppointment Reserved Successfully");
                printf("\n**BILL**");
                printf("\nName: %s %s", fname, lname);
                printf("\nMobile Number: %lld", mobile);
                printf("\nService Name: %s", b.service);
                if(temp_sin == 1){
                    printf("\nScheduled at 10AM - 11AM");
                }
                else if(temp_sin == 2){
                    printf("\nScheduled at 11AM - 12PM");
                }
                else if(temp_sin == 3){
                    printf("\nScheduled at 12AM - 1PM");
                }
                else if(temp_sin == 4){
                    printf("\nScheduled at 1PM - 2PM");
                }
                else if(temp_sin == 5){
                    printf("\nScheduled at 2PM - 3PM");
                }
                else if(temp_sin == 6){
                    printf("\nScheduled at 3PM - 4PM");
                }
                else if(temp_sin == 7){
                    printf("\nScheduled at 4PM - 5PM");
                }
                printf("\nTotal Amount: %d", total_amount);

                cusf = fopen("customerinfo.txt","a");

                if(cusf == NULL){
                    printf("File Not Found!");
                }
                else{
                    fprintf(cusf,"%s %s %lld %s %d %d \n",fname, lname, mobile, b.service, temp_sin, total_amount);
                }
                printf("\n");
                fclose(cusf);

                bookf = fopen("data.txt","w");
                fprintf(bookf,"%s %d",b.service, b.price);
                for (i =0; i < 7; i++){
                    if(temp_sin == j-1){
                        fprintf(bookf,"\n%d",b.time[i]);
                        continue;
                    }
                    else{
                        fprintf(bookf,"\n%d",b.time[i]);
                    }
                }
                fclose(bookf);
            }
        }
        else if(choice == 'n'){
            printf("No Problem! Visit Us After Few Days");
            return;
        }
        else{
            printf("Wrong choice!!!\n");
            goto choose;
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