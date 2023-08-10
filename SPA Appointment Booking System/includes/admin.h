void view_transactions(){

    system("cls");
    char sn[50];
    struct customerinfo c;
    struct book b;
    cusf = fopen("./Appdata/customerinfo.txt", "r");

    if(cusf == NULL){
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
        while(fscanf(cusf,"%s %s %lld %d %s %d %d %d\n",c.fname, c.lname, &c.mobile, &b.sn, b.service, &c.sn, &c.total, &c.tid) != EOF){
            if (c.total == 0){
                strcpy(sn, "CANCELLED");
            }
            else if (c.sn == 1) {
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
    struct book b;
    char ch;
    char choice;

    system("cls");
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
    choice = tolower(choice);

    if(choice == 'y'){
        cusf = fopen("./Appdata/customerinfo.txt", "w");
        if(cusf == NULL){
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

            for(i = 0; i<3; i++){
                if(i == 0){
                    bookf = fopen("./Appdata/service1.txt", "r+");
                }
                if(i == 1){
                    bookf = fopen("./Appdata/service2.txt", "r+");
                }
                if(i == 2){
                    bookf = fopen("./Appdata/service3.txt", "r+");
                }
                if(bookf == NULL)
                {
                    continue;
                }
                fscanf(bookf, "%s %d\n", b.service, &b.price);
                fseek(bookf, 0, SEEK_SET);
                fprintf(bookf, "%s %d\n", b.service, b.price);
                for (j = 0; j < 7; j++){
                    b.time[j] = 1;
                    fprintf(bookf, "%d\n", b.time[j]);
                }
                fclose(bookf);
            }
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

void edit_services()
{
    
    struct book b;
    char choice, c;
    int ch;

    system("cls");
    printf("||===========================================================================||\n");
    printf("||***************************** LIST OF SERVICES ****************************||\n");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    bookf = fopen("./Appdata/service1.txt", "r");
    if(bookf == NULL){
        printf("||  PRESS [1] => ADD SERVICE\n");
        printf("\n");
    }
    else{
        fscanf(bookf,"%s %d", b.service, &b.price);
        printf("||  PRESS [1] => %s \n\t\t PRICE -> RS.%d\n", b.service, b.price);
        printf("\n");
    }
    fclose(bookf);
    

    bookf = fopen("./Appdata/service2.txt", "r");
    if(bookf == NULL){
        printf("||  PRESS [2] => ADD SERVICE\n");
        printf("\n");
    }
    else{
        fscanf(bookf,"%s %d", b.service, &b.price);
        printf("||  PRESS [2] => %s \n\t\t PRICE -> RS.%d\n", b.service, b.price);
        printf("\n");
    }
    fclose(bookf);

    bookf = fopen("./Appdata/service3.txt", "r");
    if(bookf == NULL){
        printf("||  PRESS [3] => ADD SERVICE\n");
        printf("\n");
    }
    else{
        fscanf(bookf,"%s %d", b.service, &b.price);
        printf("||  PRESS [3] => %s \n\t\t PRICE -> RS.%d\n", b.service, b.price);
        printf("\n");
    }
    fclose(bookf);

    printf("||  PRESS [4] => RETURN BACK\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    ch:
    {
        printf("||  ENTER YOUR CHOICE => ");
        scanf("%d",&ch);
        fflush(stdin);
    }
    if (ch == 1 || ch == 2 || ch == 3){
        goto edit;
    }
    else if(ch == 4){
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||             YOU'LL BE RETURNED BACK TO MAIN MENU IN A FEW SECONDS         ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        Sleep(2000);
        system("cls");
        return;
    }
    else{
        printf("** IVALID OPTION \n");
        goto ch;
    }

    edit:
    {
        
        system("cls");
        printf("||===========================================================================||\n");
        printf("||************************ ADD/ UPDATE INFORMATION **************************||\n");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||      DO YOU WANT TO ADD/ UPDATE SERVICE?                                  ||\n");
        printf("||      Press [Y/y] => YES                                                   ||\n");
        printf("||      Press [N/n] => NO                                                    ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");

        choose:{
            printf("||      Enter Your Choice ==> ");
            scanf("%c", &choice);
            fflush(stdin);
        }

        tolower(choice);

        if(choice == 'y'){
            i = 0;
            
            if(ch == 1){
                bookf = fopen("./Appdata/service1.txt", "w");
            }
            else if(ch == 2){
                bookf = fopen("./Appdata/service2.txt", "w");
            }
            else if(ch == 3){
                bookf = fopen("./Appdata/service3.txt", "w");
            }
            printf("||  ENTER SERVICE NAME (Use '_' for spaces) => ");
            while(1){
                c = getch();            
                if(c == 13){
                    b.service[i]='\0';
                    break;                                        
                }
                else if(c == 8){
                    if(i > 0){
                        i--;
                        printf("\b \b");
                    }
                }
                else if(c == 32){
                    continue;
                }
                else{
                    b.service[i] = c;
                    i++;
                    printf("%c",c);            
                }
            }
            printf("\n||  ENTER PRICE OF SERVICE => ");
            scanf("%d", &b.price);

            fprintf(bookf,"%s %d", b.service, b.price);
            for (i =0; i < 7; i++){
                b.time[i] = 1;
                fprintf(bookf,"\n%d",b.time[i]);
            }
            fclose(bookf);
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                        SERVICE UPDATED SUCCESSFULLY                       ||\n");
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
            printf("||                     YOU'LL BE RETURNED IN A FEW SECONDS                   ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            Sleep(2000);
            system("cls");
            return;
        }
        else{
            printf("** IVALID OPTION \n");
            goto choose;
        }
    }
}
