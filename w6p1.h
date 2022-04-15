#include <stdio.h>
#define MAX_PRD 3
#define SERVING 64


struct CatFoodInfo
    {
        int sku;
        double price;
		int calorie;
		double weight;
    };

int getIntPositive(int* intValue);

double getDoublePositive(double* dblValue);

void openingMessage(const int productNo);

struct CatFoodInfo getCatFoodInfo(const int seqOfProduct);

void displayCatFoodHeader(void);

void displayCatFoodData(const int sku, const double* price, const int calorie, const double* weight);

void displayReportHeader(void);

void start(void);
