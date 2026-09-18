#include <stdio.h>

int main()
{
    int monthLengths[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int currentDay, currentMonth, currentDayNum;
    int eventDay, eventMonth, countdown, eventDayNum;

    printf("Please enter today's month: ");
    scanf("%d", &currentMonth);

    while (currentMonth < 1 || currentMonth > 12)
    {
        printf("Uh Oh! Month must be between 1 and 12. Please try again: ");
        scanf("%d", &currentMonth);
    }

    printf("Please enter today's day: ");
    scanf("%d", &currentDay);

    while (currentDay < 1 || currentDay > monthLengths[currentMonth - 1])
    {
        printf("Oh Uh! Invalid day for this month, Please try again: ");
        scanf("%d", &currentDay);
    }

    printf("Please enter the event Month: ");
    scanf("%d", &eventMonth);

    while (eventMonth < 1 || eventMonth > 12)
    {
        printf("Uh Oh! Month must be between 1 and 12. Please try again: ");
        scanf("%d", &eventMonth);
    }

    printf("Please enter the event day: ");
    scanf("%d", &eventDay);

    while (eventDay < 1 || eventDay > monthLengths[eventMonth - 1])
    {
        printf("Oh Uh! Invalid day for this month, Please try again: ");
        scanf("%d", &eventDay);
    }

    currentDayNum = currentDay;
    for (int i = 0; i < currentMonth - 1; i++)
    {
        currentDayNum = currentDayNum + monthLengths[i];
    }

    eventDayNum = eventDay;
    for (int i = 0; i < eventMonth - 1; i++)
    {
        eventDayNum = eventDayNum + monthLengths[i];
    }

    countdown = eventDayNum - currentDayNum;

    printf("\n---------- Event Status ----------\n");

    if (countdown < 0)
    {
        printf("\nUh Oh! This event has already passed.\n");
    }
    else if (countdown == 0)
    {
        printf("\nYour event is today, I repeat, your event is TODAY!\n");
    }
    else if (countdown <= 7)
    {
        printf("\nBe ready! Your event is coming soon.\n");
    }
    else
    {
        printf("\nBreathe...your event is later in the year.\n");
    }

    printf("Days until event: %d days\n", countdown);

    return 0;
}