#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    //make sure program runs with only one command-line argument
    //only two command-line
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //only digits
    for(int i = 0; i < strlen (argv[1]); i++)
    {
        if(!isdigit(argv[1][i]))
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }

    //convert string s to int
    int key = atoi(argv[1]);

    //get plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //convert to ciphertext
    for(int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + key) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }

    //bring down
    printf("\n");

}