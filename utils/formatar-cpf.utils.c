#include "../headers.h"

void formatar_cpf(char cpf[11], char cpf_formatado[16])
{
    char resultado[16] = {
        cpf[0],
        cpf[1],
        cpf[2],
        '.',
        cpf[3],
        cpf[4],
        cpf[5],
        '.',
        cpf[6],
        cpf[7],
        cpf[8],
        '-',
        cpf[9],
        cpf[10],
    };

    strcpy(cpf_formatado, resultado);
}