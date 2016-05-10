#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
	{



		struct memory_block{
			int block_num;
			void* starting;
			void* ending;
		};


		char* ptr_one;
		ptr_one = (char*)malloc(400*sizeof(char));

		struct memory_block block1;

		block1.starting = ptr_one;
		ptr_one = ptr_one + 4;
		block1.ending = ptr_one;

		printf("%p\n",block1.starting);
		printf("%p\n",ptr_one);



		return 0;


	}
