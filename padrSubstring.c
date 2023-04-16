#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char texto[] = "GTAGTACTAGTACTAGTACTGGATC";
char padrao[] = "TACTA";

void ler_padrao(int *indice, int tamPadrao)
{
    // LER O PADRÃO AO MESMO TEMPO QUE LER O TEXTO, SÓ QUE AGORA VERIFICANDO SE O TEXTO É IGUAL AO PADRÃO
    int aux = *indice, p;
    for (p = 0; p < tamPadrao; p++)
    {
        if (texto[(*indice)] == padrao[p])
        {
            (*indice)++;
        }
        else
        {
            break;
        }
    }

    if (p == tamPadrao)
    {
        printf("\nFoi encontrado o padrao a partir do indice %d", aux);
    }

    // POR TER SAIDO DE UM FOR, DECREMENTO UM NO INDICE, PARA NÃO PERDER A LEITURA DE ELEMENTO DO TEXTO
    (*indice)--;
}

int main()
{

    int t = 0, p = 0;
    int tamTexto = strlen(texto);
    int tamPadrao = strlen(padrao);
    int indice = -1;

    printf("tamanho texto: %d\ntamanho padrao: %d", tamTexto, tamPadrao);

    for (t; t < tamTexto; t++)
    {
        // VERIFICA SE O ELEMENTO DO INDICE DA VEZ É IGUAL AO PRIMEIRO ELEMENTO DO PADRÃO
        if (texto[t] == padrao[p])
        {
            ler_padrao(&t, tamPadrao);
        }
    }

    return 0;
}
