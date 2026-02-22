#include <stdio.h>

int main() {

    int n = 5;

    // Arrival Time and Burst Time
    int AT[5] = {0, 1, 2, 3, 4};
    int BT[5] = {5,7,6,2,4};

    int CT[5], TAT[5], WT[5];

    float avgTAT = 0, avgWT = 0;


    // Completion Time calculation (FCFS)
    CT[0] = AT[0] + BT[0];

    for(int i = 1; i < n; i++) {
        if(CT[i-1] > AT[i])
            CT[i] = CT[i-1] + BT[i];
        else
            CT[i] = AT[i] + BT[i];
    }

    // Calculate TAT and WT
    for(int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        avgTAT += TAT[i];
        avgWT += WT[i];
    }

    avgTAT = avgTAT / n;
    avgWT = avgWT /n;

    // Output
    printf("\nPN\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage TAT = %.2f\n", avgTAT);
    printf("Average WT  = %.2f\n", avgWT);

    

    return 0;
}