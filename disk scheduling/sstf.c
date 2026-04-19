#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[] = {82,160,53,143,34,16,195};
    int p = 40;
    int s_time = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    int visited[7] = {0};

    for(int i = 0; i < n; i++){
        int min = 100000, index = -1;

        for(int j = 0; j < n; j++){
            if(!visited[j]){
                int dist = abs(arr[j] - p);
                if(dist < min){
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        s_time += min;
        p = arr[index];
    }

    printf("%d ", s_time);
    return 0;
}