#include "../headers.h"

 char *encrypt(char string[])
{
    for (int i = 0; (i < strlen(string) && string[i] != '\0'); i++)
    {
        string[i] = string[i] + strlen(string);
    }

    return string;
}

char *decrypt(char string[])
{
    for (int i = 0; (i < strlen(string) && string[i] != '\0'); i++)
    {
        string[i] = string[i] - strlen(string);
    }

    return string;
}