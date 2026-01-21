#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int arr[30], key1, key2, status;
    pid_t p1, p2;
    srand(time(NULL));
    printf("Array: ");
    for (int i = 0; i < 30; i++) {
        arr[i] = rand() % 50 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n\nEnter Key 1 and Key 2: ");
    scanf("%d %d", &key1, &key2);

    // Child 1
    p1 = fork();
    if (p1 == 0) {
        int found = 0;
        for (int i = 0; i < 30; i++) {
            if (arr[i] == key1) {
                found = 1;
                break; 
            }
        }
        exit(found); 
    }

    waitpid(p1, &status, 0);
    int res1 = WEXITSTATUS(status);

    // Child 2
    p2 = fork();
    if (p2 == 0) {
        int found = 0;
        for (int i = 0; i < 30; i++) {
            if (arr[i] == key2) {
                found = 1;
                break; 
            }
        }
        exit(found); 
    }

    waitpid(p2, &status, 0);
    int res2 = WEXITSTATUS(status);

    if (p1 > 0 && p2 > 0) {
        printf("\nParent Process:\n");
        printf("Key %d was %s found in the array.\n", key1, res1 ? "" : "not");
        printf("Key %d was %s found in the array.\n", key2, res2 ? "" : "not");
    }

    return 0;
}