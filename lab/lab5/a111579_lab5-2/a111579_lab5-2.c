#include <stdio.h>

void rearrangeArray(int *arr, int n);

int main() {
    int n;
    scanf("%d", &n); 

    int *arr = (int *)malloc(n * sizeof(int));  
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    rearrangeArray(arr, n); 

    
    free(arr); 
    return 0;
}

void rearrangeArray(int *arr, int n) {
    int *left = arr;        
    int *right = arr + n - 1; 
    while (left < right) {
        while (left < right && *left % 2 != 0) { // odd left
            left++;
        }
        while (left < right && *right % 2 == 0) { // even right
            right--;
        }
        if (left < right) { //swap
            int temp = *left;
            *left = *right;
            *right = temp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}