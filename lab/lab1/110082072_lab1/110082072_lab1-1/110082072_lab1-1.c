#include <stdio.h>

int main(){
    int x, y, z;
    int vx, vy, vz;
    
    scanf("(%d,%d,%d) (%d,%d,%d)", &x, &y, &z, &vx, &vy, &vz);
    
    int new_x = x + vx;
    int new_y = y + vy;
    int new_z = z + vz;
    
    printf("(%d,%d,%d)\n", new_x, new_y, new_z);
    
    return 0;
}
