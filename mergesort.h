/*
FIleftArrayENAME:	mergesort.c
AUTHOR:		eric phung
PURPOSE:	mergesort example in C
DATE:		2017.09.15
*/
#include <stdio.h>

int startTimer();
int endTimer();
void fillArray(int a[],int n);
void printArray(int a[],int n);
int getClockCycles(int start, int end);
void swap(int* a, int* b);
int addStepCount(int a, int b);
void WriteData(FILE * fp,char name[],int elements,int steps,int cycles);

int merge(int arr[], int l, int m, int r, int steps) {

	// vars
	int i;
	int j;
	int k;
    int n1 = (m - l + 1);
    int n2 =  (r - m);

    // create temp arrays
    int leftArray[n1];
    int R[n2];

    // copy arrays
    for (i = 0; i < n1; i++)
        leftArray[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;// first subarray
    j = 0;// second subarray
    k = l;// merged subarray
    while (i < n1 && j < n2) {
        
        steps = addStepCount(steps,3);// comparison,comparison,comparison

        if (leftArray[i] <= R[j]) {
            arr[k] = leftArray[i];
            steps = addStepCount(steps,1);// swap
            i++;
            steps = addStepCount(steps,1);// comparison
        }
        else {
            arr[k] = R[j];
            j++;
            steps = addStepCount(steps,1);// swap
        }
        k++;
    }

    /* Copy the remaining elements of leftArray[], if there
       are any */
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
        steps = addStepCount(steps,1);// comparison
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        steps = addStepCount(steps,1);// comparison
    }
    return steps;


}// end merge def

 
int mergeSort(int myArray[], int left, int right, int steps) {
    if (left < right) {

        steps = addStepCount(steps,1);// comparison

        int median = (left)+(right-left)/2;// pick value to partition at

        // first half, second half
        steps = mergeSort(myArray, left, median, steps);
        steps = mergeSort(myArray, (median+1), right, steps);
 
 		// combine sorted halves
        steps = merge(myArray, left, median, right, steps);
    }
    return steps;
}

/* Driver program to test above functions */
int myMergeSort(int a[], int n, int steps, FILE * fp){

    // start time
    int start;
    start = startTimer();
 
    //printf("Given array is \n");
    //printArray(arr, n);
 
    steps = mergeSort(a, 0, n - 1, steps);

    // end time
    int end;
    end = endTimer();


    int cycles = getClockCycles(start, end);

    WriteData(fp,"mergesort",n,steps,cycles);

    if (n <= 1000) {
    printf("Merge Sort => \n");
    printArray(a, n);
    printf("Steps: %i\n", steps);
    printf("Elements: %i\n", n);
    printf("Cycles: %i\n", cycles);

    } else {
        printf("Merge Sort => \n");
        //printArray(a, n);
        printf("Steps: %i\n", steps);
        printf("Elements: %i\n", n);
        //printf("Cycles: %i\n", cycles);

    }

    return 0;
}// end main def