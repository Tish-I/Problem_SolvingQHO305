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
    return 0;
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
    printf("\n---------- Before ----------\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", titles[i]);
    }

    char temp[51];

    for (int i = 0; i < 7; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            if (compareTitles(titles[j], titles[i]) < 0)
            {
                strcpy(temp, titles[i]);
                strcpy(titles[i], titles[j]);
                strcpy(titles[j], temp);
            }
        }
    }

    printf("\n---------- After ----------\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", titles[i]);
    }

    return 0;
}