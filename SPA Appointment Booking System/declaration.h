#include "headers.h"

FILE *bookf;
FILE *cusf;
FILE *file;

int i, j, k;

struct book{
    int sn;
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
