#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    float average;
    int sum_greater = 0;
    for (int i = 0; i < n; i++) {
        sum= sum+array[i];
    }
    average = (float)sum / n;
    for (int i = 0; i < n; i++) {
        if (array[i] > average) {
            
            sum_greater += array[i];
        }
    }
    printf("The average of the array elements is: %.2f\n", average);
    printf("sum of elements greater than the average is: %d\n", sum_greater);
    return 0;
}