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


static long Partition(long v[], long a, long b)
{
long pivot, lower, upper, temp;
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

static void QuickSort(long v[], long a, long b)
{
long k;
if (a < b)
{
k = Partition(v, a, b);
QuickSort(v, a, k-1);
QuickSort(v, k+1, b);
}
}