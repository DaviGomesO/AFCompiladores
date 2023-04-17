#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char texto[] = "GTAGTACTAGTACTAGTACTGGATC";
// char padrao[] = "TACTA";
// char texto[] = "BABABBABBABABAB";
// char padrao[] = "ABA";

void ler_padrao(char *texto, char *padrao, int *indice, int tamPadrao)
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

void forca_bruta(char *texto, char *padrao, int tamTexto, int tamPadrao)
{
    int t = 0, p = 0;

    for (t; t < tamTexto; t++)
    {
        // VERIFICA SE O ELEMENTO DO INDICE DA VEZ É IGUAL AO PRIMEIRO ELEMENTO DO PADRÃO
        if (texto[t] == padrao[p])
        {
            ler_padrao(texto, padrao, &t, tamPadrao);
        }
    }
}

// AFD
// basicamente minha ideia foi considerar cada estado a leitura de um elemento do padrão
int ler_cadeia(char *padrao, int estadoAtual, char elementoAtual, int tamPadrao)
{
    if (estadoAtual < tamPadrao)
    {
        if (elementoAtual == padrao[estadoAtual])
        {
            return estadoAtual + 1;
        }
        else if (estadoAtual == 1)
        {
            // se o elemento for o primeiro, se ele ler o mesmo caractere que saiu do estado zero para o estado um, ele fica em loop
            if (elementoAtual == padrao[estadoAtual - 1])
            {
                return estadoAtual;
            }
        }
        else
        {
            return 0;
        }
    }
}

int estado_inicial = 0;

void automato(char *texto, char *padrao, int tamTexto, int tamPadrao)
{
    int estado_atual = estado_inicial;
    int i, qtd_padrao = 0;

    for (i = 0; i < tamTexto; i++)
    {
        estado_atual = ler_cadeia(padrao, estado_atual, texto[i], tamPadrao);

        // se o estado for do tamanho do padrão, significa que ele foi encontrado
        if (estado_atual == tamPadrao)
        {
            qtd_padrao++;
            estado_atual = 0;
            // se o padrão for de tamanho um, ele não decrementa, pois não perde a leitura de elemento
            if (tamPadrao > 1)
                i--;
        }
    }

    printf("\nO padrao foi encontrado %d vez(es) no texto.", qtd_padrao);
}

int main()
{

    char *texto, *padrao;
    texto = (char *)malloc(sizeof(char) * 256);
    padrao = (char *)malloc(sizeof(char) * 10);

    printf("Digite o texto: ");
    scanf("%s", texto);

    printf("Digite o padrao: ");
    scanf("%s", padrao);

    int tamTexto = strlen(texto);
    int tamPadrao = strlen(padrao);

    printf("tamanho texto: %d\ntamanho padrao: %d", tamTexto, tamPadrao);

    // forca_bruta(texto, padrao, tamTexto, tamPadrao);
    automato(texto, padrao, tamTexto, tamPadrao);

    return 0;
}
