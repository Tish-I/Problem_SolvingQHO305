#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB.UTF-8");
    char movieCategories;
    char ticketType;
    float ticketPrice;
    float totalCost;
    int numOfTickets;

    printf("Please enter movie selection (A = Action, C = Comedy, H = Horror): ");
    scanf(" %c", &movieCategories);

    printf("Please enter ticket selection (S = Standard, P = Premium): ");
    scanf(" %c", &ticketType);

    movieCategories = toupper(movieCategories);
    ticketType = toupper(ticketType);

    printf("Please enter your desired number of tickets: ");
    scanf("%d", &numOfTickets);

    if (numOfTickets <= 0)
    {
        printf("Uh Oh! Invalid number of tickets entered.\n");
        return 1;
    }

    if (movieCategories != 'A' && movieCategories != 'C' && movieCategories != 'H')
    {
        printf("Uh Oh! Invalid movie selection.\n");
        return 1;
    }

    if (ticketType != 'S' && ticketType != 'P')
    {
        printf("Uh Oh. Invalid ticket selection.\n");
        return 1;
    }

    switch (movieCategories)
    {
    case 'A':
        printf("Movie Selected: Action\n");
        if (ticketType == 'S')
        {
            ticketPrice = 10.00;
        }

        else
        {
            ticketPrice = 15.00;
        }
        break;

    case 'C':
        printf("Movie Selected: Comedy\n");
        if (ticketType == 'S')
        {
            ticketPrice = 8.00;
        }

        else
        {
            ticketPrice = 13.00;
        }
        break;

    case 'H':
        printf("Movie Selected: Horror\n");
        if (ticketType == 'S')
        {
            ticketPrice = 9.00;
        }

        else
        {
            ticketPrice = 14.00;
        }
        break;
    }

    totalCost = ticketPrice * numOfTickets;

    if (ticketType == 'S')
    {
        printf("Ticket Selected: Standard Seat\n");
    }

    else
    {
        printf("Ticket Selected: Premium Seat\n");
    }

    printf("Selected ticket price: £%.2f\n", ticketPrice);
    printf("Number of Tickets Selected: %d\n", numOfTickets);
    printf("Total Cost of selection: £%.2f\n", totalCost);

    return 0;
}