#include <stdio.h>

int main()
{
    int currentDay, currentMonth, currentDayNum;
    int eventDay, eventMonth, countdown, eventDayNum;

    printf("Please enter today's day: ");
    scanf("%d", &currentDay);

    printf("Please enter today's month: ");
    scanf("%d", &currentMonth);

    printf("Please enter the event day: ");
    scanf("%d", &eventDay);

    printf("Please enter the event Month: ");
    scanf("%d", &eventMonth);

    currentDayNum = (currentMonth - 1) * 30 + currentDay;
    eventDayNum = (eventMonth - 1) * 30 + eventDay;

    countdown = eventDayNum - currentDayNum;

    if (countdown < 0)
    {
        printf("Uh Oh! Event date can't be before today's date.\n");
    }
    else
    {
        printf("Approximate days until event: %d days\n", countdown);
    }

    return 0;
}