#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){
    char uname[10], pass[10], ch = ' ';
    int buname, bpass, i=0;
    
    printf("Enter Username:");
    scanf("%s", uname);
    printf("Enter password:");
    while(1)
    {
        ch = getch();
        if(ch == '\r'){
            pass[i] = '\0';
            break;
        }
        else{
            pass[i] = ch;
            printf("*");
        }
        i++;
    }

    printf("\n%s",uname);
    printf("\n%s", pass);

    sscanf(uname, "%d", &buname);
    sscanf(pass, "%d", &bpass);
    

    printf("\n%d", buname);
    printf("\n%d", bpass);

    sprintf(buname, "%s", uname);
    sprintf(bpass, "%s", pass);
    

    printf("\n%s", uname);
    printf("\n%s", pass);

    getch();

    return 0;

}