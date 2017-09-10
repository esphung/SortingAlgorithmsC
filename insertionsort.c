/*
FILENAME:	insertionsort.c
PURPOSE:	Insertionsort Example in C language
AUTHOR:		eric phung
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// function to keep time
void startTimer()
{
	int time;
    int CPU_time_1 = clock();
    printf("\nCPU start time is : %d \n", CPU_time_1);
    for(time = 0; time < 150000000; time++);

}// end start timer def

int main(int argc, char const *argv[])
{
	// main function

	// create empty array
	int a[100];
	int n = (sizeof(a))/(sizeof(int));

	// random generator seed
	srand(time(NULL));   // should only be called once

	// fill array with random ints
	int k;
	for (k = 0; k < 100; k++) {
	    a[k] = (rand() % 10);
	}

	// sorting algorithm variables
	int i = 1;
	int j;
	int steps = 0;
	int x; // swap variable


	// print out original array
	for(int i = 0; i < n; i++)
	{
		printf("%i ", a[i]);

    }// end print array print out

    // start time
    startTimer();
    
    // loop thru array until reaches the end
    while(i < n) {

    	// step: compare array size
		steps += 1;

		// sync j with i
	    j = i;

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
	        i = a[j-1];

	        // steps: copy
	        steps++;

	    }// end while j-1 > j

	    // increment i
	    i = i + 1;

	    // steps: addition
	    steps += 1;

    }// end while i is less than length of array

    // end timer
    int CPU_time_2 = clock();
    printf("\nCPU end time is : %d\n", CPU_time_2);

    // print out stats
    printf("Steps => %i\n", steps);
    printf("Elements => %i\n", n);

	// print out original array
	for(int i = 0; i < n; i++)
	{
		printf("%i ", a[i]);

    }// end print array print out
    printf("\n");

    // end main
	return 0;
}// end main function def