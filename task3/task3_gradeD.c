#include <stdio.h>

int main()
{

    int steps;
    float distance, calories;

    printf("Please enter your steps for today: ");
    scanf("%d", &steps);

    distance = steps / 1250.0;
    calories = (steps / 1000.0) * 40;

    printf("Distance covered: %.2f km\n", distance);
    printf("Calories burned: %.2f kcal\n", calories);

    return 0;
}