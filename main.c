#include "ft_printf.h"

int main() 
{
//  char *fname = strdup("Faical");
//  char *lname = strdup("BOUIBAOUEN");
  // int a = 3648;
  
//printf("\n\nhello evreybody i'm %s %s i have %d",fname, lname, a);
   ft_printf("|%0*.*d|\n", -6, 3, -32);
   printf("|%0*.*d|\n", -6, 3,  -32);

//printf("%p\n",&a);


  return 0;
}
