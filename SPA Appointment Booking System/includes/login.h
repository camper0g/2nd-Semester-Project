void rlogin()
{
	int a = 4, i = 0;
    char uname[100], c=' '; 
    char pword[100], code[100];
    char fileUsername[100];
    char filePassword[100];

    do
    {
        file = fopen("./Appdata/login.bat", "rb");
        if (file == NULL) 
        {
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                            NO LOGIN RECORDS FOUND                         ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            printf("                       PRESS ANY KEY TO CONTINUE TO SIGN UP");
            getch();
            system("cls");
            
            file = fopen("./Appdata/login.bat", "wb");
            SetFileAttributes("./Appdata/login.bat", FILE_ATTRIBUTE_HIDDEN);

            printf("||==================== USER >>> SIGN UP =======================||\n");
            printf("||  ENTER NEW USERNAME: ");
            scanf("%s", uname);
            printf("||  ENTER NEW PASSWORD: ");
            while(1){
                c = getch();            
                if(c == 13){
                    pword[i]='\0';
                    i = 0;
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
                    pword[i] = c;
                    i++;
                    printf("*");            
                }
            }

            fprintf(file, "%s %s", uname, pword);
            fclose(file);

            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                            SIGNED UP SUCCESSFULLY                         ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            printf("                       PRESS ANY KEY TO CONTINUE");
            getch();
            system("cls");
            return;
        }

        else{
            printf("||====================== USER LOGIN INFO  ======================||\n");
            printf("||  ENTER USERNAME => ");
            scanf("%s", &uname); 
            printf("||  ENTER PASSWORD => ");
            while(1){
                c = getch();            
                if(c == 13){
                    pword[i]='\0';
                    i = 0;
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
                    pword[i] = c;
                    i++;
                    printf("*");            
                }
            } 

            fscanf(file, "%s %s", fileUsername, filePassword);

            fclose(file);
        }
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
            printf("||                        WAIT FEW SECONDS BEFORE YOU TRY AGAIN");
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

void alogin()
{
	int a=4,i=0;
    char uname[100],c=' '; 
    char pword[100],code[100];
    char fileUsername[100];
    char filePassword[100];

    do
    {
        file = fopen("./Appdata/admin.bat", "rb");
        if (file == NULL) 
        {
            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                            NO LOGIN RECORDS FOUND                         ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            printf("                       PRESS ANY KEY TO CONTINUE TO SIGN UP");
            getch();
            system("cls");
            
            file = fopen("./Appdata/admin.bat", "wb");
            SetFileAttributes("./Appdata/admin.bat", FILE_ATTRIBUTE_HIDDEN);


            printf("||================== SIGN UP >>> ADMINISTRATOR =====================||\n");
            printf("||  ENTER NEW USERNAME: ");
            scanf("%s", uname);
            printf("||  ENTER NEW PASSWORD: ");
            while(1){
                c = getch();            
                if(c == 13){
                    pword[i]='\0';
                    i = 0;
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
                    pword[i] = c;
                    i++;
                    printf("*");            
                }
            }

            fprintf(file, "%s %s", uname, pword);
            fclose(file);

            system("cls");
            printf("||===========================================================================||\n");
            printf("||                                                                           ||\n");
            printf("||                            SIGNED UP SUCCESSFULLY                         ||\n");
            printf("||                                                                           ||\n");
            printf("||===========================================================================||\n");
            printf("                       PRESS ANY KEY TO CONTINUE");
            getch();
            system("cls");
            return;
        }

        else{
            printf("||==================== ADMIN LOGIN INFO  =====================||\n");
            printf("||  ENTER USERNAME => ");
            scanf("%s", &uname); 
            printf("||  ENTER PASSWORD => ");
            while(1){
                c = getch();            
                if(c == 13){
                    pword[i]='\0';
                    i = 0;
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
                    pword[i] = c;
                    i++;
                    printf("*");            
                }
            } 

            fscanf(file, "%s %s", fileUsername, filePassword);
            fclose(file);

        }
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
            printf("||                        WAIT FEW SECONDS BEFORE YOU TRY AGAIN");
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

void change_password(){
    int choice;
    system("cls");
    printf("||===========================================================================||\n");
    printf("||************************* SELECT USER TYPE ********************************||\n");
    printf("||===========================================================================||\n");
    printf("||                                                                           ||\n");
    printf("||  PRESS [1] => REGULAR USER                                                ||\n");
    printf("||  PRESS [2] => ADMINISTRATOR                                               ||\n");
    printf("||  PRESS [3] => RETURN TO MENU                                              ||\n");
    printf("||                                                                           ||\n");
    printf("||===========================================================================||\n");
    printf("||  SELECT USER TYPE => ");
    scanf("%d", &choice);
    fflush(stdin);
    if( choice == 1)
    {
        int i = 0;
        char pword[100], uname[100], c= ' ';
        printf("||===========================================================================||\n");
        printf("||********************* UPDATE REGULAR USER LOGIN INFO **********************||\n");
        printf("||===========================================================================||\n");
        printf("||  NEW USERNAME => ");
        scanf("%s", &uname); 
        printf("||  NEW PASSWORD => ");
        while(1){
            c = getch();            
            if(c == 13){
                pword[i]='\0';
                i = 0;
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
                pword[i] = c;
                i++;
                printf("*");            
            }
        }
        SetFileAttributes("./Appdata/login.bat", FILE_ATTRIBUTE_NORMAL);

        file = fopen("./Appdata/login.bat", "wb");

        if(file == NULL)
        {
            printf("\n\n\t\tERROR OPENING FILE.\n");
            system("pause");
        }
        fprintf(file, "%s %s",uname ,pword);
        fclose(file);

        SetFileAttributes("./Appdata/login.bat", FILE_ATTRIBUTE_HIDDEN);

        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                     LOGIN INFO UPDATED SUCCESSFULLY                       ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("                       PRESS ANY KEY TO CONTINUE");
        getch();
        system("cls");
    }

    else if( choice == 2)
    {
        int i = 0;
        char pword[100], uname[100], c= ' ';
        printf("||===========================================================================||\n");
        printf("||********************* UPDATE ADMINISTRATOR LOGIN INFO *********************||\n");
        printf("||===========================================================================||\n");
        printf("||  NEW USERNAME => ");
        scanf("%s", &uname); 
        printf("||  NEW PASSWORD => ");
        while(1){
            c = getch();            
            if(c == 13){
                pword[i]='\0';
                i = 0;
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
                pword[i] = c;
                i++;
                printf("*");           
            }
        }

        SetFileAttributes("./Appdata/admin.bat", FILE_ATTRIBUTE_NORMAL);

        file = fopen("./Appdata/admin.bat", "wb");
        if (file == NULL) 
        {
            printf("\n\n\t\tERROR OPENING FILE.\n");
            system("pause");
        }
        fprintf(file, "%s %s",uname ,pword);
        fclose(file);

        SetFileAttributes("./Appdata/admin.bat", FILE_ATTRIBUTE_HIDDEN);

        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                     LOGIN INFO UPDATED SUCCESSFULLY                       ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        printf("                       PRESS ANY KEY TO CONTINUE");
        getch();
        system("cls");
    }
    else if(choice == 3){
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                                RETURNING BACK                             ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        Sleep(1500);
        system("cls");
        //amenu();
    }
    else{
        system("cls");
        printf("||===========================================================================||\n");
        printf("||                                                                           ||\n");
        printf("||                               INVALID OPTION                              ||\n");
        printf("||                                                                           ||\n");
        printf("||===========================================================================||\n");
        Sleep(750);
        change_password();
    }
}