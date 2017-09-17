/*
FILENAME:	mergesort.c
AUTHOR:		eric phung
PURPOSE:	mergesort example in C
DATE:		2017.09.15
*/
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

int merge(int arr[], int l, int m, int r, int steps) {

	// function variables
	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        steps = addStepCount(steps,3);// comparison,comparison,comparison
        if (L[i] <= R[j]) {
            arr[k] = L[i];
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

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
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

 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
int mergeSort(int arr[], int l, int r, int steps) {
    if (l < r) {

        steps = addStepCount(steps,1);
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        steps = mergeSort(arr, l, m, steps);
        steps = mergeSort(arr, m+1, r, steps);
 
        steps = merge(arr, l, m, r, steps);
    }
    return steps;
}
/*
void MergeSort(int arr[],int l,int r,int steps) {
	
	//merge sort algorithm
	if (r > l) {
		
		// find the middle point to divide the array into two halves 
		int m = ((l+r)/(2));

		// 2. call mergeSort for first half
		mergeSort(arr,l,m,steps);

		// 3. Call mergeSort for second half:
		mergeSort(arr,(m+1),r,steps);

		//  4. Merge the two halves sorted in step 2 and 3:
		merge(arr,l,m,r);



		
	}// end if

	
}// end mergesort def
*/


/* Driver program to test above functions */
int myMergeSort(int a[], int n, int steps, FILE * fp){
    // start time
    int start;
    start = startTimer();

    //int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    //printf("Given array is \n");
    //printArray(arr, n);
 
    steps = mergeSort(a, 0, n - 1, steps);


    int end;
    end = endTimer();


    int cycles = getClockCycles(start, end);

    WriteData(fp,"mergesort",n,steps,cycles);

    if (n <= 1000) {
    printf("Merge Sort => \n");
    //printArray(a, n);
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