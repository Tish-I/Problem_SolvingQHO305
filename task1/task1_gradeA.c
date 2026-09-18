#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB.UTF-8");
    int numOfCategories;
    char categoryNames[10][25];
    float week1Amounts[10];
    float week2Amounts[10];
    float week1Total = 0;
    float week2Total = 0;
    float week1Average;
    float week2Average;
    float weeklyBudget = 85.00;

    printf("How many spending categories would you like to track? ");
    scanf("%d", &numOfCategories);

    if (numOfCategories < 1 || numOfCategories > 10)
    {
        printf("Sorry, Number of categories must be between 1 and 10.\n");
        return 1;
    }

    for (int i = 0; i < numOfCategories; i++)
    {
        printf("Please enter category %d name: ", i + 1);
        scanf("%s", categoryNames[i]);
    }

    for (int i = 0; i < numOfCategories; i++)
    {
        printf("Please enter Week One spending for %s: £", categoryNames[i]);
        scanf("%f", &week1Amounts[i]);

        printf("Please enter Week Two spending for %s: £", categoryNames[i]);
        scanf("%f", &week2Amounts[i]);

        if (week1Amounts[i] < 0 || week2Amounts[i] < 0)
        {
            printf("Uh Oh! Invalid input. Spending cannot be negative.\n");
            return 1;
        }

        week1Total += week1Amounts[i];
        week2Total += week2Amounts[i];
    }

    week1Average = week1Total / 7;
    week2Average = week2Total / 7;

    printf("\nWeek One Expense Tracker\n");
    printf("----------------------\n");
    for (int i = 0; i < numOfCategories; i++)
    {
        printf("%s: £%.2f\n", categoryNames[i], week1Amounts[i]);
    }

    printf("----------------------\n");
    printf("Week One Total Spend: £%.2f\n", week1Total);
    printf("Average Daily Spend: £%.2f\n", week1Average);
    printf("Weekly Budget: £%.2f\n", weeklyBudget);

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
    for (int i = 0; i < numOfCategories; i++)
    {
        printf("%s: £%.2f\n", categoryNames[i], week2Amounts[i]);
    }

    printf("----------------------\n");
    printf("Week Two Total Spend: £%.2f\n", week2Total);
    printf("Average Daily Spend: £%.2f\n", week2Average);
    printf("Weekly Budget: £%.2f\n", weeklyBudget);

    if (week2Total <= weeklyBudget)
    {
        printf("\nWell Done! You are within budget for this week, keep it up.\n");
    }
    else
    {
        printf("\nOh Dear...you have gone over this weeks budget.\n");
    }

    printf("\nCategory Spend Comparison\n");
    printf("----------------------\n");
    for (int i = 0; i < numOfCategories; i++)
    {
        if (week2Amounts[i] > week1Amounts[i])
        {
            printf("%s Spending has increased.\n", categoryNames[i]);
        }
        else if (week2Amounts[i] < week1Amounts[i])
        {
            printf("%s Spending has decreased.\n", categoryNames[i]);
        }
        else
        {
            printf("%s Spending has remained the same.\n", categoryNames[i]);
        }
    }

    printf("\nOverall Spend Summary\n");
    printf("----------------------\n");
    if (week2Total > week1Total)
    {
        printf("Overall spending has increased from Week One to Week Two.\n");
    }
    else if (week2Total < week1Total)
    {
        printf("Overall spending has decreased from Week One to Week Two.\n");
    }
    else
    {
        printf("Overall spending has remained the same.\n");
    }

    return 0;
}