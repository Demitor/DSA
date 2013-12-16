#include "Sort.h"
#include <stdio.h>
#include <sys/time.h>

static void disp_menu(){
	printf("************************************************************\n");
	printf("*** Welcome to algorithms efficiency testing             ***\n");
	printf("*** 1  : Bubble Sort                                     ***\n");
	printf("*** 2  : Insertion Sort                                  ***\n");
	printf("*** 3  : Quicksort                                       ***\n");
	printf("*** 4  : Linear Search                                   ***\n");
	printf("*** 5  : Binary Search                                   ***\n");
	printf("*** 6  : Search in Binary Tree (BST)                     ***\n");
	printf("*** 7  : Fill Random Case Array                          ***\n");
	printf("*** 8  : Fill Worst Case Array                           ***\n");
	printf("*** 9  : Print Array                                     ***\n");
	printf("*** 10 : Set Size of Array                               ***\n");
	printf("*** 11 : Display Menu                                    ***\n");
	printf("*** 0  : Exit                                            ***\n");
	printf("************************************************************\n");
}

int int main(int argc, char const *argv[])
{
	struct timeval tv0, tv1;
    struct timezone tzp;
    int c = -1;
    disp_menu();

    do{
    scanf("%d", &c);
	switch(c){
		case 1: //done
    rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		bubble_sort();
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		break;
		case 2: //done
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		insertion_sort();
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		break;
		case 3: //done
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		QuickSort();
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		break;
		case 4: //done
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		linear_search();
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		break;
		case 5://done
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		binary_search();
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		break;
		case 6://inte done
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		BST();
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		break;
		case 7: //inte done
		random_array();
		break;
		case 8: // inte done
		worst_array();
		break;
		case 9: //inte done
		print_array();
		break;
		case 10: //inte done
		set_size();
		break;
		case 11: //done
		disp_menu();
		break;
		case 0:
		c = 0;
		break;
		default:
		printf("Invalid Parameter!\n");
		break;
	}
}while(c != 0);
	return 0;
}
