/*
   Write a C program to find out if the underlying
   architecture is little endian or big endian.
 */

/*
   Function check_for_endianness() returns 1, if architecture
   is little endian, 0 in case of big endian.
 */

int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}

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
