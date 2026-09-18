#include <stdio.h>

int main()
{
    int monthLengths[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    char eventTitle[15][25];
    int eventDays[15];
    int eventMonths[15];
    int numOfEvents = 0;

    int currentIdx = 0;

    int currentDay, currentMonth, currentDayNum;
    int countdown, eventDayNum, weekDay;
    int startOfWeek = 4;
    int menuChoice;

    printf("How many events would you like to enter? ");
    scanf("%d", &numOfEvents);

    while (numOfEvents < 1 || numOfEvents > 15)
    {
        printf("Uh Oh! Please enter between 1 and 15 events: ");
        scanf("%d", &numOfEvents);
    }

    for (int i = 0; i < numOfEvents; i++)
    {
        printf("\n---------- Event %d ----------", i + 1);

        printf("\nPlease enter the name of the event %d: ", i + 1);
        scanf(" %[^\n]", eventTitle[i]);

        printf("Please enter the month of the event: ");
        scanf("%d", &eventMonths[i]);

        while (eventMonths[i] < 1 || eventMonths[i] > 12)
        {
            printf("Uh Oh! Month must be between 1 and 12. Please try again: ");
            scanf("%d", &eventMonths[i]);
        }

        printf("Please enter the day of the event: ");
        scanf("%d", &eventDays[i]);

        while (eventDays[i] < 1 || eventDays[i] > monthLengths[eventMonths[i] - 1])
        {
            printf("Uh Oh! Invalid day for this month. Please try again: ");
            scanf("%d", &eventDays[i]);
        }
    }
    printf("\n---------- Current Date ----------\n");

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
        printf("Uh Oh! Invalid day for this month, Please try again: ");
        scanf("%d", &currentDay);
    }

    currentDayNum = currentDay;
    for (int i = 0; i < currentMonth - 1; i++)
    {
        currentDayNum = currentDayNum + monthLengths[i];
    }

    do
    {
        eventDayNum = eventDays[currentIdx];

        for (int i = 0; i < eventMonths[currentIdx] - 1; i++)
        {
            eventDayNum = eventDayNum + monthLengths[i];
        }

        countdown = eventDayNum - currentDayNum;
        weekDay = ((eventDayNum - 1) + (startOfWeek - 1)) % 7 + 1;

        printf("\n---------- Current Event ----------\n");
        printf("Name: %s\n", eventTitle[currentIdx]);
        printf("Date: %d/%d/2026\n", eventDays[currentIdx], eventMonths[currentIdx]);
        printf("Days until event: %d\n", countdown);

        switch (weekDay)
        {
        case 1:
            printf("Event weekday: Monday\n");
            break;

        case 2:
            printf("Event weekday: Tuesday\n");
            break;

        case 3:
            printf("Event weekday: Wednesday\n");
            break;

        case 4:
            printf("Event weekday: Thursday\n");
            break;

        case 5:
            printf("Event weekday: Friday\n");
            break;

        case 6:
            printf("Event weekday: Saturday\n");
            break;

        case 7:
            printf("Event weekday: Sunday\n");
            break;
        }

        if (countdown < 0)
        {
            printf("\nEvent Status: Uh Oh! This event has already passed.\n");
        }
        else if (countdown == 0)
        {
            printf("\n**** Event Status: Your event is today, I repeat. YOUR EVENT IS TODAY! ****\n");
        }
        else if (countdown <= 7)
        {
            printf("Event Status: Be ready! Your event is coming soon.\n");
            printf("\n**** URGENT EVENT ****\n");
        }
        else
        {
            printf("\nEvent Status: Breathe...your event is later in the year.\n");
        }

        printf("\n ========== Navigation ==========\n");
        printf("1. View next event\n");
        printf("2. View previous event\n");
        printf("3. Add another event\n");
        printf("4. Exit\n");
        printf("Please enter your selection: ");
        scanf("%d", &menuChoice);

        while (menuChoice < 1 || menuChoice > 4)
        {
            printf("Uh Oh! Please enter your selection from 1 to 4: ");
            scanf("%d", &menuChoice);
        }

        switch (menuChoice)
        {
        case 1:
            if (currentIdx < numOfEvents - 1)
            {
                currentIdx++;
            }
            else
            {
                printf("\nYou are already at the last event.\n");
            }
            break;

        case 2:
            if (currentIdx > 0)
            {
                currentIdx--;
            }
            else
            {
                printf("\nYou are already at the first event.\n");
            }
            break;

        case 3:
            if (numOfEvents < 15)
            {
                printf("\n---------- Add New Event ----------\n");

                printf("\nPlease enter the name of the event: ");
                scanf(" %[^\n]", eventTitle[numOfEvents]);

                printf("Please enter the month of the event: ");
                scanf("%d", &eventMonths[numOfEvents]);

                while (eventMonths[numOfEvents] < 1 || eventMonths[numOfEvents] > 12)
                {
                    printf("Uh Oh! Month must be between 1 and 12. Please try again: ");
                    scanf("%d", &eventMonths[numOfEvents]);
                }

                printf("Please enter the day of the event: ");
                scanf("%d", &eventDays[numOfEvents]);

                while (eventDays[numOfEvents] < 1 ||
                       eventDays[numOfEvents] >
                           monthLengths[eventMonths[numOfEvents] - 1])
                {
                    printf("Uh Oh! Invalid day for this month. Please try again: ");
                    scanf("%d", &eventDays[numOfEvents]);
                }
                numOfEvents++;
                currentIdx = numOfEvents - 1;

                printf("\nEvent added successfully!\n");
            }
            else
            {
                printf("\nUh Oh! Maximum number of 15 events reached.\n");
            }
            break;

        case 4:
            printf("\nExiting program...Come again\n");
            break;
        }
    } while (menuChoice != 4);

    return 0;
}