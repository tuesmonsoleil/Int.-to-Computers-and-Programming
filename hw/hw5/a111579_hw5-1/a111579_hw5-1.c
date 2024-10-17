#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseMat(int m, int n, int mat[m][n]) {
    int total = m * n; 
    int half = total / 2;

    for (int i = 0; i < half; i++) {
        int row1 = i / n;
        int col1 = i % n;
        int row2 = (total - 1 - i) / n;
        int col2 = (total - 1 - i) % n;

        // swap mat[row1][col1], mat[row2][col2]
        swap(&mat[row1][col1], &mat[row2][col2]);
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int mat[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    reverseMat(m, n, mat);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
