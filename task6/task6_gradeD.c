#include <stdio.h>

int main()
{
    char titles[8][51] = {
        "The Viscount Who Loved Me",
        "1984",
        "Fourth Wing",
        "Foundation",
        "The Three Body Problem",
        "Verity",
        "Klara and the Sun",
        "Parable of the Sower"};

    for (int i = 0; i < 8; i++)
    {
        printf("Current Title: \"%s\"\n", titles[i]);
        printf("First Title: \"%s\"\n\n", titles[0]);
    }

    return 0;
}