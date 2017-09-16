/*

FILENAME:	insertionsort.c

PURPOSE:	Insertionsort Example in C language

AUTHOR:		eric phung

*/

#include "mytimer.h"

//Define developer-configurable array length, static (on the stack)
#define ARR_SIZE 1000


int main(int argc, char const *argv[])

{
	// main function
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
	// sorting algorithm variables
	int i = 1;
	int j;
	int steps = 0;
	int x; // swap variable

	// print out original array

	for(int i = 0; i < n; i++) {
		printf("%i ", a[i]);
    }// end print array print out

    // start time
    startTimer();

    // loop thru array until reaches the end

    //int iCounter = 0;
    while(i < n) {

    	// step: compare array size
		steps += 1;
		// sync j with i

	    j = i;

//	    printf("Insertion sort - Initial value of i= %2d, j = %2d\n\n", i, j);
	    // compare a[j-1] < a[j]

	    while((j > 0)&&((a[j-1]) > (a[j]))) {

	    	// (compare n and compare n) compare n
	    	steps += 3;
	        /* swap a[j] and a[j-1] */
	        x = a[j];
	        a[j] = a[j-1];
	        a[j-1] = x;
	        // count steps for swap, copy, copy
	        steps += 3;
	        // recursive i
/*************************************
 * This is the loop line I changed
 *************************************/
	        j = j-1;		//Move the inside index left 1
	        steps++;
	    }// end while j-1 > j

	    // increment i
	    i = i + 1;

	    // steps: addition

	    steps += 1;

    }// end while i is less than length of array

    // end timer
    endTimer();


    // print out stats

    printf("Steps => %i\n", steps);
    printf("Elements => %i\n", n);



	// print out original array

	for(int i = 0; i < n; i++) {
		printf("%i ", a[i]);

    }// end print array print out

    printf("\n");



    // end main
	return 0;

}// end main function def