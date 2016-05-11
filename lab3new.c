#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char command[20];
  void* mainheap = (char *)malloc(400);
  void* begin = mainheap;
  void* end = mainheap;
  int block_counter = 1;

  short size;
  size = 398;

  *mainheap = size;

  printf("%d", mainheap);


  return 0;

}
