#include<stdio.h>

int main(){
    int at = 0;
    int bt[] = {4,3,5,1};
    int pid[] = {1,2,3,4};
    int tq = 2;
    int n = sizeof(bt)/sizeof(bt[0]);
    int ct[n];
    int tat[n];
    int wt[n];
    int bt2 [n];
    int time= 0;
    int processcomp = 0;
    for(int i = 0; i < n; i++){
        bt2[i] = bt[i];
    }

    while(processcomp < n){
        for(int i = 0; i < n; i++){
            if(bt2[i] > 0){
                if(bt2 [i] > tq){
                    time = time +  tq;
                    bt2[i] = bt2[i] -  tq;
                }
                else{
                    time = time + bt2[i];
                    ct[i] = time;
                    bt2[i] = 0;
                    processcomp++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at;
        wt[i] = tat[i] - bt[i];
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