//Wong, Brian: 34216498
//Cha, Yoon Ho: 32075491


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char command[20];
	char* mainheap = (char *)malloc(400);
	void* begin = mainheap;   //used for blocklist(), too print in order of heap
	void* end = mainheap;	  //used for blocklist(), too print in order of heap
	int block_counter = 1;

	struct memory_block{
		int block_num;
		int size;
		int allocated;
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
			block.size = second;
			block.allocated = 1;
			int i;
			mainheap = mainheap + second;
			block.ending = mainheap;
			table[block_counter-1] = block;


			printf("%d\n",block_counter);
			block_counter++;
			end = mainheap;   //used for blocklist(), too print in order of heap
			mainheap++;


			// int j;
			// for(j=0; table[j].block_num<block_counter && j<401 && table[j].block_num>0; j++){
			// 	printf("Block number: %d\n", table[j].block_num);
			// 	printf("Allocated: %d\n", table[j].allocated);
			// 	printf("Size: %d\n", table[j].size);
			// 	printf("%p\n", table[j].starting);
			// 	printf("%p\n", table[j].ending);
			// 	printf("-------------------------------------------\n");
			// }
    	}


		else if(strcmp(command,"free")==0){
            int second;
            scanf("%d",&second); //gets block number
			int j;
			for(j=0; table[j].block_num<block_counter && j<401 && table[j].block_num>0; j++){
				if(second == table[j].block_num){
					table[j].allocated = 0;
				}
			}
		}

		else if(strcmp(command,"blocklist")==0){
			printf("BlockNum  Size  Allocated   Start             End\n");
			int j;
			for(j=0; table[j].block_num<block_counter && j<401 && table[j].block_num>0; j++){
				printf("%-3d       ", table[j].block_num);
				printf("%-3d   ", table[j].size);
				if(table[j].allocated == 0){
					printf("no          ");
				}
				else{ printf("yes         ");}
				printf("%p    ", table[j].starting);
				printf("%p\n", table[j].ending);
			}

		}

		else if(strcmp(command,"writeheap")==0){

		}

		else if(strcmp(command,"printheap")==0){


		}

		else{
			printf("INVALID COMMAND, TRY AGAIN\n");
		}
	}

	// int k;
	// for(k = 0; k<400; k++){
	// 	mainheap[k] = k+1;
	//
	// }
	//
	// int j;
	// for(j = 0; j<400; j++){
	// 	printf("%d\n", mainheap[j]);
	// 	//mainheap++;
	// }


	free(mainheap);

	return 0;
}
