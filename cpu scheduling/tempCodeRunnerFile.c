int main(){
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], wt[n], tat[n], ct[n];
    for (i = 0; i < n; i++)
    {
        at[i] = 0;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    ct[0] = bt[0];
    wt[0] = 0;
    tat[0] = ct[0] - at[0];
    for (i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    return 0;
}
