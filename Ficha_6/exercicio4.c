#include <stdio.h>
#include <string.h>
#include <ctype.h>

void minorWord()
{
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove \n at the end
    str[strcspn(str, "\n")] = 0;

    int minor = 1000;
    int word_length = 0;

    // Run string
    for (int i = 0; i <= strlen(str); i++)
    {
        // verify if its the end or if has a space
        if (isspace(str[i]) || str[i] == '\0')
        {
            if (word_length < minor && word_length > 0)
            {
                minor = word_length;
            }
            word_length = 0; // Reset the length str
        }
        else
        {
            word_length++; // Increment the length str
        }
    }
    if (minor == 1000)
    {
        printf("There are no words in the string.\n");
    }
    else
    {
        printf("The length of the smallest word is: %d\n", minor);
    }
}
int main(int argc, char const *argv[])
{
    minorWord();
}
