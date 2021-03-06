#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
// function to keep time
int startTimer() {
	int time;
    int CPU_time_1 = clock();
    //printf("\nCPU start time is : %d \n", CPU_time_1);
    for(time = 0; time < 150000000; time++);

    return CPU_time_1;
}// end start timer def

int endTimer() {
	// end timer
	int CPU_time_2 = clock();
	//printf("\nCPU end time is : %d\n", CPU_time_2);

	return CPU_time_2;
}// end end timer def

int getClockCycles(int start, int end){
	int cycles = ((end) - (start));
	return cycles;
}

// A utility function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void fillArray(int a[], int n) {
	// random generator seed

	srand(time(NULL));// should only be called once

	// fill array with random ints
	int k;

	for (k = 0; k < n; k++) {//CHANGED THIS TO CONST VALUE
	    a[k] = (rand() % 100);
	}

}

int addStepCount(int a, int b) {
	a = a+b;
	return a;
}

void WriteData(FILE * fp,char name[],int elements,int steps,int cycles) {
    // name, steps,elements,clock cycle time
    fprintf(fp, "%s,",name);
    fprintf(fp, "%i,",elements);
    fprintf(fp, "%i,",steps);
    fprintf(fp, "%i\n",cycles);

    //fprintf(fp, "data2\n");
}

void WriteHeaders(FILE * fp,char name[],char elements[],char steps[],char cycles[]) {
    // name, steps,elements,clock cycle time
    fprintf(fp, "%s,",name);
    fprintf(fp, "%s,",elements);
    fprintf(fp, "%s,",steps);
    fprintf(fp, "%s\n",cycles);

    //fprintf(fp, "data2\n");
}

