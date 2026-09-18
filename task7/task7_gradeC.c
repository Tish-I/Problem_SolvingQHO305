#include <stdio.h>

    struct Item
{
    int id;
    char assetTag[20];
    char status[20];
};

void addItem(int id, char assetTag[], char status[])
{

    FILE *fptr = fopen("loans.txt", "r");

    int currentId;
    char currentAssetTag[20];
    char currentStatus[20];

    if (fptr != NULL)
    {
        while (fscanf(fptr, "%d,%19[^,],%19[^\n]\n",
                      &currentId, currentAssetTag, currentStatus) == 3)
        {
            if (currentId == id)
            {
                printf("Sorry, an item with ID %d already exists.\n", id);
                fclose(fptr);
                return;
            }
        }
        fclose(fptr);
    }
    fptr = fopen("loans.txt", "a");

    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file!\n");
        return;
    }

    fprintf(fptr, "%d,%s,%s\n", id, assetTag, status);

    fclose(fptr);

    printf("Item added successfully!\n");
}

void displayItems()
{
    struct Item item;

    FILE *fptr = fopen("loans.txt", "r");
    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file!\n");
        return;
    }
    printf("\n------------ Equipment List -----------\n");
    while (fscanf(fptr, "%d,%19[^,],%19[^\n]\n", &item.id, item.assetTag, item.status) == 3)
    {
        printf("ID: %d | Asset Tag: %s | Status: %s\n", item.id, item.assetTag, item.status);
    }
    fclose(fptr);
}

void searchItemById(int id)
{

    FILE *fptr = fopen("loans.txt", "r");

    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file\n");
        return;
    }
    int currentId;
    char assetTag[20], status[20];
    int found = 0;

    while (fscanf(fptr, "%d,%19[^,],%19[^\n]\n", &currentId, assetTag, status) == 3)
    {
        if (currentId == id)
        {
            printf("Found: ID %d | AssetTag: %s | Status: %s\n", currentId, assetTag, status);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Sorry, No item found with ID %d.\n", id);
    }
    fclose(fptr);
}

int main()
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

    displayItems();

    int searchId;

    printf("Please enter the ID of the item you'd like to search for: ");
    scanf("%d", &searchId);

    searchItemById(searchId);

    return 0;
}