#define _CRT_SECURE_NO_WARNINGS
#define MAX_ITEMS 10
#include <stdio.h>

int main(void){
    
    const double minIncome = 500.00, maxIncome = 400000.00, minCost = 100.00;
    double netIncome = 0;
    int userWish = 0,minUserWish = 0;
    int i;
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    
    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &netIncome);
        
        if (netIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (netIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
    }
    while (netIncome < minIncome || netIncome > maxIncome);
    
    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &userWish);
        if (userWish <= minUserWish)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else if (userWish > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        
    }while (userWish <= minUserWish || userWish > MAX_ITEMS);
    
    double userCost[userWish];
    int priority[userWish];
    char financingOption[userWish];
    char tmp;
    
    for (i = 0; i < userWish; i++)
    {
        printf("\nItem-%d Details:\n",i+1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &userCost[i]);
            
            if(userCost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            
            
        }while (userCost[i] < minCost);
        
        
        do{
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if(priority[i] != 1 && priority[i] !=2 && priority[i] !=3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
                
            }
        }while (priority[i] != 1 && priority[i] !=2 && priority[i] !=3);
        
        do{
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &tmp);
            if(tmp != 'y' && tmp != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                
            }else{
                financingOption[i] = tmp;
            }
        }while (tmp != 'y' && tmp != 'n');
    }
    
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    double total;
    for (i = 0 ; i < userWish; i++){
        printf("%3d  %5d    %5c    %11.2lf\n",i+1,priority[i],financingOption[i],userCost[i]);
        total += userCost[i];
    }
    
    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n" , total);
    printf("\n");
    printf("Best of luck in all your future endeavours!\n");
    
    return 0;
}
