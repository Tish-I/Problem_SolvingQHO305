#include <stdio.h>
#include <ctype.h>

int main()
{
    int menu;

    do
    {
        printf("\n---- Cinema Ticket Booking System ----\n");
        printf("1. Book Tickets\n");
        printf("2. View Ticket Prices\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
        {
            char movieCategories;
            char ticketType;
            float ticketPrice;
            float totalCost;
            int numOfTickets;
            float groupDiscount = 0;
            char snackCombo;
            float snackCost = 0;
            float finalTotal;

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
                break;
            }

            if (movieCategories != 'A' && movieCategories != 'C' && movieCategories != 'H')
            {
                printf("Uh Oh! Invalid movie selection.\n");
                break;
            }

            if (ticketType != 'S' && ticketType != 'P')
            {
                printf("Uh Oh. Invalid ticket selection.\n");
                break;
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

            if (ticketType == 'S')
            {
                printf("Ticket Selected: Standard Seat\n");
            }
            else
            {
                printf("Ticket Selected: Premium Seat\n");
            }

            printf("Would you like to add a snack combo to this purchase? (y/n): ");
            scanf(" %c", &snackCombo);
            snackCombo = toupper(snackCombo);

            if (snackCombo != 'Y' && snackCombo != 'N')
            {
                printf("Uh Oh! Invalid snack combo choice.\n");
                break;
            }

            if (snackCombo == 'Y')
            {
                snackCost = 5.50 * numOfTickets;
            }

            totalCost = ticketPrice * numOfTickets;

            if (numOfTickets > 6)
            {
                groupDiscount = totalCost * 0.10;
            }

            finalTotal = totalCost - groupDiscount + snackCost;

            printf("Selected ticket price: £%.2f\n", ticketPrice);
            printf("Number of tickets selected: %d\n", numOfTickets);

            if (numOfTickets > 6)
            {
                printf("Total before discount: £%.2f\n", totalCost);
                printf("Group discount: £%.2f\n", groupDiscount);
                printf("Group discount applied!\n");
            }
            else
            {
                printf("Ticket total: £%.2f\n", totalCost);
                printf("No group discount applied (need to purchase more than 6 tickets for this perk).\n");
            }

            if (snackCombo == 'Y')
            {
                printf("Cost of snack combo: £%.2f\n", snackCost);
            }
            else
            {
                printf("No snack combo added.\n");
            }

            printf("Final total: £%.2f\n", finalTotal);
            break;
        }

        case 2:
            printf("\n---- Ticket Prices ----\n");
            printf("Action - Standard: £10.00 | Premium: £15.00\n");
            printf("Comedy - Standard: £8.00  | Premium: £13.00\n");
            printf("Horror - Standard: £9.00  | Premium: £14.00\n");

            break;

        case 3:
            printf("Exiting Booking System. Thank you. Come Again...\n");
            break;

        default:
            printf("Uh Oh! Invalid menu choice. Please try again.\n");
        }
    } while (menu != 3);

    return 0;
}