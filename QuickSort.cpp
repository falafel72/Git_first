#include <stdio.h>

/* Prints an array */
void printArray(int arr[], int len) {
    for(int i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

/* Helper function for swapping two elements in an array. */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Sorts an array with the Quicksort algorithm. */
void quickSort(int arr[], int low, int high) {
    // Only sort if the lower index is lower than the higher index
    if (low < high) {
        // pick a pivot (can be done in many different ways, here we just pick the
        // leftmost index)
        int pivot = arr[low];
         
        // partition: make sure elements smaller than the pivot are on the left and
        // elements larger than the pivot are on the right
        int i = low + 1,j = high;
        while(i < j) {
            // Start from either end of the array (excluding the pivot), and swap 
            // if there is an element smaller than the pivot near the end of the 
            // list and an element larger than the pivot near the beginning of the
            // list
            while(arr[i] <= pivot) i++;
            while(arr[j] > pivot) j--;

            // i and j may have crossed each other, so if they have, don't swap
            if (i < j) {
                swap(&arr[i],&arr[j]);        
            }
        }
        // Swap the pivot with the element at the index of j (this is the element 
        // furthest along the list that is less than or equal to the pivot).
        swap(&arr[j],&arr[low]);
        
        // recursively sort the arrays on the left and right
        quickSort(arr,low,j-1); // don't include the pivot, it is in the correct spot
        quickSort(arr,i,high);
    }
}


int main() {
    int arr[] = {4,1,3,6,8,3,2,9,9,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    printf("Sorted array: \n");
    printArray(arr,size);
}
