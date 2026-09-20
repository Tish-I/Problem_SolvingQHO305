#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB.UTF-8");
    int numOfDays;
    float tempReadings[50];

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
    tempReadings[numOfDays] = -999.0;

    int menuChoice;

    do
    {
        printf("\n========== Menu Selection ==========\n");
        printf("1. Display all temperature readings\n");
        printf("2. Calculate average temperature\n");
        printf("3. Highest and Lowest temperature\n");
        printf("4. Count days above and below the threshold\n");
        printf("5. Calculate weekly averages\n");
        printf("6. Reverse temperature readings\n");
        printf("7. Exit\n");
        printf("\nPlease enter your selection: ");
        scanf("%d", &menuChoice);

        while (menuChoice != 1 && menuChoice != 2 &&
               menuChoice != 3 && menuChoice != 4 &&
               menuChoice != 5 && menuChoice != 6 &&
               menuChoice != 7)
        {
            printf("Uh Oh! Please choose between numbers 1 and 7: ");
            scanf("%d", &menuChoice);
        }

        if (menuChoice == 1)
        {
            float *ptr = tempReadings;
            int day = 1;

            printf("\n---------- Temperature Readings ----------\n");

            while (*ptr != -999.0)
            {
                printf("Day %d: %.2f°C\n", day, *ptr);

                ptr++;
                day++;
            }
        }

        else if (menuChoice == 2)
        {
            float total = 0;
            int count = 0;

            for (int i = 0; tempReadings[i] != -999.0; i++)
            {
                total += tempReadings[i];
                count++;
            }
            float average = total / count;
            printf("\n------------ Average Temperature ----------\n");
            printf("Average: %.2f°C\n", average);
        }
        else if (menuChoice == 3)
        {
            float *ptr = tempReadings;

            float highest = *ptr;
            float lowest = *ptr;

            int highestDay = 1;
            int lowestDay = 1;

            ptr++;
            int day = 2;

            while (*ptr != -999.0)
            {
                if (*ptr > highest)
                {
                    highest = *ptr;
                    highestDay = day;
                }
                if (*ptr < lowest)
                {
                    lowest = *ptr;
                    lowestDay = day;
                }
                ptr++;
                day++;
            }

            float tempRange = highest - lowest;

            printf("\n---------- Temperature Comparison ----------\n");
            printf("Highest Temperature: %.2f°C on day %d\n", highest, highestDay);
            printf("Lowest Temperature: %.2f°C on day %d\n", lowest, lowestDay);
            printf("Temperature Range: %.2f°C\n", tempRange);
        }
        else if (menuChoice == 4)
        {
            float threshold;
            int above = 0, below = 0, onThreshold = 0;
            printf("\n---------- Temperature Threshold ----------\n");
            printf("Please enter the temperature threshold: ");
            scanf("%f", &threshold);

            for (int i = 0; tempReadings[i] != -999.0; i++)
            {
                if (tempReadings[i] > threshold)
                {
                    above++;
                }
                else if (tempReadings[i] < threshold)
                {
                    below++;
                }
                else
                {
                    onThreshold++;
                }
            }
            printf("Days above the threshold: %d\n", above);
            printf("Days below the threshold: %d\n", below);
            printf("Days exactly on the threshold: %d\n", onThreshold);
        }
        else if (menuChoice == 5)
        {
            int week = 1;
            int idx = 0;

            printf("\n---------- Weekly Averages ----------\n");

            while (tempReadings[idx] != -999.0)
            {
                float weekTotals = 0;
                int daysInWeek = 0;

                for (int i = 0; i < 7 && tempReadings[idx] != -999.0; i++)
                {
                    weekTotals += tempReadings[idx];
                    daysInWeek++;
                    idx++;
                }
                float weekAverage = weekTotals / daysInWeek;
                printf("Week %d Average: %.2f°C\n", week, weekAverage);
                week++;
            }
        }
        else if (menuChoice == 6)
        {
            float *ptr = tempReadings + numOfDays - 1;
            int daysAgo = 0;

            printf("\n---------- Reverse Temperature Readings ----------\n");

            while (1)
            {
                if (daysAgo == 0)
                {
                    printf("Today: %.2f°C\n", *ptr);
                }
                else if (daysAgo == 1)
                {
                    printf("Yesterday: %.2f°C\n", *ptr);
                }
                else
                {
                    printf("%d days ago: %.2f°C\n", daysAgo, *ptr);
                }
                if (ptr == tempReadings)
                {
                    break;
                }
                ptr--;
                daysAgo++;
            }
        }

        else if (menuChoice == 7)
        {
            printf("\nExiting the program...Please come again.\n");
        }
    } while (menuChoice != 7);

    return 0;
}