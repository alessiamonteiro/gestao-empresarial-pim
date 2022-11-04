#include "../headers.h"
#include "../constantes.h"

void montar_caminho_arquivo(char caminho_arquivo[150], char sufixo[75])
{
    strcat(caminho_arquivo, CAMINHO_PROJETO);
    strcat(caminho_arquivo, sufixo);
}