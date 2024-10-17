#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[5] = {10, 20, 30, 40, 50}; 
    int *pointer = arr;        // Pointer -> arr
    int *start = arr;      
    int size = 5;  
    int i; 

    while (scanf("%d", &i) != EOF) {
        switch (i) {
            case 1:  // Add one
                if (pointer >= start && pointer < start + size) {
                    (*pointer)++;
                } else {
                    printf("Out of bounds\n");
                }
                break;
            case 2:  // Subtract one
                if (pointer >= start && pointer < start + size) {
                    (*pointer)--;
                } else {
                    printf("Out of bounds\n");
                }
                break;
            case 3:  // Next one
                pointer++;
                break;
            case 4:  // Previous one
                pointer--;
                break;
            case 5:  // Print 
                if (pointer >= start && pointer < start + size) {
                    printf("%d\n", *pointer);
                } else {
                    printf("Out of bounds\n");
                }
                break;
            case 6:  // Calloc size
                {
                    int v; 
                    if (scanf("%d", &v) == 1) {
                        int *new_arr = (int *)calloc(v, sizeof(int));
                        pointer = new_arr;
                        start = new_arr;
                        size = v; 
                    } else {
                        printf("Undefined operation\n");
                    }
                }
                break;
            default:
                printf("Undefined operation\n");
                break;
        }
    }
    return 0;
}
