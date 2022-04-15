#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    
    double userNum;
    double serviceFee;
    
    printf("Change Maker Machine\n");
    printf("====================\n");
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &userNum);
    serviceFee = userNum * 0.05;
    printf("Service fee (5.0 percent): %.2lf\n", serviceFee);

    userNum = userNum - serviceFee;
    printf("Balance to dispense: $%.2lf\n", userNum);
    
    int numToonies = (int)(userNum * 100) / 200;
    double remain = (int)(userNum * 100) % 200;
    double tooniesRemain = remain/100;
    
    int numLoonies = (int)(tooniesRemain * 100) / 100;
    remain = (int) (tooniesRemain * 100) % 100;
    double looniesRemain = remain/100;
    
    
    int numQuarters = (int)(looniesRemain * 100) / 25;
    remain = (int) (looniesRemain * 100) %25;
    double quartersRemain = remain/100;
    
    int numDimes = (int)(quartersRemain * 100) / 10;
    remain = (int) (quartersRemain * 100) %10;
    double dimesRemain = remain/100;
    
    int numNickels = (int)(dimesRemain * 100) / 5;
    remain = (int) (dimesRemain * 100) %5;
    double nickelsRemain = remain/100;
    
    int numPennies = (int)(nickelsRemain * 100) / 1;
    remain = (int) (nickelsRemain * 100) %1;
    double penniesRemain = remain/100;
    
    printf("\n");
    printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", numToonies, tooniesRemain);
    printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", numLoonies, looniesRemain);
    printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", numQuarters, quartersRemain);
    printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", numDimes, dimesRemain);
    printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", numNickels, nickelsRemain);
    printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", numPennies, penniesRemain);
    printf("\n");
    printf("All coins dispensed!");
    
    return 0;
    
}
