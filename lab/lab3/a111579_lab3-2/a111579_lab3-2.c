#include <stdio.h>

int grid[101][101]; 

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        int x_min = (x1 < x2) ? x1 : x2;
        int x_max = (x1 > x2) ? x1 : x2;
        int y_min = (y1 < y2) ? y1 : y2;
        int y_max = (y1 > y2) ? y1 : y2;
        
        // Increment the count for each point inside the rectangle
        for (int x = x_min; x <= x_max; x++) {
            for (int y = y_min; y <= y_max; y++) {
                grid[x][y]++;
            }
        }
    }
    
    int max_x = 0, max_y = 0, max_coverage = 0;
    
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            if (grid[x][y] > max_coverage || 
               (grid[x][y] == max_coverage && x < max_x) || 
               (grid[x][y] == max_coverage && x == max_x && y < max_y)) {
                max_x = x;
                max_y = y;
                max_coverage = grid[x][y];
            }
        }
    }
    
    printf("%d %d %d", max_x, max_y, max_coverage);
    
    return 0;
}
