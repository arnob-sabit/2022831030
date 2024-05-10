#include<stdio.h>

int main()
{
    int n1,n2;
    char a='+',b='-',c='*',d='/';

    printf("enter the first value:");
    scanf("%d",&n1);

    printf("enter the second value:");
    scanf("%d",&n2);

    printf("%d %c %d=%d\n",n1,a,n2,n1+n2);
    printf("%d %c %d=%d\n",n1,b,n2,n1-n2);
    printf("%d %c %d=%d\n",n1,c,n2,n1*n2);
    printf("%d %c %d=%d\n",n1,d,n2,n1/n2);

    return 0;

}

