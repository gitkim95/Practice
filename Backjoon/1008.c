#include <stdio.h>

int     main()
{
        double     a;
        double     b;

        scanf("%lf %lf", &a, &b);
        printf("%.16lf", a / b);
        return (0);
}