#include <stdio.h>

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages)/sizeof(pages[0]);

    int frame[3] = {-1, -1, -1};
    int f = 3;

    int i, j, k;
    int hits = 0, faults = 0;

    for(i = 0; i < n; i++) {
        int found = 0;

        // check hit
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        if(!found) {

            // fill empty frame first
            int placed = 0;
            for(j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    frame[j] = pages[i];
                    faults++;
                    placed = 1;
                    break;
                }
            }

            // if no empty frame → apply OPT
            if(!placed) {
                int pos = 0;
                int farthest = -1;

                for(j = 0; j < f; j++) {
                    int next = -1;

                    // find next use of this page
                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == pages[k]) {
                            next = k;
                            break;
                        }
                    }

                    // if never used again → best to replace
                    if(next == -1) {
                        pos = j;
                        break;
                    }

                    // choose farthest future use
                    if(next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }

                frame[pos] = pages[i];
                faults++;
            }
        }

        for(j = 0; j < f; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nHits = %d", hits);
    printf("\nMisses = %d", faults);

    printf("\nHit Ratio = %.2f", (float)hits/n);
    printf("\nMiss Ratio = %.2f\n", (float)faults/n);

    return 0;
}