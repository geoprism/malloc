#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char command[20];
  char* mainheap = (char *)malloc(400);
  char* front = mainheap;
  char* debug = front;
  int freed = 0;

  int block_counter = 1;

  short size = 396;


  //SIZE - ALLOCATED - BLOCKNUM
  *(unsigned short *)mainheap = size;
  mainheap += 2;
  *mainheap = 0;
  mainheap ++;
  *mainheap = 0;
  mainheap ++;

  mainheap = front;



  while(strcmp(command, "quit")!=0){
    printf(">");
    scanf("%s", command);
    if(strcmp(command,"allocate")==0){
      int second;
      scanf("%d",&second);
      char* cursor = front;
      int old_block_num;
      while(1){
        unsigned short current_size = *(unsigned short *)cursor;
        cursor+=2;
        if(*cursor == 0 &&(current_size-second)>4 ){
          cursor -= 2;
          *(unsigned short *)cursor = second;
          cursor +=2;
          *cursor = 1;
          cursor++;
          old_block_num = *cursor;
          *cursor = block_counter;

          block_counter++;
          cursor += second + 1;
          *(unsigned short *)cursor = current_size - second - 4;
          cursor += 2;
          *cursor = 0;
          cursor ++;
          *cursor = old_block_num;
          break;
        }
        else if(*cursor == 0 && (current_size-second)<=4){
          cursor -= 2;
          *(unsigned short *)cursor = second + current_size-second;
          cursor +=2;
          *cursor = 1;
          cursor ++;
          freed ++;
          *cursor = block_counter;
          block_counter++;
          break;
        }
        else{
          cursor +=current_size + 2;
        }
      }
    }
    else if(strcmp(command, "blocklist")==0){
      printf("BlockNum  Size  Allocated   Start             End\n");
      int counter = 0;
      char* cursor;
      char* front_cursor;
      cursor = front;
      char yn[10];
      while(counter != block_counter - freed){
        front_cursor = cursor;
        int this_size = *(unsigned short *)cursor;
        cursor += 2;
        int this_allocated = *cursor;
        cursor++;
        int this_blocknum = *cursor;
        printf("%-3d       ", this_blocknum);
        printf("%-3d   ", this_size + 4);
        if(this_allocated == 1)
          strcpy(yn, "yes");
        else
          strcpy(yn, "no ");
        printf("%s          ", yn);
        printf("%p         ", front_cursor);
        cursor += this_size;
        printf("%p\n", cursor);
        counter++;
        cursor++;
      }
    }
    else if(strcmp(command, "printheap") == 0){
      int second;
            scanf("%d",&second); //gets block number
      int third;
            scanf("%d",&third);
      char* cursor = front;

      if(second < block_counter){
        while(1){
          int this_size = *cursor;
          cursor += 2;
          int this_allocated = *cursor;
          cursor++;
          if(*cursor == second){
            if(this_allocated == 0){
              printf("That block is unallocated.\n");
              break;
            }
            cursor++;
            int i;
            for(i=0; i<third; i++){
              printf("%c", *cursor);
              cursor++;
            }
            printf("\n");
            break;
          }
          else{
            cursor += this_size + 1;
          }
        }
      }
      else{
        printf("No Such Block\n");
      }
    }

    else if(strcmp(command, "writeheap") == 0){
      int second;
      scanf("%d", &second);
      char third;
      scanf(" %c", &third);
      int fourth;
      scanf("%d",&fourth);
      char* cursor = front;
      int total_size = 0;

      if(second < block_counter){
        while(1){
          if(total_size >= 400){
            printf("That block is unallocated\n");
            break;
          }
          int this_size = *cursor;
          cursor += 2;
          int this_allocated = *cursor;
          cursor++;
          if(*cursor == second){
            if(this_allocated == 0){
              printf("That block is already unallocated.\n");
              break;
            }
            cursor ++;
            int i;
            for(i=0; i<fourth; i++){
              *cursor = third;
              cursor++;
            }
            break;
          }
          else{
            cursor += this_size + 1;
            total_size += this_size + 4;
          }
        }
      }
      else{
        printf("No Such Block\n");
      }
    }

    else if(strcmp(command,"free")==0){
              int second;
              scanf("%d",&second); //gets block number

              int i;
              char* cursor = front;
              for(i = 0; i< block_counter; i++){
                  int size = *(unsigned short *)cursor;
                  if(*(cursor+3) == second){
                      *(cursor+2) = 0;
                      break;
                  }
                  cursor += size +4;
              }
          }
  }



  return 0;

}
