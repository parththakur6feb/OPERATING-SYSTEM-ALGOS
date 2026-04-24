#include <stdio.h>

int main() {
    int at = 0;
    int bt[] = {4, 3, 5, 1};
    int pid[] = {1, 2, 3, 4};
    int pr[] = {3, 1, 4, 2};
    int n = sizeof(bt)/sizeof(bt[0]);
    int ct[n];
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

    for (int i = 0; i < n; i++)
    {
        if (i>n)
        {
            break;
        }else if(i==0){
            ct[i] = bt[i];
        }
        else{
            ct[i] = ct[i-1]+bt[i];
        }
        
        tat[i] = ct[i] - at;        
        wt[i] = tat[i] - bt[i];
          
    }


    printf("PID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at, bt[i], pr[i], ct[i], wt[i], tat[i]);
    }

    return 0;
}