#include "../headers.h"

void formatar_cpf_cnj(char cpf_cnpj[19], char cpf_cnpj_formatado[19]) {
    strlen(cpf_cnpj) == 11
        ? formatar_cpf(cpf_cnpj, cpf_cnpj_formatado)
        : formatar_cnpj(cpf_cnpj, cpf_cnpj_formatado);
}