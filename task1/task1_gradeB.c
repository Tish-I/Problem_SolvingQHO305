#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB.UTF-8");
    float week1Food, week1Travel, week1Entertainment, week1Total;
    float week2Food, week2Travel, week2Entertainment, week2Total;
    float week1Average;
    float week2Average;
    float weeklyBudget = 85.00;

    printf("Please enter your food spend for week One: £");
    scanf("%f", &week1Food);

    printf("Please enter your food spend for week Two: £");
    scanf("%f", &week2Food);

    printf("\nPlease enter your travel spend for week One: £");
    scanf("%f", &week1Travel);

    printf("Please enter your travel spend for week Two: £");
    scanf("%f", &week2Travel);

    printf("\nPlease enter your entertainment spend for week One: £");
    scanf("%f", &week1Entertainment);

    printf("Please enter your entertainment spend for week Two: £");
    scanf("%f", &week2Entertainment);

    if (week1Food < 0 || week1Travel < 0 || week1Entertainment < 0)
    {
        printf("\nUh Oh! Invalid input. Spending cannot be negative");
        return 1;
    }

    if (week2Food < 0 || week2Travel < 0 || week2Entertainment < 0)
    {
        printf("\nUh Oh! Invalid input. Spending cannot be negative");
        return 1;
    }

    week1Total = week1Food + week1Travel + week1Entertainment;
    week2Total = week2Food + week2Travel + week2Entertainment;

    week1Average = week1Total / 7;
    week2Average = week2Total / 7;

    printf("\nWeek One Expense Tracker\n");
    printf("----------------------\n");
    printf("Food: £%.2f\n", week1Food);
    printf("Travel: £%.2f\n", week1Travel);
    printf("Entertainment: £%.2f\n", week1Entertainment);
    printf("----------------------\n");
    printf("Week One Total Spending: £%.2f\n", week1Total);
    printf("Average Daily Spending: £%.2f\n", week1Average);
    printf("Weekly Budget: £%.2f\n", weeklyBudget);
    printf("----------------------\n");

    if (week1Total <= weeklyBudget)
    {
        printf("\nWell Done! You are within budget for this week, keep it up.\n");
    }
    else
    {
        printf("\nOh Dear...you have gone over this weeks budget.\n");
    }

    printf("\nWeek Two Expense Tracker\n");
    printf("----------------------\n");
    printf("Food: £%.2f\n", week2Food);
    printf("Travel: £%.2f\n", week2Travel);
    printf("Entertainment: £%.2f\n", week2Entertainment);
    printf("----------------------\n");
    printf("Week Two Total Spending: £%.2f\n", week2Total);
    printf("Average Daily Spending: £%.2f\n", week2Average);
    printf("Weekly Budget: £%.2f\n", weeklyBudget);
    printf("----------------------\n");

    if (week2Total <= weeklyBudget)
    {
        printf("\nWell Done! You are within budget for this week, keep it up.\n");
    }
    else
    {
        printf("\nOh Dear...you have gone over this weeks budget.\n");
    }

    if (week2Total > week1Total)
    {
        printf("\nOverall spending increased from week One to week Two. Please budget better!");
    }
    else if (week2Total < week1Total)
    {
        printf("\nOverall spending decreased from week One to week Two. Amazing! Keep it up.");
    }
    else
    {
        printf("\nOverall spending has remained the same. Not bad at all.");
    }

    return 0;
}