#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char command[20];
  char* mainheap = (char *)malloc(400);
  char* begin = mainheap;
  char* end = mainheap;
  int block_counter = 1;

  short size = 398;


  //SIZE - ALLOCATED - BLOCKNUM
  *(unsigned short *)mainheap = size;
  mainheap += 2;
  *mainheap = 0;
  mainheap ++;
  *mainheap = 0;
  mainheap ++;



  while(strcmp(command, "quit")!=0){
    printf(">");
    scanf("%s", command);
    if(strcmp(command,"allocate")==0){
      int second;
      scanf("%d",&second);
      int flag=0;
      char* cursor = mainheap;
      while(1){
        unsigned int
      }
    }
  }



  return 0;

}
