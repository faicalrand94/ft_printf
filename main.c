#include "ft_printf.h"

int main() 
{
//  char *fname = strdup("Faical");
//  char *lname = strdup("BOUIBAOUEN");
  // int a = 3648;
  
//printf("\n\nhello evreybody i'm %s %s i have %d",fname, lname, a);
ft_printf("|%*.*d|\n", -16, 3, 12);
   printf("|%*.*d|\n", -16,  3, 12);

//printf("%p\n",&a);


  return 0;
}
