#include <stdio.h>

int main() {
    int at = 0;
    int bt[] = {4, 3, 5, 1};
    int pid[] = {1, 2, 3, 4};
    int pr[] = {3, 1, 4, 2};
    int n = sizeof(bt)/sizeof(bt[0]);
    int wt[n];
    int tat[n];

    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }


    printf("PID\tAT\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at, bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}