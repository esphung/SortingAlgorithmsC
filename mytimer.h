#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
// function to keep time
void startTimer() {
	int time;
    int CPU_time_1 = clock();
    printf("\nCPU start time is : %d \n", CPU_time_1);
    for(time = 0; time < 150000000; time++);

}// end start timer def

void endTimer() {
	// end timer
	int CPU_time_2 = clock();
	printf("\nCPU end time is : %d\n", CPU_time_2);

}// end end timer def