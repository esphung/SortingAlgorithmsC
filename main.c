/*

FILENAME:	main.c

PURPOSE:	main file for sorting algorithm basic example
            add step counting instructions at the instruction of comparison, swamping, and additional copying.

AUTHOR:		eric phung

*/

#include "utility.h"
#include "insertionsort.h"
#include "quicksort.h"
#include "mergesort.h"


int main() {

/*    int n,j;// array count, which sorting algo
    printf ("Elements: ");
    if (scanf("%d", &n) == 1)
        printf ("You entered %d\n", n);
    else
        printf ("You failed to enter a number\n");*/

    int n = 10;// size of array

    int a[n];// create empty arrays

    fillArray(a,n);

    // print out original array
    //printf("\nUnsorted array: ");
    //printArray(a,n);

    int steps = 0;
    

    myInsertionSort(a,n,steps);
    myQuickSort(a,n,steps);
    myMergeSort(a,n,steps);

    return 0;
}// end main def