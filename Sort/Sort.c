#include <math.h>

int size;
int a[size]


static void bubble_sort(int a[],int n)
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

static void insertion_sort(int a[], int length){

  for(i=1;i<length;i++){
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


static int Partition(int v[], int a, int b)
{
int pivot, lower, upper, temp;
pivot = v[a];
lower = a + 1;
upper = b;
do
{
while (v[lower] <= pivot && lower <= upper)
lower = lower + 1;
while (v[upper] > pivot && lower <= upper)
upper = upper - 1;
if (lower <= upper)
{
temp = v[lower];
v[lower] = v[upper];
v[upper] = temp;
lower = lower + 1;
upper = upper - 1;
}
}while (lower <= upper);
temp = v[upper];
v[upper] = v[a];
v[a] = temp;
return upper;
}

static void QuickSort(int v[], int a, int b)
{
int k;
if (a < b)
{
k = Partition(v, a, b);
QuickSort(v, a, k-1);
QuickSort(v, k+1, b);
}
}


    struct timeval tv0, tv1;
    struct timezone tzp;
    rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
    //kalla på funktion
    rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
    printf("%d msek\n",difftod(&tv0,&tv1));

static void linear_search(A[], int v, int i){
       A[i] == NULL               ? NULL
     : v == A[i]                  ? printf("The value %d is placed on [%d]", v, A[i])
     :                              b_search(A[],v,++i);
}

static void binary_search(int array, int key, int first, int last, int middle){

   if ( first > last ){
      printf("Not found! %d is not present in the list.\n", key);
      break;
}
     if( first <= last )
   {
      if ( array[middle] < search )
         first = middle + 1;    
      else if ( array[middle] == search ) 
      {
         printf("%d found at location %d.\n", key, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   else{binary_search(array[], key, first, last, middle);}

}

static void random_array(){
  int i, j;
for (i = 0; i < size; ++i)
{
  srand (time(NULL));
  a[i] = rand() % 100;
}
}

static void set_size(int x){
  size = x;
}