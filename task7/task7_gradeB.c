#include <stdio.h>
#include <string.h>

struct Item
{
    int id;
    char assetTag[20];
    char status[20];
};

int addItem(int id, char assetTag[], char status[])
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
                return 0;
            }
        }
        fclose(fptr);
    }
    fptr = fopen("loans.txt", "a");

    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file!\n");
        return 0;
    }

    fprintf(fptr, "%d,%s,%s\n", id, assetTag, status);

    fclose(fptr);

    printf("Item added successfully!\n");

    return 1;
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

int searchItemById(int id)
{

    FILE *fptr = fopen("loans.txt", "r");

    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file\n");
        return -1;
    }
    int currentId;
    char assetTag[20], status[20];
    int position = 0;

    while (fscanf(fptr, "%d,%19[^,],%19[^\n]\n", &currentId, assetTag, status) == 3)
    {
        if (currentId == id)
        {
            printf("Found: ID %d | AssetTag: %s | Status: %s\n", currentId, assetTag, status);
            fclose(fptr);
            return position;
        }
        position++;
    }
    printf("Sorry, no item found with Id %d.\n", id);
    fclose(fptr);
    return -1;
}

int updateItem(int id, const char newAssetTag[], const char newStatus[])
{

    struct Item items[100];
    int count = 0;

    FILE *fptr = fopen("loans.txt", "r");

    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file!\n");
        return 0;
    }

    while (count < 100 &&
           fscanf(fptr, "%d,%19[^,],%19[^\n]\n",
                  &items[count].id,
                  items[count].assetTag,
                  items[count].status) == 3)
    {

        count++;
    }

    fclose(fptr);

    int found = 0;

    for (int i = 0; i < count; i++)
    {

        if (items[i].id == id)
        {

            strcpy(items[i].assetTag, newAssetTag);
            strcpy(items[i].status, newStatus);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Sorry, no item found with ID %d.\n", id);
        return 0;
    }

    fptr = fopen("loans.txt", "w");

    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file!\n");
        return 0;
    }

    for (int i = 0; i < count; i++)
    {

        fprintf(fptr, "%d,%s,%s\n",
                items[i].id,
                items[i].assetTag,
                items[i].status);
    }

    fclose(fptr);

    printf("Item updated successfully!\n");
    return 1;
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

    int position = searchItemById(searchId);

    if (position != -1)
    {
        printf("Record position: %d\n", position);
    }

    int updateId;
    char newAssetTag[20];
    char newStatus[20];

    printf("\nPlease enter the ID of the item you'd like to update: ");
    scanf("%d", &updateId);

    printf("Please enter the new asset tag: ");
    scanf("%19s", newAssetTag);

    printf("Please enter the new status (A = Available, L = Loaned): ");
    scanf("%19s", newStatus);

    updateItem(updateId, newAssetTag, newStatus);

    displayItems();

    return 0;
}