#include <stdio.h>

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    
    printf("num1=%d, num2=%d in decimal\n", num1, num2);
    printf("num1=%o, num2=%o in octal\n", num1, num2);
    printf("num1=%x, num2=%x in hexadecimal\n", num1, num2);
    
    printf("(%d)+(%d)=%d\n", num1, num2, num1 + num2);
    printf("(%d)-(%d)=%d\n", num1, num2, num1 - num2);
    printf("(%d)*(%d)=%d\n", num1, num2, num1 * num2);
    printf("(%d)/(%d)=%d\n", num1, num2, num1 / num2);
    printf("(%d)%%(%d)=%d\n", num1, num2, num1 % num2);
    
    printf("(%d)/(%d)=%.2f\n", num1, num2, (float)num1 / (float)num2);
    
    printf("(%d)/(%d)=%.2e in scientific notation\n", num1, num2, (float)num1 / (float)num2);

    return 0;
}