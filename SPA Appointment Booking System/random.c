#include<stdio.h>
#include<conio.h>

int main()
{
    int tid;
    FILE *cusf;
    cusf = fopen("customerinfo.txt","r");
    if(cusf == NULL){
        printf("Error Opening File\n");
    }
    else{
        fseek(cusf, -3, SEEK_END);
        fscanf(cusf, "%d", &tid);
    }

    fclose(cusf);

    printf("%d",tid);
    getch();
    return 0;
}
