#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // for row
    for (int i = 0; i < n; i++)
    {
        // for space
        for (int j = 0; j < n; j++)
        {
            if (i+j < n-1)
                printf(" ");
            else
                printf("#");
        }
        //to go another line
        printf("\n");
    }
}