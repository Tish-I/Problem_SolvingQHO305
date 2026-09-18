#include <stdio.h>

int main()
{
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

    do
    {
        printf("\n========== Menu Selection ==========\n");
        printf("1. Display all temperature readings\n");
        printf("2. Calculate average temperature\n");
        printf("3. Highest and Lowest temperature\n");
        printf("7. Exit\n");
        printf("\nPlease enter your selection: ");
        scanf("%d", &menuChoice);

        while (menuChoice != 1 && menuChoice != 2 &&
               menuChoice != 3 && menuChoice != 7)
        {
            printf("Uh Oh! Please enter 1, 2, 3 or 7: ");
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
        else if (menuChoice == 3)
        {
            float highest = tempReadings[0];
            float lowest = tempReadings[0];

            int highestDay = 1;
            int lowestDay = 1;

            for (int i = 1; i < numOfDays; i++)
            {
                if (tempReadings[i] > highest)
                {
                    highest = tempReadings[i];
                    highestDay = i + 1;
                }
                if (tempReadings[i] < lowest)
                {
                    lowest = tempReadings[i];
                    lowestDay = i + 1;
                }
            }

            float tempRange = highest - lowest;

            printf("\n---------- Temperature Comparison ----------\n");
            printf("Highest Temperature: %.2f°C on day %d\n", highest, highestDay);
            printf("Lowest Temperature: %.2f°C on day %d\n", lowest, lowestDay);
            printf("Temperature Range: %.2f°C\n", tempRange);
        }
        else if (menuChoice == 7)
        {
            printf("\nExiting the program...Please come again.\n");
        }
    } while (menuChoice != 7);

    return 0;
}