#include <stdio.h>

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages)/sizeof(pages[0]);

    int frame[3] = {-1, -1, -1};
    int time[3] = {0, 0, 0};
    int f = 3;

    int i, j, pos, min;
    int counter = 0;
    int hits = 0, faults = 0;

    for(i = 0; i < n; i++) {
        int flag = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                hits++;
                counter++;
                time[j] = counter;
                break;
            }
        }

        if(flag == 0) {
            pos = 0;
            min = time[0];

            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }

        for(j = 0; j < f; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Hits = %d", hits);
    printf("\nTotal Misses = %d", faults);

    float hit_ratio = (float)hits / n;
    float miss_ratio = (float)faults / n;

    printf("\nHit Ratio = %.2f", hit_ratio);
    printf("\nMiss Ratio = %.2f\n", miss_ratio);

    return 0;
} 