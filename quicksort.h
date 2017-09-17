/*

FILENAME:	quicksort.c

PURPOSE:	quicksort Example in C language

AUTHOR:		eric phung

*/

//#include "utility.h"
#include <stdio.h>
//Define developer-configurable array length, static (on the stack)
//#define ARR_SIZE 100
int startTimer();
int endTimer();
void fillArray(int a[],int n);
void printArray(int a[],int n);
int getClockCycles(int start, int end);
void swap(int* a, int* b);
int addStepCount(int a, int b);
void WriteData(FILE * fp,char name[],int elements,int steps,int cycles);


/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high, int steps) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    //steps+=1;//swap
 
    for (int j = low; j <= high- 1; j++) {

    	//steps+=1;// swap

        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            //steps+=1;// swap
        }
    }
    swap(&arr[i + 1], &arr[high]);
    //steps+=1;// swap

    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
int quickSort(int arr[], int low, int high, int steps) {

    if (low < high){
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high, steps);
        //steps += 4;
        steps = addStepCount(steps,4);// swap,swap,swap,swap
 
        // Separately sort elements before
        // partition and after partition
        steps = quickSort(arr, low, pi - 1, steps);
        steps = quickSort(arr, pi + 1, high, steps);
    }
    return steps;
}
 

// Driver program to test above functions
int myQuickSort(int a[],int n, int steps, FILE *fp) {

	int start = startTimer();

    steps = quickSort(a, 0, n-1, steps);

    int end = endTimer();


    int cycles = getClockCycles(start, end);

    WriteData(fp,"quicksort",n,steps,cycles);

    if (n <= 1000) {
	printf("Quick Sort => \n");
    //printArray(a, n);
    printf("Steps: %i\n", steps);
    printf("Elements: %i\n", n);
    printf("Cycles: %i\n", cycles);

    } else {
    	printf("Quick Sort => \n");
    	//printArray(a, n);
    	printf("Steps: %i\n", steps);
    	printf("Elements: %i\n", n);
    	//printf("Cycles: %i\n", cycles);

    }


    return 0;
}
