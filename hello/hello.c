#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // to get name
    string name = get_string("What's your name? ");
    // to print hello and name together
    printf("hello, %s!\n", name);
}