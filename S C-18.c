#include<stdio.h>

int main()
{
    double n1,n2;

    printf("enter the first value:");
    scanf("%lf",&n1);

    printf("enter the second value:");
    scanf("%lf",&n2);

    printf("%lf+%lf=%lf\n",n1,n2,n1+n2);
    printf("%lf-%lf=%lf\n",n1,n2,n1-n2);
    printf("%lf*%lf=%lf\n",n1,n2,n1*n2);
    printf("%lf/%lf=%lf\n",n1,n2,n1/n2);

    return 0;

}
