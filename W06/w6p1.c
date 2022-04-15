#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w6p1.h"

int valid;

int getIntPositive(int* intValue)
{
    int userInput = 0;
    
    do
    {
        scanf("%d", &userInput);
        if(userInput > 0)
        {
            valid = 1;
            if(intValue != NULL)
            {
                *intValue = userInput;
            }
        }
        else
        {
            valid = 0;
            printf("ERROR: Enter a positive value: ");
        }
    } while(!valid);
    
    return userInput;
}

double getDoublePositive(double* dblValue)
{
    double userInput = 0.0;
    
    do
    {
        scanf("%lf", &userInput);
        if(userInput > 0)
        {
            valid = 1;
            if(dblValue != NULL)
            {
                *dblValue = userInput;
            }
        }
        else
        {
            valid = 0;
            printf("ERROR: Enter a positive value: ");
        }
    } while(!valid);
    
    return userInput;
    
}

void openingMessage(const int productNo)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRD);
    printf("NOTE: A 'serving' is %dg\n", SERVING);
}

struct CatFoodInfo getCatFoodInfo(const int seqOfProduct)
{
    struct CatFoodInfo catFoodInfo;
    
    printf("\n"
           "Cat Food Product #%d\n", seqOfProduct+1);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&catFoodInfo.sku);
    printf("PRICE         : $");
    catFoodInfo.price = getDoublePositive(NULL);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&catFoodInfo.weight);
    printf("CALORIES/SERV.: ");
    catFoodInfo.calorie = getIntPositive(NULL);
    
    return catFoodInfo;
}

void displayCatFoodHeader(void)
{   printf("\n");
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int sku, const double* price, const int calorie, const double* weight)
{ 
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calorie);
}

void start(void)
{
    int i;
    struct CatFoodInfo catFoodInfoList[MAX_PRD] = {{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    openingMessage(MAX_PRD);
    for(i=0; i<MAX_PRD; i++)
    {
        catFoodInfoList[i] = getCatFoodInfo(i);
    }
    
    displayCatFoodHeader();
    
    for(i=0; i<MAX_PRD; i++)
    {
        displayCatFoodData(catFoodInfoList[i].sku, &catFoodInfoList[i].price, catFoodInfoList[i].calorie, &catFoodInfoList[i].weight);
    }
}
