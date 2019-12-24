#include "ft_printf.h"

int  main()
{

int a,b = 2,c = 3;

// a = ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%\n", 7,5, "ABC",15,0);
// b = printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%\n", 7,5, "ABC",15,0);
    // ft_printf("%*.*x\n", 0, 0, 100);
	// ft_printf("%*.*x\n", 0, 0, UINT32_MAX);
	// ft_printf("%*.*x\n", 0, 0, UINT32_MAX + 95);
	// ft_printf("%*.*x\n", 0, 0, 0);
	// ft_printf("a%*.*xa\n", 0, 0, 100);
	// ft_printf("a%*.*xa\n", 0, 0, UINT32_MAX);
	// ft_printf("a%*.*xa\n", 0, 0, 0);
a = ft_printf("Bla bla %*.d\n", 0, 0);
b = printf("Bla bla %*.d\n", 0, 0);
//b = printf("Bla bla %p\n", &c);
printf("%d\n%d",a,b);
    return 0;
}