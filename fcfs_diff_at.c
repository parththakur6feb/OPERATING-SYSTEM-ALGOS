#include<stdio.h>

int main(){
    int at[] = {0,2,1};
    int bt[] = {4,3,5};
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
        
        tat[i] = ct[i] - at[i];        
        wt[i] = tat[i] - bt[i];        
        printf("%d\n",ct[i]);
        printf("%d\n",tat[i]);
        printf("%d\n",wt[i]);
    }

    return 0;
}