#include "ft_printf.h"

int  main()
{

char a,b;

a = ft_printf("Bla bla %03%");
b = printf("Bla bla %03%");


printf("%d\n%d\n\n\n", a, b);
    return 0;
}