#include <stdio.h>
#include <ctype.h>

int main()
{
    int activityIntensity;

    float intensityFactor = 1.0;
    float progress;
    float kcal;
    float daykms = 0;
    float daykcal = 0;
    float kms, minutes, kmsEntry;
    float totalkms = 0, totalkcal = 0;
    float storedkms[30];
    float storedkcal[30];
    float storedProgress[30];

    int dayNum = 1;
    int dailyGoal = 0;
    int currentStreak = 0, longestStreak = 0, daysMeetingGoal = 0;
    int daySteps = 0;
    int steps;
    int totalSteps = 0;
    int storedSteps[30];

    int menuChoice;
    int stepEntry = 0, kmEntry = 0, minuteEntry = 0;

    char repeat;
    char anotherDay;

    printf("Please enter your daily step goal: ");
    scanf("%d", &dailyGoal);

    while (dailyGoal <= 0)
    {
        printf("Uh Oh! Daily goal must be positive. Please try again: ");
        scanf("%d", &dailyGoal);
    }

    printf("\nSelect the intensity of the activity:\n");
    printf("1. Light Walking\n");
    printf("2. Moderate Walking\n");
    printf("3. Fast Walking\n");
    printf("Please enter your selection: ");
    scanf("%d", &activityIntensity);

    while (activityIntensity < 1 || activityIntensity > 3)
    {
        printf("Uh Oh! Invalid choice. Please enter 1, 2 or 3: ");
        scanf("%d", &activityIntensity);
    }

    switch (activityIntensity)
    {
    case 1:
        intensityFactor = 1.0;
        break;

    case 2:
        intensityFactor = 1.10;
        break;

    case 3:
        intensityFactor = 1.20;
        break;
    }

    do
    {
        daySteps = 0;
        daykms = 0;
        daykcal = 0;

        printf("\n---- Day %d ----\n", dayNum);

        do
        {
            printf("\nWhat would you like to add and track?\n");
            printf("1. Steps\n2. Kilometers\n3. Walking minutes\n");
            printf("Please enter your choice: ");
            scanf("%d", &menuChoice);

            while (menuChoice < 1 || menuChoice > 3)
            {
                printf("Uh Oh! Invalid choice. Please enter 1, 2 or 3: ");
                scanf("%d", &menuChoice);
            }

            switch (menuChoice)
            {
            case 1:
                printf("How many steps? ");
                scanf("%d", &steps);
                while (steps <= 0)
                {
                    printf("Uh Oh! Invalid input. Steps must be positive. Please try again: ");
                    scanf("%d", &steps);
                }

                stepEntry++;
                break;
            case 2:
                printf("How many Kilometers? ");
                scanf("%f", &kms);
                while (kms <= 0)
                {
                    printf("Uh Oh! Invalid input. Kilometers must be positive. Please try again: ");
                    scanf("%f", &kms);
                }

                steps = kms * 1250;
                kmEntry++;
                break;
            case 3:
                printf("How many minutes? ");
                scanf("%f", &minutes);
                while (minutes <= 0)
                {
                    printf("Uh Oh! Invalid input. Minutes must be positive. Please try again: ");
                    scanf("%f", &minutes);
                }

                steps = minutes * 100;
                minuteEntry++;
                break;
            default:
                printf("Uh Oh! Invalid choice.\n");
                continue;
            }
            daySteps = daySteps + steps;

            kcal = ((steps / 1000.0) * 40) * intensityFactor;

            daykms = daySteps / 1250.0;
            daykcal = daykcal + kcal;

            progress = ((float)daySteps / dailyGoal) * 100;
            kmsEntry = steps / 1250.0;

            printf("\nDistance covered by this entry: %.2f km\n", kmsEntry);
            printf("Calories burned by this entry: %.2f kcal\n", kcal);

            printf("Total steps today: %d\n", daySteps);
            printf("Total distance today: %.2f km\n", daykms);
            printf("Total calories today: %.2f kcal\n", daykcal);
            printf("Progress: %.2f%% of daily goal\n", progress);

            do
            {
                printf("\nWould you like to add and track another entry? (y/n): ");
                scanf(" %c", &repeat);
                repeat = toupper(repeat);
                if (repeat != 'Y' && repeat != 'N')
                {
                    printf("Uh Oh. Invalid input. Please enter y or n.\n");
                }
            } while (repeat != 'Y' && repeat != 'N');
        } while (repeat == 'Y');

        totalSteps = totalSteps + daySteps;
        totalkms = totalkms + daykms;
        totalkcal = totalkcal + daykcal;

        if (daySteps >= dailyGoal)
        {
            daysMeetingGoal++;
            currentStreak++;

            if (currentStreak > longestStreak)
            {
                longestStreak = currentStreak;
            }
        }
        else
        {
            currentStreak = 0;
        }

        printf("\n---- Day %d Summary ----\n", dayNum);
        printf("Steps: %d\n", daySteps);
        printf("Distance: %.2f kms\n", daykms);
        printf("Calories: %.2f kcal\n", daykcal);
        printf("Daily goal progress: %.2f%%\n", progress);

        if (dayNum == 30)
        {
            printf("\nUh Oh! Maximum number of 30 days reached.\n");
            anotherDay = 'N';
        }
        else
        {
            do
            {
                printf("\nWould you like to track another day? (y/n): ");
                scanf(" %c", &anotherDay);
                anotherDay = toupper(anotherDay);

                if (anotherDay != 'Y' && anotherDay != 'N')
                {
                    printf("Uh Oh! Invalid input. Please enter y or n.\n");
                }
            } while (anotherDay != 'Y' && anotherDay != 'N');
        }

        storedSteps[dayNum - 1] = daySteps;
        storedkms[dayNum - 1] = daykms;
        storedkcal[dayNum - 1] = daykcal;
        storedProgress[dayNum - 1] = progress;

        dayNum++;

    } while (anotherDay == 'Y');

    printf("\n========== Daily Summary ==========\n");

    for (int i = 0; i < dayNum - 1; i++)
    {
        printf("\nDay %d\n", i + 1);
        printf("Steps: %d | ", storedSteps[i]);
        printf("Distance: %.2f kms | ", storedkms[i]);
        printf("Calories: %.2f kcal | ", storedkcal[i]);
        printf("Goal Progress: %.2f%%\n", storedProgress[i]);
    }

    printf("\n========== Overall Summary ==========\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f kms\n", totalkms);
    printf("Total Calories: %.2f kcal\n", totalkcal);
    printf("Days meeting or exceeding goal: %d\n", daysMeetingGoal);
    printf("Longest goal streak: %d days\n", longestStreak);

    printf("\nActivity Entries\n");
    printf("Steps: %d\n", stepEntry);
    printf("Kilometers: %d\n", kmEntry);
    printf("Walking minutes: %d\n", minuteEntry);

    return 0;
}