#include <stdio.h>

int main() {
    int n, age, totalPrice = 0;  // Declare totalPrice only once
    scanf("%d", &n);  // Read the total number of individuals

    // Loop through each individual
    for (int i = 0; i < n; i++) {
        scanf("%d", &age);  // Read the age of each individual

        // Determine ticket price based on age
        if (age < 12) {
            totalPrice += 350;  // Child
        } else if (age >= 12 && age <= 18) {
            totalPrice += 550;  // Teenager
        } else if (age > 18 && age < 65) {
            totalPrice += 700;  // Adult
        } else {
            totalPrice += 300;  // Senior
        }
    }

    // Output the total price after calculating for all individuals
    printf("%d\n", totalPrice);

    return 0;
}
