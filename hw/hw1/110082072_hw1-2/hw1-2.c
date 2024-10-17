#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 將帶有貨幣符號和逗號的字符串轉換為純數字
int process(const char *loan_amount) {
    char modified[7];  // 將儲存整理後的數字部分
    int len = strlen(loan_amount);
    int index = 0;

    // 過濾掉 "$" 和 ","，保留數字
    for (int i = 0; i < len; i++) {
        if (loan_amount[i] != '$' && loan_amount[i] != ',') {
            modified[index++] = loan_amount[i];
        }
    }
    modified[index] = '\0';

    // 將處理後的字符串轉換為整數
    return atoi(modified);
}

int main() {
    char loan_amount[9];  
    float annual_interest_rate;
    int loan_periods;

    // 輸入格式: "$101,677 24.0 3"
    scanf("%s %f %d", &loan_amount, &annual_interest_rate, &loan_periods);

    // 處理 loan_amount 字符串以去除 '$' 和 ','
    int modified = process(loan_amount);

    // 計算月利率，並四捨五入至小數點後兩位顯示
  	// year/12
    float monthly_interest_rate = annual_interest_rate / 12;

    // 計算單利下的總貸款金額
  	// total = origin *(1 + montn/100 * preilod)
    float total_loan_amount = modified * (1 + monthly_interest_rate / 100 * loan_periods);

    // 將處理後的貸款金額分解成鈔票
    int num_2000 = modified / 2000;
    modified %= 2000;

    int num_1000 = modified / 1000;
    modified %= 1000;

    int num_500 = modified / 500;
    modified %= 500;

    int num_100 = modified / 100;
    modified %= 100;

    int num_10 = modified / 10;
    modified %= 10;

    int num_1 = modified;

    // 輸出格式
    printf("| $2000| $1000| $500| $100| $10| $1|\n");
    printf("|%6d|%6d|%5d|%5d|%4d|%3d|\n", num_2000, num_1000, num_500, num_100, num_10, num_1);

    // 輸出月利率（顯示兩位小數）
    printf("Monthly interest rate: %.2f%%\n", monthly_interest_rate);

    // 輸出總貸款金額（保留一位小數）
    printf("Total loan amount: %.1f\n", total_loan_amount);

    return 0;
}
