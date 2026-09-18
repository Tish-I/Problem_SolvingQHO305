#include <stdio.h>

struct Item
{
    int id;
    char assetTag[20];
    char status[20];
};

void addItem()
{
    struct Item newItem;

    printf("Please enter the item ID: ");
    scanf("%d", &newItem.id);

    printf("Please enter the asset tag: ");
    scanf("%s", newItem.assetTag);

    printf("Please enter the items status (A = Available, L = Loaned): ");
    scanf("%s", newItem.status);

    FILE *fptr = fopen("loans.txt", "a");
    if (fptr == NULL)
    {
        printf("Uh Oh! Error opening file!\n");
        return;
    }
    fprintf(fptr, "%d,%s,%s\n", newItem.id, newItem.assetTag, newItem.status);
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

int main()
{
    addItem();
    addItem();
    addItem();

    displayItems();

    return 0;
}