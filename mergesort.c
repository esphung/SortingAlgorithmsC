/*
FILENAME:	mergesort.c
AUTHOR:		eric phung
PURPOSE:	mergesort example in C
DATE:		2017.09.15
*/
#include "mytimer.h"
#include "utility.h"

void merge(int arr[], int l, int m, int r) {

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
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }


}// end merge def

 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

void MergeSort(int arr[],int l,int r) {
	
	//merge sort algorithm
	if (r > l) {
		
		// find the middle point to divide the array into two halves 
		int m = ((l+r)/(2));

		// 2. call mergeSort for first half
		mergeSort(arr,l,m);

		// 3. Call mergeSort for second half:
		mergeSort(arr,(m+1),r);

		//  4. Merge the two halves sorted in step 2 and 3:
		merge(arr,l,m,r);



		
	}// end if

	
}// end mergesort def



/* Driver program to test above functions */
int main()
{
	//printf("\n================================\n");
	//start timer
	startTimer();

	// create empty array
	int arr[100];

	// random generator seed
	srand(time(NULL));   // should only be called once

	// fill array with random ints
	int k;
	for (k = 0; k < (sizeof(arr))/(sizeof(int)); k++) {
	    arr[k] = (rand() % 10);
	}
    
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    // end timer
	endTimer();
    return 0;
}// end main def