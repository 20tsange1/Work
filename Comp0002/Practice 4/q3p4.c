#include <stdio.h>

int main() {
    int arr_count = 5;
    int arr[5] = {12,22,5,298,23985};
    int flag = 1;
    int i = 0;
    int temp = arr[0];
    while (flag > 0) {
        flag = 0;
        i = 0;
        while (i < arr_count-1) {
            printf("%i, %i\n", arr[i], arr[i+1]);
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag++;
            }
            i++;
            printf("%i\n", i);
        }
        
    }

    
    printf("%i %i", arr[0]+arr[1]+arr[2]+arr[3], arr[4]+arr[3]+arr[2]+arr[1]);
}