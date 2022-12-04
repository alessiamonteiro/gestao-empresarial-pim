// C Program to demonstrate fscanf
#include <stdio.h>
#include <string.h>
 
// Driver Code
int main()
{
    char caminho_arquivo[150] = "";
    FILE* ptr = fopen("/home/gestao-empresarial/database/funcionarios.txt", "r");

    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
 
    /* Assuming that abc.txt has content in below
       format
       NAME    AGE   CITY
       abc     12    hyderabad
       bef     25    delhi
       cce     65    bangalore */
    char buf[1024];
    while (fscanf(ptr, "%s,%s,%s,%s,%s,%s,%s,%s", buf) == 1)
    {
        
        // printf("%s\n", buf);
        for (int i = 0; i<strlen(buf); i++) {
            putchar(buf[i]);
        }
    }
    
    return 0;
}