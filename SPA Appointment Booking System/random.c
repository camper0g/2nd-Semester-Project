#include<stdio.h>
#include<conio.h>

struct book {
    char service[50];
    int price;
    int time[7];
};

struct customerinfo {
    char fname[25];
    char lname[25];
    long long int mobile;
    int total;
    int sn;
    int tid;
};

int main() {
    // struct book b;
    // struct customerinfo c;
    // int ch;
    // FILE *cusf;

    // cusf = fopen("customerinfo.txt", "r");
    // if (cusf == NULL) {
    //     printf("Error Opening File\n");
    //     return 1;  // Return non-zero value to indicate failure
    // }

    // while (fscanf(cusf, "%s %s %lld %s %d %d %d\n", c.fname, c.lname, &c.mobile, b.service, &c.sn, &c.total, &c.tid) == 7) {
    //     printf("%s %s %lld %s %d %d %d\n", c.fname, c.lname, c.mobile, b.service, c.sn, c.total, c.tid);
    // }

    // fclose(cusf);
    // getch();
    // return 0;

    char ch[50];
    ch[50] = '10AM - 11AM';
    printf("%s", ch);
    return 0;
}
