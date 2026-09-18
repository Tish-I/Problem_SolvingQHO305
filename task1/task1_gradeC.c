#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB.UTF-8");
    float food;
    float travel;
    float entertainment;
    float total;
    float dailyAverageSpend;
    float weeklyBudget = 85.00;

    printf("Please enter your weekly spend for food: £");
    scanf("%f", &food);

    printf("Please enter your weekly spend for travel: £");
    scanf("%f", &travel);

    printf("Please enter your weekly spend for entertainment: £");
    scanf("%f", &entertainment);

    if (food < 0 || travel < 0 || entertainment < 0)
    {
        printf("\nUh Oh! Invalid input. Spending cannot be negative");
        return 1;
    }

    total = food + travel + entertainment;
    dailyAverageSpend = total / 7;

    printf("\nWeekly Expense Tracker\n");
    printf("----------------------\n");
    printf("Food: £%.2f\n", food);
    printf("Travel: £%.2f\n", travel);
    printf("Entertainment: £%.2f\n", entertainment);
    printf("----------------------\n");
    printf("Total Weekly Spending: £%.2f\n", total);
    printf("Average Daily Spending: £%.2f\n", dailyAverageSpend);
    printf("Weekly Budget: £%.2f\n", weeklyBudget);
    printf("----------------------\n");

    if (total <= weeklyBudget)
    {
        printf("\nWell Done! You are within budget for this week, keep it up.");
    }
    else
    {
        printf("\nOh Dear...you have gone over this weeks budget.");
    }

    return 0;
}