<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> ad30266a89f4238f83fc28894dc3e3703b4e2212
//Wong, Brian: 34216498
//Cha, Yoon Ho: 32075491


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char command[20];
	int* mainheap = (int *)malloc(4*400);

	while(strcmp(command,"quit")!=0){
		printf(">");
        if(strcmp(command,"allocate")==0){
			char second[20];
            scanf("%s",second);  //get number of bytes to allocate

        }

		else if(strcmp(command,"free")==0){
            char second[20];
            scanf("%s",second); //gets block number
		}

		else if(strcmp(command,"blocklist")==0){

		}

		else if(strcmp(command,"writeheap")==0){

		}

		else if(strcmp(command,"printheap")==0){


		}

		else{
			printf("INVALID COMMAND, TRY AGAIN\n");
		}



	scanf("%s",command);
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


<<<<<<< HEAD
		free(mainheap);
		return 0;
	}
=======
	free(mainheap);

	return 0;
}
>>>>>>> ad30266a89f4238f83fc28894dc3e3703b4e2212
