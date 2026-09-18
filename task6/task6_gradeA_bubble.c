#include <stdio.h>
#include <ctype.h>
#include <string.h>

int compareTitles(char title1[], char title2[])
{
    int i = 0;

    while (title1[i] != '\0' && title2[i] != '\0')
    {
        char first = tolower(title1[i]);
        char second = tolower(title2[i]);

        if (first < second)
        {
            return -1;
        }
        else if (first > second)
        {
            return 1;
        }

        i++;
    }

    if (title1[i] == '\0' && title2[i] == '\0')
    {
        return 0;
    }
    else if (title1[i] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char titles[8][51] = {
        "The Viscount Who Loved Me",
        "Dungeon Crawler Carl",
        "Fourth Wing",
        "Foundation",
        "The Three Body Problem",
        "Verity",
        "Klara and the Sun",
        "Parable of the Sower"};
    int numofTitles = 8;

    printf("\n---------- Before ----------\n");
    for (int i = 0; i < numofTitles; i++)
    {
        printf("%s\n", titles[i]);
    }

    char temp[51];
    for (int i = 0; i < numofTitles - 1; i++)
    {
        for (int j = 0; j < numofTitles - 1 - i; j++)
        {
            if (compareTitles(titles[j], titles[j + 1]) > 0)
            {
                strcpy(temp, titles[j]);
                strcpy(titles[j], titles[j + 1]);
                strcpy(titles[j + 1], temp);
            }
        }
    }

    printf("\n---------- After ----------\n");
    for (int i = 0; i < numofTitles; i++)
    {
        printf("%s\n", titles[i]);
    }

    return 0;
}