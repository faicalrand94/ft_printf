#include "ft_printf.h"

int main() 
{
//  char *fname = strdup("Faical");
//  char *lname = strdup("BOUIBAOUEN");
  // int a = 3648;
  
//printf("\n\nhello evreybody i'm %s %s i have %d",fname, lname, a);
  // ft_printf("|%-10.5d|\n", -15);
  ft_printf("|%-10.*s|\n", 6, "hello");
     printf("|%-10.*s|\n", 6,  "hello");
  
//printf("%p\n",&a);


  return 0;
}
