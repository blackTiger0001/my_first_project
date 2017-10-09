#include <custom/header.h>
#include <unistd.h>		/* For brk(), sbrk() */
#include <stdlib.h>		/* For malloc(), realloc(), freee */

int main(int argc, char **argv){
	void *program_break;
	if((program_break = sbrk(0)) == (void *) -1){
		printf("Unable to detect initial program break:  %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("Initial program break at: 	%10p\n", program_break);

	int blk_n, blk_s;
	if(argv[1] == NULL){
		printf("Warning: No block number given. Using default value (10).\n");
		blk_n = 10;
	}
	else{
		blk_n = atoi(argv[1]);
		if(argv[2] == NULL){
			blk_s = sysconf(_SC_PAGESIZE);
			printf("Warning: No block size given. Using system page size (%dB).\n", blk_s);
		}
		else blk_s = atoi(argv[2]);
	}

	printf("Allocating Memory...\n");
	void *PTR[blk_n]; int n;
	for(n = 0; n < blk_n; n++){
		PTR[n] = malloc(blk_s);
		if(PTR[n] = NULL){
			printf("Unable to allocate memory for Block Number %d : %s\n." \
			       "Exiting allocation process..\n", n+1, strerror(errno));
			break;
		}
	}
	printf("Allocation sucessfull for %d blocks\n", n);
	if (n == 0) exit(EXIT_FAILURE);

	if((program_break = sbrk(0)) == (void *) -1){
                printf("Unable to detect program break after alloction:  %s\n", strerror(errno));
                exit(EXIT_FAILURE);
        }
	printf("After allocation program break is at:	%10p\n", program_break);
	
	printf("Freeing block %d...\n", n); 
	free(PTR[n-1]);
	printf("Freeing block %d..\n", n-1);
	free(PTR[n-2]);
	

	if((program_break = sbrk(0)) == (void *) -1){
		printf("Unable to detect program brreak after freeing memory:  %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("After freeing memory program break is at:      %10p\n", program_break);

	printf("Operation: Successful. Exit..\n\n");
	
	exit(EXIT_SUCCESS);
}
