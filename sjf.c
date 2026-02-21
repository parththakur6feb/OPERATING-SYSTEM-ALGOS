#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void bubblesort(int arr[], int pid[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                int temp1 = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp1;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    int at = 0;
    int pid[] = {1, 2, 3};
    int bt[] = {4, 2, 5};
    int n = sizeof(bt) / sizeof(bt[0]);
    int ct[n];
    int tat[n];
    int wt[n];
    bubblesort(bt, pid, n);


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


        // time_t current_time = time(NULL); 
        // printf("%s", ctime(&current_time));

        printf("\nProcess id ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ",pid[i]);
        }
        printf("\narival time ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ",at);
        }
        printf("\nbust time ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ",bt[i]);
        }
        printf("\ncompletion time ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ",ct[i]);
        }
        printf("\nturn around time ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ",tat[i]);
        }
        printf("\nwaiting time ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ",wt[i]);
        }

    // for (int i = 0; i < 3; i++)
    // {
    //     // printf("%d", bt[i]);
    //     printf("%d", pid[i]);
    // }

    return 0;
}