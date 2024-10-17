#include <stdio.h>

int main() {
    int num1, num2;
    char op;
    
    scanf("%d %c %d", &num1, &op, &num2);
    
    switch(op) {
        case '+':
            printf("%d\n", num1 + num2);
            break;
        case '-':
            printf("%d\n", num1 - num2);
            break;
        case '*':
            printf("%d\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("division by zero error\n");
            } else {
                printf("%.2f\n", (float)num1 / (float)num2);
            }
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
    
    return 0;
}
