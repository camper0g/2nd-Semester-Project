#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void login();
void view_appointment();
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
    // system("cls");
    // printf("\n\n\t\t\t   LOGIN SUCCESSFUL\n\n\t\t\tWELCOME TO OUR SYSTEM\n\n");
    // printf("\t\t\t");
    // system("pause");
    // system("cls");
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

void view_appointment()
{
    system("pause");
    system("cls");
}

void book_appointment()
{

    struct book b;
    FILE *bookf;
    FILE *cusf;
    int total_seats, total_amount, uinput_sn, temp_sin, i, j, k;
    long long int mobile;
    char fname[15], lname[15];
    char ch, choice, ch1;

    bookf = fopen("data.txt", "r");

    if(bookf == NULL)
    {
        printf("File not found!\n");
        // return;
    }

    // else if(ch=fgetc(bookf) == EOF)
    // {
    //     printf("\nNo Appointments are available to book right now!\nVisit after few days!\n");
    //     return;
    // }

    else
    {
        system("cls");

        bookf = fopen("data.txt","r");
        fscanf(bookf,"%s %d", b.service, &b.price);
        for( i = 0; i < 7; i++){
            fscanf(bookf,"\n%d",&b.time[i]);
        }
        fclose(bookf);
        printf("||=============================== SERVICE AVAILABLE ================================||\n");
        printf("\n AVAILABLE SERVICE: %s", b.service);
        printf("\n SERIVE PRICE: %d", b.price);
        printf("\n Avaible Scheadules:");
        if(b.time[0] == 1){
            printf("\nPRESS [1] => 10AM - 11PM");
        }
        else{
            printf("\n====BOOKED====");
        }
        if(b.time[1] == 1){
            printf("\nPRESS [2] => 11AM - 12PM");
        }
        else{
            printf("\n====BOOKED====");
        }
        if(b.time[2] == 1){
            printf("\nPRESS [3] => 12PM - 1PM");
        }
        else{
            printf("\n====BOOKED====");
        }
        if(b.time[3] == 1){
            printf("\nPRESS [4] => 1PM - 2PM");
        }
        else{
            printf("\n====BOOKED====");
        }
        if(b.time[4] == 1){
            printf("\nPRESS [5] =>  2PM - 3PM");
        }
        else{
            printf("\n====BOOKED====");
        }
        if(b.time[5] == 1){
            printf("\nPRESS [6] => 3PM - 4PM");
        }
        else{
            printf("\n====BOOKED====");
        }
        if(b.time[6] == 1){
            printf("\nPRESS [7] => 4PM - 5PM");
        }
        else{
            printf("\n====BOOKED====");
        }
    }

    k=0;
    for(i = 0; i < 7; i++){
        if(b.time[i] == 1){
            k = 1;
            break;
        }
    }

    if(k != 1){
        printf("\n The Appointments are full!\nVisit Us After Few Days");
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
        printf("\nDo you want to reserve an appontment? \nPress [Y/y] => YES \nPress [N/n] => NO");
        printf("Enter Your Choice:");
        scanf("%c", &choice);
        tolower(choice);
        if(choice == 'y'){
            printf("\n===Fill Details===");

            name:
            {
                printf("\nEnter your name (First Name<space>Last Name):");
                scanf("%s %s", fname, lname);

                for( i = 0; i<strlen(fname); i++){
                    int j = fname[i];
                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92)){
                        continue;
                    }
                    else{
                        printf("\nFirst name is invalid! Enter alphabets only!!!");
                        goto name;
                    }
                }
                for( i = 0; i<strlen(lname); i++){
                    int j = lname[i];
                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92)){
                        continue;
                    }
                    else{
                        printf("\nFirst name is invalid! Enter alphabets only!!!");
                        goto name;
                    }
                }

            }

            number:
            {
                mobile = 0;
                printf("\nEnter Your Mobile Number:");
                scanf("%lld", &mobile);
                fflush(stdin);

                if(mobile<=9000000000 || mobile>=9999999999){
                    printf("\n Invalid Mobile Number");
                    goto number;
                }
                else{
                    goto appointments;
                }
            }

            appointments:
            {
                printf("Select Schedule Number:\n");
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
                                printf("\n Already Booked");
                                goto appointments;
                            }
                        }
                    }
                }
                else{
                    printf("\nInvalid Input");
                    goto appointments;
                }
            }

            booking:
            {
                total_amount = b.price;
                printf("\nAppointment Reserved Successfully");
                printf("**BILL**");
                printf("\nName: %s %s", fname, lname);
                printf("\nMobile Number: %lld", mobile);
                printf("Service Name: %s", b.service);
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

                cusf = fopen("customerinfo.txt","a");

                if(cusf == NULL){
                    printf("File Not Found!");
                }
                else{
                    fprintf(cusf,"%s %s %lld %s %d \n",fname, lname, mobile, b.service, temp_sin);
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
            printf("Wrong choice!!!");
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