#include <stdio.h>
#include <stdlib.h>

int* sort(int* n, int size) {
    int *newnums = malloc(size * sizeof(int));
    newnums = n;

    int temp = newnums[0];

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (newnums[i] > newnums[j]) {
                temp = newnums[i];
                newnums[i] = newnums[j];
                newnums[j] = temp;
            }
        }
    }

    return newnums;

}

int main() {
    int nums[] = {6, 1, 7, 3, 2, 4, 9, 5};

    int *sortednums = sort(nums, sizeof(nums)/sizeof(nums[0]));

    for (int x = 0; x < sizeof(nums)/sizeof(nums[0]); x++) {
        printf("%i\n", sortednums[x]);
    }

    

    return 0;
}