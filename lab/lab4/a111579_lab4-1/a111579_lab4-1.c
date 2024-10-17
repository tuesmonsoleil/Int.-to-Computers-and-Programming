#include <stdio.h>

// dynamic programming approach
unsigned long long catalan(int n) {
    unsigned long long dp[n + 1];

    // C(0) = 1
    dp[0] = 1;

    // C(n) for n >= 1
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);

    unsigned long long n_th = catalan(n);
    printf("%llu\n", n_th);

    return 0;
}
