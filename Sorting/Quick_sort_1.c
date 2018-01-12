 #include<stdio.h>


int interchange=0,count=0;

int quicksort(int [10],int,int);

int main(){
  int x[20],size,i;
  //int interchange;

  printf("Enter size of the array: ");
  scanf("%d",&size);

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&x[i]);

  interchange=quicksort(x,0,size-1);

  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf(" %d",x[i]);

  printf("\nNumber of Interchange to sort the array = %d\n",interchange);

  return 0;
}

int quicksort(int x[],int first,int last){
    int pivot,j,temp,i;
    //static int interchange;

     //printf("\nfunction called = %d\n",++count);
     if(first<last){
        //printf("\nIn main if\n");
         pivot=first;
         i=first;
         j=last;

         while(i<j){
                //printf("\nIn main while\n");
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
                  interchange++;
                printf("\n...Interchange = %d\n",interchange);
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         interchange++;
                printf("\nInterchange = %d\n",interchange);
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);
    }
    //printf("\nfunction called again\n");
    return interchange;
}


//Sorting Algorithm
/*function quicksort(array)
    if length(array) > 1
        pivot := select any element of array
        left := first index of array
        right := last index of array
        while left ≤ right
            while array[left] < pivot
                left := left + 1
            while array[right] > pivot
                right := right - 1
            if left ≤ right
                swap array[left] with array[right]
                left := left + 1
                right := right - 1
        quicksort(array from first index to right)
        quicksort(array from left to last index)
*/
