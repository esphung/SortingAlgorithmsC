/*

FILENAME:	main.c

PURPOSE:	main file for sorting algorithm basic example

            1.       Write your own program in C or C++ and add step counting instructions at the instruction of comparison, swamping, and additional copying.
            2.       Print the sorted results of three algorithms for 100, and 1000 numbers.
            3.       Print the counted steps for sorting 100, 1,000, 5,000 and 10,000 numbers.
            4.       Record the computer times and print them for above running as well.
            5.       Plot the values of counted steps and computer times in a chart and connect them in curves by using Excel or other graph software.

AUTHOR:		eric phung

*/

#include "utility.h"
#include "insertionsort.h"
#include "quicksort.h"
#include "mergesort.h"



int main() {

    FILE *fp = fopen("data.csv", "a");
    WriteHeaders(fp,"name","elements","steps","cycles");// write column headers list


/*    int n,j;// array count, which sorting algo
    printf ("Elements: ");
    if (scanf("%d", &n) == 1)
        printf ("You entered %d\n", n);
    else
        printf ("You failed to enter a number\n");*/


    int num[4] = {100,1000,5000,10000};// different element counts
    int steps = 0;

    for (int i = 0; i < ((sizeof(num)/(sizeof(int)))); ++i) {
        // loop thru array sizes
        int n = num[i];// size of array
        int b[n];// create empty arrays
        
        fillArray(b,n);

        steps = 0;
        

        myInsertionSort(b,n,steps,fp);
        myQuickSort(b,n,steps,fp);
        myMergeSort(b,n,steps,fp);


    }// end for





    return 0;
}// end main def