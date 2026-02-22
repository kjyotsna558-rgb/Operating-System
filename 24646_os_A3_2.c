#include <stdio.h>

#define N 5

int main() {

    int at[N]  = {0,0,0,0,0};
    int bt1[N] = {5,7,6,8,5};
    int io[N]  = {2,2,3,1,2};
    int bt2[N] = {3,2,4,2,5};

    int pct[N], ct[N];
    int i;

    // Calculate PCT
    for(i = 0; i < N; i++) {
        if(i == 0)
            pct[i] = bt1[i] + io[i];
        else
            pct[i] = pct[i-1] + bt1[i] + io[i];
    }

    // Calculate CT
    for(i = 0; i < N; i++) {
        if(i == 0) {
            ct[i] = pct[i] + bt2[i];
        }
        else {
            int start_time;

            if(ct[i-1] > pct[i])
                start_time = ct[i-1];
            else
                start_time = pct[i];

            ct[i] = start_time + bt2[i];
        }
    }

    printf("PN\tAT\tBT1\tIO\tBT2\tPCT1\tCT\n");

    for(i = 0; i < N; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt1[i], io[i], bt2[i], pct[i], ct[i]);
    }

    return 0;
}