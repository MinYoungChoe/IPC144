#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010 
#define MAX_YEAR 2021
#define LOG_DAYS 3
#include<stdio.h>

int main (void)
{
    const int JAN = 1, DEC = 12;
    int year = 0;
    int month = 0;
    int y = 0, m = 0, i = 0, flag;
    double morningRate;
    double eveningRate;
   
    printf("General Well-being Log\n");
    printf("======================\n");
    while(year == 0 && month == 0) {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &y, &m);
        
        if (y < MIN_YEAR || y > MAX_YEAR) {
            printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
            if(m < JAN || m > DEC) {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }
        }
        else if (m < JAN || m > DEC) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else {
            
            year = y;
            month = m;
        }
    }
    
    printf("\n*** Log date set! ***\n");
    printf("\n");
    
    double sumMorning = 0;
    double sumEvening = 0;
    
    for (i = 1; i <= LOG_DAYS; i++)
    {
        
        printf("%d-",year);
        switch(month)
        {
            case 1:
                printf("JAN");
                break;
            case 2:
                printf("FEB");
                break;
            case 3:
                printf("MAR");
                break;
            case 4:
                printf("APR");
                break;
            case 5:
                printf("MAY");
                break;
            case 6:
                printf("JUN");
                break;
            case 7:
                printf("JUL");
                break;
            case 8:
                printf("AUG");
                break;
            case 9:
                printf("SEP");
                break;
            case 10:
                printf("OCT");
                break;
            case 11:
                printf("NOV");
                break;
            case 12:
                printf("DEC");
                break;
        }
        printf("-0%d\n",i);
        
        do{
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRate);
            if (morningRate < 0 || morningRate > 5){
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                flag = 1;
            }else{
                flag = 0;
                sumMorning += morningRate;
                
            }
        }while (flag == 1);
        
        
        do{
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRate);
            if (eveningRate < 0 || eveningRate > 5){
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                flag = 1;
            }else {
                flag = 0;
                sumEvening += eveningRate;
            }
        }while (flag == 1);
        
        printf("\n");
    }
    
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n",sumMorning);
    printf("Evening total rating: %.3lf\n",sumEvening);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n",sumMorning+sumEvening);
    printf("\n");
    printf("Average morning rating: %4.1lf\n",sumMorning/LOG_DAYS);
    printf("Average evening rating: %4.1lf\n",sumEvening/LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n",(sumMorning+sumEvening)/(LOG_DAYS*2));
    
    return 0;
}
