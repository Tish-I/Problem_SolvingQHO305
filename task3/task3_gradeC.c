#include <stdio.h>

int main()
{

    int steps, dayCount = 0;
    int totalSteps = 0;
    float distance, calories;
    float totalDistance = 0, totalCalories = 0;
    char repeat;

    do
    {
        printf("\nPlease enter your steps for today: ");
        scanf("%d", &steps);

        distance = steps / 1250.0;
        calories = (steps / 1000.0) * 40;

        totalSteps = totalSteps + steps;
        totalDistance = totalDistance + distance;
        totalCalories = totalCalories + calories;
        dayCount++;

        printf("Distance covered: %.2f km\n", distance);
        printf("Calories burned: %.2f kcal\n", calories);

        printf("\nWould you like to add and track another day? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("\nYou tracked %d days.\n", dayCount);
    printf("Total steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories: %.2f kcal\n", totalCalories);

    return 0;
}