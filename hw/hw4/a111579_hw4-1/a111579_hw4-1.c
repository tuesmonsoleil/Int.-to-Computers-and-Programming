#include <stdio.h>

unsigned long long count_sequences(int n, int m);

unsigned long long recursive_count(int days_left, int consecutive_kazuya, int two_consecutive, int n, int m) {
    // no more days
    if (days_left == 0) {
        return two_consecutive ? 1 : 0;
    }

    unsigned long long total = 0;

    // Kazuya
    if (consecutive_kazuya >= 1) {
        // Kazuya 1 day, if he dates again, consecutive days increase
        total += recursive_count(days_left - 1, consecutive_kazuya + 1, two_consecutive || consecutive_kazuya + 1 >= 2, n, m);
    } else {
        // Kazuya hasn't dated yet or just started
        total += recursive_count(days_left - 1, 1, two_consecutive, n, m);
    }

    // other clients (m-1 options)
    if (consecutive_kazuya > 0) {
        // choose another, consecutive Kazuya ends
        total += (m - 1) * recursive_count(days_left - 1, 0, two_consecutive, n, m);
    } else {
        total += (m - 1) * recursive_count(days_left - 1, 0, two_consecutive, n, m);
    }

    return total;
}

unsigned long long count_sequences(int n, int m) {
    // n days, 0 consecutive days -> Kazuya, 2 consecutive days -> false
    return recursive_count(n, 0, 0, n, m);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    unsigned long long result = count_sequences(n, m);
    printf("%llu\n", result);

    return 0;
}
