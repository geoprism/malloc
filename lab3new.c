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

  short size = 2000;

  // *(unsigned short *)mainheap = size;
  // printf("%d\n", *(unsigned short *)mainheap);
  // printf("%d\n", *mainheap);
  // mainheap++;
  // printf("%d\n", *(unsigned short *)mainheap);
  // printf("%d\n", *mainheap);

  while(strcmp(command, "quit")!=0){
    printf(">");
    scanf("%s", command);
    if(strcmp(command,"allocate")==0){
      int second;
      scanf("%d",&second);
      int flag=0;
      char* cursor = mainheap;
      while(){
        if(
      }
    }
  }



  return 0;

}
