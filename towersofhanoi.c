#include<stdio.h>

void toh(int n,char source,char dest,char temp);
int main()
{
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);

    toh(n,'A','C','B');

}

void toh(int n,char source,char dest,char temp){
    if(n>0){
        toh(n-1,source,temp,dest);
        printf("\nmove %d\t tower from %c\t source to %c\t destination",n,source,dest);
        toh(n-1,temp,dest,source);
    }
}