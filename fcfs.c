#include<stdio.h>

int main(){
    int at = 0;
    int bt[] = {4,3,5};
    int pid[] = {1,2,3};
    int n = sizeof(bt)/sizeof(bt[0]);
    int ct[n];
    int tat[n];
    int wt[n];

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
        // printf("%d\n",ct[i]);
        // printf("%d\n",tat[i]);
        // printf("%d\n",wt[i]);
    }

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

    return 0;
}