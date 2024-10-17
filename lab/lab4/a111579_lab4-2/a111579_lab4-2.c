#include <stdio.h>

// min in array
int find_min(int arr[], int left, int right) {
    int min = arr[left];
    for (int i = left; i <= right; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// recursive function
int min_operations(int arr[], int left, int right) {
    // when the interval is empty
    if (left > right) {
        return 0;
    }

    // min in the segment
    int min_value = find_min(arr, left, right);

    // subtract all min
    for (int i = left; i <= right; i++) {
        arr[i] -= min_value;
    }

    // count operations
    int operations = min_value;

    // split array
    int prev = left;
    for (int i = left; i <= right; i++) {
        if (arr[i] == 0) {
            operations += min_operations(arr, prev, i - 1);
            prev = i + 1;
        }
    }

    // solve for the remaining part after the last zero
    operations += min_operations(arr, prev, right);

    return operations;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
  
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
  
    int result = min_operations(arr, 0, N - 1);
    printf("%d\n", result);

    return 0;
}
