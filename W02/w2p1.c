#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    
    double userNum;
    
    printf("Change Maker Machine\n");
    printf("====================\n");
    
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &userNum);
    
    int numToonies = (int)(userNum) * 100 / 200;
    double remain1 = userNum - (numToonies * 2);
    
    int numLoonies = (int)(remain1) * 100 / 100;
    double remain2 = remain1 - (numLoonies * 1);
    
    int numQuarters = (double)(remain2) * 100 / 25;
    double remain3 = remain2 - (numQuarters * 0.25);
    
    printf("\n");
    printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", numToonies, remain1);
    printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", numLoonies, remain2);
    printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", numQuarters, remain3);
    printf("\n");
    printf("Machine error! Thank you for letting me keep $%.2lf!\n", remain3);
    
    return 0;
    
}
