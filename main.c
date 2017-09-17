/*

FILENAME:	main.c

PURPOSE:	main file for sorting algorithm basic example

AUTHOR:		eric phung

*/

#include "utility.h"
#include "insertionsort.h"


//Define developer-configurable array length, static (on the stack)


int main(int argc, char const *argv[]) {
    /* code */
    insertionSort(10);

    printf("HEllo Main\n");
    return 0;
}// end main def