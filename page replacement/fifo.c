#include <stdio.h>

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages)/sizeof(pages[0]);

    int frame[3] = {-1, -1, -1};
    int f = 3;

    int i, j, k = 0, flag;
    int hits = 0, miss = 0;

    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                hits++;
                break;
            }
        }

        if(flag == 0) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            miss++;
        }

        for(j = 0; j < f; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Hits = %d", hits);
    printf("\nTotal Misses = %d", miss);

    float hit_ratio = (float)hits / n;
    float miss_ratio = (float)miss / n;

    printf("\nHit Ratio = %.2f", hit_ratio);
    printf("\nMiss Ratio = %.2f\n", miss_ratio);

    return 0;
}