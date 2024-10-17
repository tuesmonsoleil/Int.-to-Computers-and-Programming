#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int arr[1000];  
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array
    qsort(arr, N, sizeof(int), compare);
    
    int isPseudoSymmetric = 1, setMiddle = 0;  
    
    for (int i = 0; i + 1 < N; i += 2) {
        if (abs(arr[i] - arr[i + 1]) > M) {
            if(!setMiddle && N%2){
                setMiddle = 1;
                //arr[i+1] = arr[i];
                i-=1;
            }else{
                isPseudoSymmetric = 0;
                break;
            }
        }
    }
    
    if (isPseudoSymmetric) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}