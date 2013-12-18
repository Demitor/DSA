#include "Sort.h"
#include <stdio.h>
#include <sys/time.h>
	int *array = NULL, is_created = 0, arr_size;
	struct timeval tv0, tv1;
    struct timezone tzp;
    int c = -1;
static void disp_menu_a(){
	printf("\n************************************************************\n");
	printf("*** Welcome to the algorithm efficiency test             ***\n");
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
 
static int set_size(){
	free(array);
	arr_size = 0;
    printf("Set x, where 2^x\n");
    scanf("%d",&arraysize);
    arr_size = (int) pow((double)2,(double)arraysize);
    array = malloc(sizeof(int)*arraysize);
    is_created++;
}

int int main(int argc, char const *argv[])
{

    disp_menu_a();
    do{
    scanf("%d", &c);
	switch(c){
		case 1: //done
		if(is_created != 0){
    rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		bubble_sort(array);
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		}
		else{printf("The Array is not yet created!\n");}
		break;
		case 2: //done
		if(is_created != 0){
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		insertion_sort(array, arr_size);
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
		}
		else{printf("The Array is not yet created!\n");}
		break;
		case 3: //done
		if(is_created != 0){
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		QuickSort(array, 0, arr_size-1);
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
    }
    else{printf("The Array is not yet created!\n");}
		break;
		case 4: //done
		if(is_created != 0){
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		linear_search(array, /*värdet vi vill leta efter*/, 0);
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
    }
    else{printf("The Array is not yet created!\n");}
		break;
		case 5://done
		if(is_created != 0){
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		binary_search();//INPARAMETRAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
    }
    else{printf("The Array is not yet created!\n");}
		break;
		case 6://inte done
		if(is_created != 0){
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		BST();
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
    }
    else{printf("The Array is not yet created!\n");}
		break;
		case 7: //done
		random_array(array);
		break;
		case 8: //done
		worst_array(array, arr_size);
		break;
		case 9: // done
		if(is_created != 0){
		print_array(array, arr_size);
	}else{printf("The Array is Empty!\n");}
		break;
		case 10: //done
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
