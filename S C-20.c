#include<stdio.h>

int main()
{
    int n1,n2,value;
    char sign;

    printf("please enter the first number:");
    scanf("%d",&n1);
    printf("please enter the second number:");
    scanf("%d",&n2);


    value=n1+n2;
    sign='+';
    printf("%d %c %d = %d\n",n1,sign,n2,value);

    value=n1-n2;
    sign='-';
    printf("%d %c %d = %d\n",n1,sign,n2,value);

    value=n1*n2;
    sign='*';
    printf("%d %c %d = %d\n",n1,sign,n2,value);

    value=n1/n2;
    sign='/';
    printf("%d %c %d = %d\n1",n1,sign,n2,value);

    return 0;
}
