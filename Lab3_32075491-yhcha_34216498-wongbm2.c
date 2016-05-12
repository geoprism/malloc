//Wong, Brian: 34216498
//Cha, Yoon Ho: 32075491


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char command[20];
  char* mainheap = (char *)malloc(400);
  char* begin = mainheap;
  int block_counter = 1;
  int freed = 0;


  *(unsigned short *)mainheap = 396;         //size
  *(mainheap +2) = 0;                        //allocated
  *(mainheap +3) = 0;                        //block_num


  while(strcmp(command,"quit")!=0){
      printf(">");
      scanf("%s",command);
      if(strcmp(command,"allocate")==0){
          int second;
          scanf("%d",&second);  //get number of bytes to allocate


          char* cursor = begin;
          while(1){

              if(*(unsigned short *)cursor >= second && *(cursor+2) == 0){
                  unsigned short old_size = *(unsigned short *)cursor;
                  char old_counter = *(cursor +3);

                  //SPLITTING, filling in extra space
                  if(old_size-second-4<=0){
                      *(unsigned short *)cursor = old_size;
                      *(cursor +2) = 1;
                      *(cursor +3) = block_counter;
                      freed++;
                  }

                  //SPLITTING with extra space
                  else{

                      *(unsigned short *)cursor = second;   //size
                      *(cursor +2) = 1;                     //allocated
                      *(cursor +3) = block_counter;         //block_num

                      cursor += second + 4;

                      *(unsigned short *)cursor = old_size - second-4;
                      *(cursor +2) = 0;
                      *(cursor +3) = old_counter;
                  }
                   break;
              }
              cursor += *(unsigned short *)cursor + 4;
          }

          printf("%d\n",block_counter);
          block_counter++;
      }

      else if(strcmp(command,"free")==0){
          int second;
          scanf("%d",&second); //gets block number

          int i;
          char* cursor = begin;
          for(i = 0; i< block_counter; i++){
              int size = *(unsigned short *)cursor;
              if(*(cursor+3) == second){
                  *(cursor+2) = 0;
                  int j;
                  for(j=0; j<size; j++){
                      *(cursor+4+j)='\0';
                  }
                  break;
              }
              cursor += size +4;
          }
      }

      else if(strcmp(command,"blocklist")==0){
          printf("BlockNum  Size   Payload    Allocated   Start             End\n");

          int i;
          char* step = begin;
          for(i = 0; i< block_counter-freed; i++){
              int size = *(unsigned short *)step;

              printf("%-3d       ", *(step+3));
              printf("%-3d    ",(*(unsigned short *)step) + 4);
              printf("%-3d        ", (*(unsigned short *)step));
              if(*(step+2) == 0){
                  printf("no          ");
              }
              else{ printf("yes         ");}
              printf("%-12p    ", step);
              printf("%-12p\n", step+4+size-1);
              step += size +4;
          }
          printf("------------------------------------------------------------------------\n");
      }

      else if(strcmp(command,"writeheap")==0){
          int second;
          scanf("%d",&second); //gets block number
          char third;
          scanf(" %c", &third);
          int fourth;
          scanf("%d",&fourth);

          int i;
          char* cursor = begin;
          for(i = 0; i< block_counter-freed; i++){
              int size = *(unsigned short *)cursor;
              if(*(cursor+3) == second && *(cursor+2)==1){
                  if(fourth>size){
                      printf("WARNING: YOU HAVE OVERWRITTEN INTO THE NEXT BLOCK\n");
                  }
                  int j;
                  for(j=0; j<fourth; j++){
                      *(cursor+4+j) = third;
                  }
                  break;
              }
              cursor += size +4;
          }
      }

      else if(strcmp(command,"printheap")==0){
          int second;
          scanf("%d",&second); //gets block number
          int third;
          scanf("%d",&third);

          int i;
          char* cursor = begin;
          for(i = 0; i< block_counter-freed; i++){
              int size = *(unsigned short *)cursor;
              if(*(cursor+3) == second && *(cursor+2)==1){
                  int j;
                  for(j=0; j<third; j++){
                      printf("%c",*(cursor+4+j));
                  }
                  printf("\n");
                  break;
              }
              cursor += size +4;
          }

      }

      else{
          if(strcmp(command,"quit")!=0)
              printf("INVALID COMMAND, TRY AGAIN\n");
      }
  }

  mainheap = begin;
  free(mainheap);

  return 0;
}
