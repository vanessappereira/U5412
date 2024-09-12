#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *pFile;
    fpos_t position;

    pFile = fopen("myfile.txt", "w+");
    if (pFile == NULL)
    {
        perror("Unable to open file");
        exit(1);
    }
    
    // Seek to the end of the file
    fgetpos(pFile, &position);
    
    // Write to the file
    fputs("Hello!\n", pFile);
    
    // Seek back to the beginning of the file
    fsetpos(pFile, &position);
    
    // Read from the file and print result
    char str[100];
    fgets(str, sizeof(str), pFile);
    puts(str);
    fclose(pFile);
    return 0;
}
