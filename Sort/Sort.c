#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "betree.h"
//#define size 1024


static void bubble_sort(int a[], int size)
{
int i,j,k,temp;
  /* printf("\nUnsorted Data:");
    for(k=0;k<n;k++)
         printf("%5d",a[k]);*/
    for(i=1;i< size;i++)
    {
         for(j=0;j< size-1;j++)
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
  int i, temp, j;
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


static int Partition(int a[], int c, int b)
{
int pivot, lower, upper, temp;
pivot = a[c];
lower = c + 1;
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
temp = a[upper];
a[upper] = a[c];
a[c] = temp;
return upper;
}

static void QuickSort(int a[], int c, int b)
{
int k;
if (c < b)
{
k = Partition(a, c, b);
QuickSort(a, c, k-1);
QuickSort(a, k+1, b);
}
}


static void linear_search(int a[], int v, int i){
       a[i] == NULL               ? NULL
     : v == a[i]                  ? printf("The value %d is placed on [%d]", v, a[i])
     :                              linear_search(a ,v,++i);
}

static void binary_search(int a[], int key, int first, int last, int middle){

   if ( first > last ){
      printf("Not found! %d is not present in the list.\n", key);
}
     if( first <= last )
   {
      if ( a[middle] < key )
         first = middle + 1;    
      else if ( a[middle] == key ) 
      {
         printf("%d found at location %d.\n", key, middle+1);
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   else{binary_search(a, key, first, last, middle);}

}

static void random_array(int a[], int size){
  int i;
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

 static void add_r_tree(){
  int i, size, v;
  printf("Set x, where 2^x\n");
  scanf("%d", &size);
  size = (int) pow((double)(sizeof(int)*3),(double)size);
  for (i = 0; i < size; ++i)
  {
    srand (time(NULL));
    v = rand() % 100 + 1;
    add(v);
  }
 }