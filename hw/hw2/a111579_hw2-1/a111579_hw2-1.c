#include <stdio.h>

int main() {
    int price, pocketMoney, refund, number;
    scanf("%d %d %d %d", &price, &pocketMoney, &refund, &number);

    int drinks = 0, cap=0, bottle=0;

    while(pocketMoney >= price || bottle >= number){
        // buy bottle with money
        int amount = pocketMoney/price;
        pocketMoney = pocketMoney % price;
        drinks += amount;
        cap += amount;
        bottle += amount;

        // exchange bottle for drinks
        amount = bottle / number;
        drinks += amount;
        cap += amount;
        bottle = (bottle % number) + amount;

        // exchange cap money
        pocketMoney += refund*cap;
        cap = 0;
    }
    printf("%d\n", drinks);

}