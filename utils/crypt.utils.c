#include "../headers.h"

bool valida_caractere(int i, char string[]) {
    return string[i] + strlen(string) * i != ',' &&
           string[i] + strlen(string) * i != '\n';
}

char *encrypt(char string[])
{
    for (int i = 0; (i < strlen(string) && string[i] != '\0'); i++)
    {
        if (valida_caractere(i, string))
        {
            string[i] = string[i] + strlen(string) * i;
        }
    }

    return string;
}

char *decrypt(char string[])
{
    for (int i = 0; (i < strlen(string) && string[i] != '\0'); i++)
    {
        if (valida_caractere(i, string))
        {
            string[i] = string[i] - strlen(string) * i;
        }
    }

    return string;
}