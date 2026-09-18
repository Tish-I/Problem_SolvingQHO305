#include <stdio.h>

int main()
{
    int menuChoice;
    int steps;
    int totalSteps = 0;
    int stepEntry = 0, kmEntry = 0, minuteEntry = 0;

    float kms, minutes, kcal;
    float totalkms = 0, totalkcal = 0;

    char repeat;

    do
    {
        printf("What would you like to add and track?\n");
        printf("1. Steps\n2. Kilometers\n3. Walking minutes\n");
        printf("Please enter your choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice)
        {
        case 1:
            printf("How many steps? ");
            scanf("%d", &steps);

            stepEntry++;
            break;
        case 2:
            printf("How many Kilometers? ");
            scanf("%f", &kms);

            steps = kms * 1250;
            kmEntry++;
            break;
        case 3:
            printf("How many minutes? ");
            scanf("%f", &minutes);

            steps = minutes * 100;
            minuteEntry++;
            break;
        default:
            printf("Uh Oh! Invalid choice.\n");
            continue;
        }

        kms = steps / 1250.0;
        kcal = (steps / 1000.0) * 40;

        totalSteps = totalSteps + steps;
        totalkms = totalkms + kms;
        totalkcal = totalkcal + kcal;

        printf("Distance covered: %.2f km\n", kms);
        printf("Calories burned: %.2f kcal\n", kcal);

        printf("\nWould you like to add and track another entry? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("\nSummary:\n");
    printf("Total steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalkms);
    printf("Total Calories: %.2f kcal\n", totalkcal);
    printf("You entered - Steps: %d, Kilometers: %d, Walking minutes: %d\n", stepEntry, kmEntry, minuteEntry);

    return 0;
}