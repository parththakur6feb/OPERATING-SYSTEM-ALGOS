#include <stdio.h>

int main()
{
    int at[] = {0, 2, 1};
    int bt[] = {4, 3, 5};
    int n = sizeof(bt) / sizeof(bt[0]);
    int ct[n];
    int tat[n];
    int wt[n];

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(at[j] > at[j + 1])
            {
                int temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ct[i] = bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        // printf("%d\n", ct[i]);
        // printf("%d\n", tat[i]);
        // printf("%d\n", wt[i]);

    }

    printf("\narival time ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", at[i]);
    }
    printf("\nbust time ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", bt[i]);
    }
    printf("\ncompletion time ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ct[i]);
    }
    printf("\nturn around time ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tat[i]);
    }
    printf("\nwaiting time ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", wt[i]);
    }

    return 0;
}