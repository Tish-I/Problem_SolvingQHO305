#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB.UTF-8");
    float food = 45.75;
    float travel = 8.50;
    float entertainment = 22.99;
    float total;

    total = food + travel + entertainment;

    printf("Weekly Expense Tracker\n");
    printf("----------------------\n");
    printf("Food: £%.2f\n", food);
    printf("Travel: £%.2f\n", travel);
    printf("Entertainment: £%.2f\n", entertainment);
    printf("----------------------\n");
    printf("Total Weekly Spending: £%.2f\n", total);

    return 0;
}