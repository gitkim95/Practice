#include <stdio.h>

int main()
{
    unsigned long   a;
    unsigned long   b;
    unsigned long   c;

    scanf("%ld %ld %ld", &a, &b, &c);
    printf("%ld", a + b + c);
    return(0);
}