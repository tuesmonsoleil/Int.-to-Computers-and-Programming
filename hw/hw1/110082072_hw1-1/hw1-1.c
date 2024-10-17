#include <stdio.h>

int main() {
    int ROC, month, day, year;
    scanf("%d/%d/%d", &ROC, &month, &day);
    year = ROC + 1911;

    printf("Germany: %02d.%02d.%04d\n", day, month, year);
    printf("Belgium: %02d/%02d/%04d\n", day, month, year);
    printf("Taiwan: %04d/%02d/%02d\n", year, month, day);
    printf("US: %02d/%02d/%02d\n", month, day, year % 100);
    printf("UK: %02d/%02d/%02d\n", day, month, year % 100);

    return 0;
}
