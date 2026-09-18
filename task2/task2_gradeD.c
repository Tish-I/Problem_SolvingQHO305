#include <stdio.h>
int main()
{
    char movieCategories = 'A';
    char ticketType = 'S';
    float ticketPrice;

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

    if (ticketType == 'S')
    {
        printf("Ticket Selected: Standard Seat\n");
    }
    else
    {
        printf("Ticket Selected: Premium Seat\n");
    }

    printf("Selected ticket price: £%.2f\n", ticketPrice);

    return 0;
}
