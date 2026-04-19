#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[] = {82,160,53,143,34,16,195};
    int p = 40;
    int s_time = 0;
    int c_pos = 0;
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i < n; i++){
        c_pos = abs(arr[i] - p);
        s_time += c_pos;   
        p = arr[i];
    }

    printf("%d ",s_time);
    return 0;
}