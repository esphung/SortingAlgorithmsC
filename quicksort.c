/*

FILENAME:	quicksort.c

PURPOSE:	quicksort Example in C language

AUTHOR:		eric phung

*/

#include "mytimer.h"
#include "utility.h"

//Define developer-configurable array length, static (on the stack)
#define ARR_SIZE 100


/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
int quickSort(int arr[], int low, int high, int steps) {
	
	steps++;

    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
        steps += 4;
 
        // Separately sort elements before
        // partition and after partition
        steps = quickSort(arr, low, pi - 1, steps);
        steps = quickSort(arr, pi + 1, high, steps);
    }
    return steps;
}
 

// Driver program to test above functions
int main() {

   	// create empty array
	int a[ARR_SIZE];//CHANGED THIS TO CONST VALUE

	int n = (sizeof(a))/(sizeof(int));
	// random generator seed

	srand(time(NULL));// should only be called once

	// fill array with random ints
	int k;

	for (k = 0; k < ARR_SIZE; k++) {//CHANGED THIS TO CONST VALUE
	    a[k] = (rand() % 100);
	}

	printf("\nUnsorted array: ");
    printArray(a, n);
    
    // step counter
	int steps = 0;


    steps = quickSort(a, 0, n-1, steps);

    printf("\nSorted array: ");
    printArray(a, n);

    printf("Steps: %i\n", steps);
    printf("Elements: %i\n", n);
    return 0;
}
