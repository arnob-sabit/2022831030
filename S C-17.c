#include<stdio.h>

int main()
{
    int n1,n2,r1,r2,r3,r4;

    printf("enter the first value:");
    scanf("%d",&n1);

    printf("enter the second value:");
    scanf("%d",&n2);

    r1=n1+n2;
    r2=n1-n2;
    r3=n1*n2;
    r4=n1/n2;

    printf("%d+%d=%d\n",n1,n2,r1);
    printf("%d-%d=%d\n",n1,n2,r2);
    printf("%d*%d=%d\n",n1,n2,r3);
    printf("%d/%d=%d\n",n1,n2,r4);

    return 0;

}
