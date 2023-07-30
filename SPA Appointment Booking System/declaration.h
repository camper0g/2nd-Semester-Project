FILE *bookf;
FILE *cusf;
FILE *file;

int i=0 , j=0, k=0;

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
