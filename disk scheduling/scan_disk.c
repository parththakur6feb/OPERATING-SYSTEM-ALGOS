#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {82,160,53,143,34,16,195};
    int disk_size = 199;
    int p = 40;
    int split_index = 0;
    int s_time = 0;
    int c_pos = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for (int i = 0; i < n; i++){
        if(arr[i] > p){
            split_index = i;
            // printf("%d,", split_index);
            break;
        }
    }

    for (int i = split_index; i < n; i++){
        c_pos = abs(arr[i] - p);
        s_time += c_pos;
        p = arr[i];
    }
    
    c_pos = abs(disk_size - p);
    s_time += c_pos;
    p = disk_size;

    for (int i = split_index-1; i >= 0; i--)
    {
        c_pos = abs(arr[i] - p);
        s_time += c_pos;
        p = arr[i];
    }
    

    printf("%d ",s_time);
    return 0;
}