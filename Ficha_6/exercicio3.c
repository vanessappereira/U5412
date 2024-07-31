#include <stdio.h>
#include <string.h>

void invertedString()
{
    char str[100];
    char inverted[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        inverted[i] = str[length - i - 1];
    }

    printf("Inverted string: %s\n", inverted);
}

int main(int argc, char const *argv[])
{
    invertedString();
}
