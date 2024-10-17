#include <stdio.h>

int main(){
    int N;
    int arr[1000];
    int temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
  
  	// even
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - i - 1; j++){
            if (arr[j] % 2 == 0){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
  
  	// even
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - i - 1; j++){
            if(arr[j] % 2 == 0 && arr[j + 1] % 2 == 0){
                if (arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
  
  	// odd
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - i - 1; j++){
            if(arr[j] % 2 != 0 && arr[j + 1] % 2 != 0){
                if (arr[j] < arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("%d", arr[i]);
        if(i < N-1){
            printf(" ");
        }
    }
    return 0;
}