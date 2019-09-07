/*
   Write a C program to find out if the underlying
   architecture is little endian or big endian.
 */

#include <stdio.h>
int main ()
{
  unsigned int x = 0x76543210;
  char *c = (char*) &x;

  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }

  return 0;
}
