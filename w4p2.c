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
    }while (netIncome < minIncome || netIncome > maxIncome);
    
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
    
    int howWant;
    int flag = 0;
    
    double priority_total;
    int priority_opt;
    double all_month = total /netIncome;
    int final_year = (int)all_month / 12;
    int final_month = (int)all_month % 12;
    double prioty_tempmonth= 0;
    int priority_year = 0;
    int priority_month = 0;
    int check_finance = 0;
    
    while(flag == 0){
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &howWant);
        printf("\n");
        if (howWant > 2 ||howWant < 0)
        {
            printf("ERROR: Invalid menu selection.\n");
            printf("\n");
            flag = 0;
        }else{
            
            switch (howWant){
                case 1:
                    printf("====================================================\n");
                    printf("Filter:   All items\n");
                    printf("Amount:   $%1.2lf\n",total);
                    
                    printf("Forecast: %d years, %d months\n",final_year ,final_month+1);
                    for (i = 0 ; i < userWish; i++){
                        if (financingOption[i] == 'y'){
                            check_finance = 1;
                        }
                    }
                    
                    if (check_finance == 1){
                        printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");
                    }
                    printf("====================================================\n");
                    printf("\n");
                    flag = 0;
                    break;
                case 2:
                    printf("What priority do you want to filter by? [1-3]: ");
                    scanf("%d", &priority_opt);
                    printf("\n");
                    printf("====================================================\n");
                    printf("Filter:   by priority (%d)\n",priority_opt);
                    for (i = 0 ; i < userWish; i++){
                        if (priority[i] == priority_opt){
                            priority_total +=userCost[i];
                            
                        }
                    }
                    printf("Amount:   $%1.2lf\n",priority_total);
                    prioty_tempmonth = priority_total /netIncome;
                    priority_year = (int)prioty_tempmonth / 12;
                    priority_month = (int)prioty_tempmonth % 12;
                    printf("Forecast: %d years, %d months\n",priority_year,priority_month+1);
                    for (i = 0 ; i < userWish; i++){
                        if(priority[i] == priority_opt){
                            if (financingOption[i] == 'y'){
                                check_finance = 1;
                            }
                        }
                    }
                    
                    if (check_finance == 1){
                        printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");
                    }
                    printf("====================================================\n");
                    printf("\n");
                    flag = 0;
                    priority_total =0;
                    check_finance = 0;
                    break;
                case 0:
                    printf("Best of luck in all your future endeavours!\n");
                    
                    return 0;
            }
            
        }
    }
    
    return 0;
}
