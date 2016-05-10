
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char command[20];
	char* mainheap = (char *)malloc(400);
	int block_counter = 1;

	struct memory_block{
		int block_num;
		void* starting;
		void* ending;
	};

	struct memory_block table[400];

	while(strcmp(command,"quit")!=0){
		printf(">");
		scanf("%s",command);
    if(strcmp(command,"allocate")==0){
			int second;
      scanf("%d",&second);  //get number of bytes to allocate
			struct memory_block block;
			block.block_num = block_counter;
			block.starting = mainheap;
			int i;
			mainheap = mainheap + second;
			block.ending = mainheap;
			table[block_counter-1] = block;
			block_counter ++;
			mainheap++;

			int j;
			for(j=0; j<10; j++){
				printf("%d\n", table[j].block_num);
				printf("%p\n", table[j].starting);
				printf("%p\n", table[j].ending);

			}
    }

		else if(strcmp(command,"free")==0){
            int second;
            scanf("%d",&second); //gets block number
		}

		else if(strcmp(command,"blocklist")==0){

		}

		else if(strcmp(command,"writeheap")==0){

		}

		else if(strcmp(command,"printheap")==0){


		}

		else{
			printf("INVALID COMMAND, TRY AGAIN\n>");
			//printf(">");
		}
	}

	int k;
	for(k = 0; k<400; k++){
		mainheap[k] = k+1;

	}

	int j;
	for(j = 0; j<400; j++){
		printf("%d\n", mainheap[j]);
		//mainheap++;
	}


	free(mainheap);

	return 0;
}
