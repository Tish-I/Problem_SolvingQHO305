#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB.UTF-8");
    int numOfDays;
    float tempReadings[30];

    printf("How many days would you like to record? ");
    scanf("%d", &numOfDays);

    while (numOfDays < 1 || numOfDays > 30)
    {
        printf("Uh Oh! Please enter a number between 1 and 30: ");
        scanf("%d", &numOfDays);
    }

    for (int i = 0; i < numOfDays; i++)
    {
        printf("Please enter temperature for day %d: ", i + 1);
        scanf("%f", &tempReadings[i]);
    }

    int menuChoice;
    printf("\n========== Menu Selection ==========\n");
    printf("1. Display all temperature readings\n");
    printf("2. Calculate average temperature\n");
    printf("\nPlease enter your selection: ");
    scanf("%d", &menuChoice);

    while (menuChoice < 1 || menuChoice > 2)
    {
        printf("Uh Oh! Please enter your selection from 1 to 2: ");
        scanf("%d", &menuChoice);
    }

    if (menuChoice == 1)
    {
        printf("\n---------- Temperature Readings ----------\n");

        for (int i = 0; i < numOfDays; i++)
        {
            printf("Day %d: %.2f °C\n", i + 1, tempReadings[i]);
        }
    }
    else if (menuChoice == 2)
    {
        float total = 0;
        for (int i = 0; i < numOfDays; i++)
        {
            total += tempReadings[i];
        }
        float average = total / numOfDays;
        printf("\n------------ Average Temperature ----------\n");
        printf("Average: %.2f°C\n", average);
    }

    return 0;
}