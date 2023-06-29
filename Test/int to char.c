#include <stdio.h>
#include <conio.h>
struct book{
    int sn;
    char service[50];
    int price;
    int time[7];
}; 
int main(){

    struct book b;
    FILE *bookf;
    int i, j;
    char ch;

    for(i = 0; i<3; i++){
        if(i == 0){
            bookf = fopen("service1.txt", "r+");
        }
        else if(i == 1){
            bookf = fopen("service2.txt", "r+");
        }
        else{
            bookf = fopen("service3.txt", "r+");
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
    getch();
    return 0;
}