#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../core/headers/criar-usuario.repository.h"

void criar_usuario_repository(char nome[21], char senha[21], int id)
{
    FILE *txt_usuarios;
    txt_usuarios = fopen("usuarios.txt", "a");

    if (txt_usuarios == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return;
    }

    fprintf(txt_usuarios, "%i,%s,%s\n", id, nome, senha);

    fclose(txt_usuarios);

    printf("Dados gravados com sucesso!");
    printf("Cadastro realizado com sucesso!\n");
    system("sleep 02");
}
