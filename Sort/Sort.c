#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define size 1024
int a[size]


static void bubble_sort(int a[])
{
int i,j,k,temp;
  /* printf("\nUnsorted Data:");
    for(k=0;k<n;k++)
         printf("%5d",a[k]);*/
    for(i=1;i< n;i++)
    {
         for(j=0;j< n-1;j++)
         if(a[j]>a[j+1])
               {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
               }
  /*  printf("\nAfter pass %d : ",i);
        for(k=0;k< n;k++)
             printf("%5d",a[k]);*/
    }
}

static void insertion_sort(int a[], int size){

  for(i=1;i<size;i++){
      temp=a[i];
      j=i-1;
      while((temp<a[j])&&(j>=0)){
      a[j+1]=a[j];
          j=j-1;
      }
      a[j+1]=temp;
  }

 /* printf("After sorting: ");
  for(i=0;i<s;i++)
      printf(" %d",a[i]);*/
}


static int Partition(int a, int b)
{
int pivot, lower, upper, temp;
pivot = a[a];
lower = a + 1;
upper = b;
do
{
while (a[lower] <= pivot && lower <= upper)
lower = lower + 1;
while (a[upper] > pivot && lower <= upper)
upper = upper - 1;
if (lower <= upper)
{
temp = a[lower];
a[lower] = a[upper];
a[upper] = temp;
lower = lower + 1;
upper = upper - 1;
}
}while (lower <= upper);
temp = v[upper];
a[upper] = a[a];
a[a] = temp;
return upper;
}

static void QuickSort(int a[], int c, int b)
{
int k;
if (c < b)
{
k = Partition(c, b);
QuickSort(c, k-1);
QuickSort(k+1, b);
}
}


  /*  struct timeval tv0, tv1;
    struct timezone tzp;
    rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
    //kalla på funktion
    /*rtn = gettimeofday(&tv1, &tzp);*/ /* read time T1 */
    /*printf("%d msek\n",difftod(&tv0,&tv1));*/

static void linear_search(int a[], int v, int i){
       a[i] == NULL               ? NULL
     : v == a[i]                  ? printf("The value %d is placed on [%d]", v, a[i])
     :                              linear_search(int a[] ,v,++i);
}

static void binary_search(int key, int first, int last, int middle){

   if ( first > last ){
      printf("Not found! %d is not present in the list.\n", key);
      break;
}
     if( first <= last )
   {
      if ( a[middle] < search )
         first = middle + 1;    
      else if ( a[middle] == search ) 
      {
         printf("%d found at location %d.\n", key, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   else{binary_search(a[], key, first, last, middle);}

}

static void random_array(int a[]){
  int i, j;
for (i = 0; i < size; ++i)
{
  srand (time(NULL));
  a[i] = rand() % 100;
}
}


 static void worst_array(int array[], int size){
  int i, j = size;
  for (i = 0; i < size; ++i)
  {
    array[i] = j;
    j--;
  }

 }

 static void print_array(int array[], int size){
  int i = 0;
  while(i < size){
    printf("%d\n", array[i]);
    i++;
  }
 }