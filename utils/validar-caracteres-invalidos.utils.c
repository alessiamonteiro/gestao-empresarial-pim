#include "../headers.h"

bool possui_caracteres_invalidos(char string[])
{
    return strstr(string, ";") ||
           strstr(string, "&") ||
           strstr(string, "=") ||
           strstr(string, ",");
}