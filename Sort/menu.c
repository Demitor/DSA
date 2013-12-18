#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Sort.h"
#include "betree.h"

	int *array = NULL, is_created = 0, arr_size;
	struct timeval tv0, tv1;
    struct timezone tzp;
    char menu = 'A';
    int c = -1, rtn;
    int v;

int difftod(struct timeval * tv0, struct timeval * tv1){
	return (tv1->tv_sec - tv0->tv_sec)*1000 + (tv1->tv_usec- tv0->tv_usec)/1000;
}
static void disp_menu_a(){
	printf("\n************************************************************\n");
	printf("*** Welcome to the algorithm efficiency test             ***\n");
	printf("*** 1  : Bubble Sort                                     ***\n");
	printf("*** 2  : Insertion Sort                                  ***\n");
	printf("*** 3  : Quicksort                                       ***\n");
	printf("*** 4  : Linear Search                                   ***\n");
	printf("*** 5  : Binary Search                                   ***\n");
	printf("*** 6  : Switch To Tree Menu                             ***\n");
	printf("*** 7  : Fill Random Case Array                          ***\n");
	printf("*** 8  : Fill Worst Case Array                           ***\n");
	printf("*** 9  : Print Array                                     ***\n");
	printf("*** 10 : Set Size of Array                               ***\n");
	printf("*** 11 : Display Menu                                    ***\n");
	printf("*** 0  : Exit                                            ***\n");
	printf("************************************************************\n");
}
static void disp_menu_b(){
	printf("\n************************************************************\n");
	printf("***                                                      ***\n");
	printf("*** 1  : Add Value To The Tree                           ***\n");
	printf("*** 2  : Search For a Value In The Tree                  ***\n");
	printf("*** 3  : Switch To Array Menu                            ***\n");
	printf("***                                                      ***\n");
	printf("************************************************************\n");
}
static void set_size(){
	free(array);
	arr_size = 0;
    printf("Set x, where 2^x\n");
    scanf("%d",&arr_size);
    arr_size = (int) pow((double)2,(double)arr_size);
    array = malloc(sizeof(int)*arr_size);
    is_created++;
}

int main(int argc, char const *argv[])
{

    disp_menu_a();
    do{
    	if (menu == 'A')
    	{
    	
    scanf("%d", &c);
	switch(c){
		case 1: //done
		if(is_created != 0){
    rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		bubble_sort(array, arr_size);
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
			int j;
			printf("What number would you like to search for?\n");
			scanf("%d", &j);
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		linear_search(array, j, 0);
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
    }
    else{printf("The Array is not yet created!\n");}
		break;
		case 5://done
		if(is_created != 0){
			int key, half;
			half = (arr_size/2);
			printf("What number would you like to search for?\n");
			scanf("%d", &key);
	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		binary_search(array, key, 0, arr_size, half);
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));
    }
    else{printf("The Array is not yet created!\n");}
		break;
		case 6://inte done

		disp_menu_b();
		break;
		case 7: //done
		random_array(array, arr_size);
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
		disp_menu_a();
		break;
		case 0:
		c = 0;
		break;
		default:
		printf("Invalid Parameter!\n");
		break;
	}
	}
	else if (menu == 'B')
	{
		disp_menu_b();
		switch(c){
		case 1: add_r_tree();
		break;
		case 2:
		printf("What number would you like to search for?\n");
		scanf("%d", &v);
		rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
		is_memberb(v);
		rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
		printf("%d msek\n",difftod(&tv0,&tv1));
		break;
		case 3:
		menu = 'A';
		break;
		default:
		printf("Invalid Parameter!\n");
		break;
	}
	}
	else {printf("Oops, something went wrong!\n");}
}while(c != 0);
	return 0;
}
