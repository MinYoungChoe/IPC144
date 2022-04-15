#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010 
#define MAX_YEAR 2021
#include<stdio.h>

int main (void)
{
    const int JAN = 1, DEC = 12;
    int year = 0;
    int month = 0;
    int y = 0, m = 0;
    
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
    printf("\nLog starting date: %d-", year);
    
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
    printf("-01");
    return 0;
}
