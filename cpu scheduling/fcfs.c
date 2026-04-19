#include <stdio.h>

int main()
{
    int at = 0;
    int bt[] = {4, 3, 5};
    int pid[] = {1, 2, 3};
    int n = sizeof(bt) / sizeof(bt[0]);
    int ct[n];
    int tat[n];
    int wt[n];

    for (int i = 0; i < n; i++)
    {
        if (i > n)
        {
            break;
        }
        else if (i == 0)
        {
            ct[i] = bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = ct[i] - at;
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at, bt[i], ct[i], wt[i], tat[i]);
    }
    
    return 0;
}