#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// didnt realise I need to submit this

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);

    //number of letters
    int Letter = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        Letter++;
    }

    //number of words (spaces + 1)
    int Word = 1;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
        Word++;
    }

    //number of sentences
    int Sen = 0;
    for(int i = 0; i < strlen(text); i++)
    {

        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        Sen++;
    }

    //Index
    float calculation = (0.0588 * Letter / Word * 100) - (0.296 * Sen / Word * 100) - 15.8;
    int index = round(calculation);
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
}