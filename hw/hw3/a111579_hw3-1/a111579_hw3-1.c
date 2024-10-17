#include <stdio.h>
#include <stdlib.h>

int min_operations(int arr[], int n) {
    int operations = 0;
    int max_element = 0;

    // max element 
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // until elements are zero
    while (max_element > 0) {
        int start = -1;
        int end = -1;

        // longest continuous sequence
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                if (start == -1) start = i;
                end = i;
            } else if (end != -1) {
                break;
            }
        }

        if (start != -1) {
            for (int i = start; i <= end; i++) {
                arr[i]--;
            }
            operations++;
        }

        // max_element upload
        max_element = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max_element) {
                max_element = arr[i];
            }
        }
    }

    return operations;
}

int main() {
    int N;
    int arr[N];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
  
    int result = min_operations(arr, N);
    printf("%d\n", result);

    return 0;
}