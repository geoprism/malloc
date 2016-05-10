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

			int flag = 0;
			struct memory_block block;
			int j;
			for(j=0; j<block_counter && table[j].block_num<block_counter &&  table[j].block_num>0 && flag !=1; j++){
				if(table[j].allocated == 0 && second <= table[j].size){
					block.block_num = block_counter;
					block.starting = table[j].starting;
					block.size = second;
					block.allocated = 1;
					block.ending = table[j].starting + second;
					table[block_counter-1] = block;


					if(second != table[j].size){       //checks partially free space
						table[j].size = table[j].size - second;
						table[j].starting = table[j].starting + second + 1;
					}
					else{
						table[j].block_num = -1 * table[j].block_num;   //if free space is filled up remove the element.
					}
					flag =1;
				}
			}

			if(flag != 1){
				block.block_num = block_counter;
				block.starting = mainheap;
				block.size = second;
				block.allocated = 1;
				mainheap = mainheap + second;
				block.ending = mainheap;
				table[block_counter-1] = block;

				end = mainheap;   //used for blocklist(), too print in order of heap
				mainheap++;
			}


			printf("%d\n",block_counter);
			block_counter++;



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
			for(j=0; j<block_counter && table[j].block_num<block_counter &&  table[j].block_num>0; j++){
				if(second == table[j].block_num){
					table[j].allocated = 0;
				}
			}
		}

		else if(strcmp(command,"blocklist")==0){
			void* start = begin;
			printf("BlockNum  Size  Allocated   Start             End\n");
			while(start < end){
				int j;
				for(j=0; j<block_counter && table[j].block_num<block_counter; j++){
					if(table[j].block_num>0 && table[j].starting == start){
						printf("%-3d       ", table[j].block_num);
						printf("%-3d   ", table[j].size);
						if(table[j].allocated == 0){
							printf("no          ");
						}
						else{ printf("yes         ");}
						printf("%p    ", table[j].starting);
						printf("%p\n", table[j].ending);
						start = table[j].ending + 1;
					}
				}
			}
			// int j;
			// for(j=0; j<block_counter && table[j].block_num<block_counter &&  table[j].block_num>0; j++){
			// 	printf("%-3d       ", table[j].block_num);
			// 	printf("%-3d   ", table[j].size);
			// 	if(table[j].allocated == 0){
			// 		printf("no          ");
			// 	}
			// 	else{ printf("yes         ");}
			// 	printf("%p    ", table[j].starting);
			// 	printf("%p\n", table[j].ending);
			// }
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
