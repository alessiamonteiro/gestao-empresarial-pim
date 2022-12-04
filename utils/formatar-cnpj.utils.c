#include "../headers.h"

void formatar_cnpj(char cnpj[14], char cnpj_formatado[19])
{
    char resultado[19] = {
        cnpj[0],
        cnpj[1],
        '.',
        cnpj[2],
        cnpj[3],
        cnpj[4],
        '.',
        cnpj[5],
        cnpj[6],
        cnpj[7],
        '/',
        cnpj[8],
        cnpj[9],
        cnpj[10],
        cnpj[11],
        '-',
        cnpj[12],
        cnpj[13],
    };

    strcpy(cnpj_formatado, resultado);
}