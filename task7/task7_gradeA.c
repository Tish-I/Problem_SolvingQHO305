#include <stdio.h>
#include <string.h>

struct Item
{
    int id;
    char assetTag[20];
    char status[20];
};

#define MAX_ITEMS 100

struct Item items[MAX_ITEMS];
int itemCount = 0;

const char filename[] = "loans.txt";

void loadItems()
{

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        return;
    }

    itemCount = 0;

    while (itemCount < MAX_ITEMS &&
           fscanf(fptr, "%d,%19[^,],%19[^\n]\n",
                  &items[itemCount].id,
                  items[itemCount].assetTag,
                  items[itemCount].status) == 3)
    {

        itemCount++;
    }

    fclose(fptr);
}

int saveItems()
{

    FILE *fptr = fopen(filename, "w");

    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file!\n");
        return 0;
    }

    for (int i = 0; i < itemCount; i++)
    {

        fprintf(fptr, "%d,%s,%s\n",
                items[i].id,
                items[i].assetTag,
                items[i].status);
    }

    fclose(fptr);

    printf("Items saved successfully!\n");
    return 1;
}

int addItem(int id, char assetTag[], char status[]) 
{

    for (int i = 0; i < itemCount; i++)
    {

        if (items[i].id == id)
        {
            printf("Sorry, an item with ID %d already exists.\n", id);
            return 0;
        }
    }

    if (itemCount >= MAX_ITEMS)
    {
        printf("Sorry, the equipment list is full.\n");
        return 0;
    }

    items[itemCount].id = id;
    strcpy(items[itemCount].assetTag, assetTag);
    strcpy(items[itemCount].status, status);

    itemCount++;

    printf("Item added successfully!\n");
    return 1;
}

void displayItems()
{

    printf("\n------------ Equipment List -----------\n");

    if (itemCount == 0)
    {
        printf("No equipment currently stored.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++)
    {
        printf("ID: %d | Asset Tag: %s | Status: %s\n",
               items[i].id,
               items[i].assetTag,
               items[i].status);
    }
}

int searchItemById(int id)
{

    for (int i = 0; i < itemCount; i++)
    {

        if (items[i].id == id)
        {
            printf("Found: ID %d | Asset Tag: %s | Status: %s\n",
                   items[i].id,
                   items[i].assetTag,
                   items[i].status);

            return i;
        }
    }

    printf("Sorry, no item found with ID %d.\n", id);
    return -1;
}

int updateItem(int id, const char newAssetTag[], const char newStatus[])
{

    for (int i = 0; i < itemCount; i++)
    {

        if (items[i].id == id)
        {

            strcpy(items[i].assetTag, newAssetTag);
            strcpy(items[i].status, newStatus);

            printf("Item updated successfully!\n");
            return 1;
        }
    }

    printf("Sorry, no item found with ID %d.\n", id);
    return 0;
}

int deleteItem(int id)
{

    int foundIndex = -1;

    for (int i = 0; i < itemCount; i++)
    {

        if (items[i].id == id)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        printf("Sorry, no item found with ID %d.\n", id);
        return 0;
    }

    for (int i = foundIndex; i < itemCount - 1; i++)
    {
        items[i] = items[i + 1];
    }

    itemCount--;

    printf("Item deleted successfully!\n");
    return 1;
}

int main()
{
    loadItems();

    int choice;

    do
    {
        printf("\n---------- Equipment Loan Manager ----------\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Save\n");
        printf("7. Exit\n");

        printf("\nPlease select an option: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
        {
            int id;
            char assetTag[20];
            char status[20];

            printf("Please enter the item ID: ");
            scanf("%d", &id);

            printf("Please enter the asset tag: ");
            scanf("%19s", assetTag);

            printf("Please enter the items status (A = Available, L = Loaned): ");
            scanf("%19s", status);

            addItem(id, assetTag, status);

            break;
        }

        case 2:
            displayItems();
            break;

        case 3:
        {
            int searchId;

            printf("Please enter the ID of the item you'd like to search for: ");
            scanf("%d", &searchId);

            int position = searchItemById(searchId);

            if (position != -1)
            {
                printf("Record position: %d\n", position);
            }

            break;
        }

        case 4:
        {
            int updateId;
            char newAssetTag[20];
            char newStatus[20];

            printf("Please enter the ID of the item you'd like to update: ");
            scanf("%d", &updateId);

            printf("Please enter the new asset tag: ");
            scanf("%19s", newAssetTag);

            printf("Please enter the new status (A = Available, L = Loaned): ");
            scanf("%19s", newStatus);

            updateItem(updateId, newAssetTag, newStatus);

            break;
        }

        case 5:
        {
            int deleteId;

            printf("Please enter the ID of the item you'd like to delete: ");
            scanf("%d", &deleteId);

            deleteItem(deleteId);

            break;
        }

        case 6:
            saveItems();
            break;

        case 7:
            printf("Exiting Equipment Loan Manager.\n");
            break;

        default:
            printf("Uh Oh! Invalid option. Please select 1-7.\n");
        }

    } while (choice != 7);

    saveItems();

    return 0;
}