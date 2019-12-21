#include "ft_printf.h"

int  main()
{

int a,b;

a = ft_printf("%x\n", 100);
b = printf("%x\n", 100);

printf("%d\n%d", a, b);
    return 0;
}