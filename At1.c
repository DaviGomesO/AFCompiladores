#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_Cadeia(int estadoAtual, char elementoAtualCadeia)
{
    if (estadoAtual == 0)
    {
        if (elementoAtualCadeia == '0')
        {
            return 0;
        }
        else if (elementoAtualCadeia == '1')
        {
            return 1;
        }
    }
    else if (estadoAtual == 1)
    {
        if (elementoAtualCadeia == '0')
        {
            return 1;
        }
        else if (elementoAtualCadeia == '1')
        {
            return 2;
        }
    }
    else if (estadoAtual == 2)
    {
        if (elementoAtualCadeia == '0' || elementoAtualCadeia == '1')
        {
            return 3;
        }
    }
}

// Automato
int estadoInicial = 0, estadoAceitacao = 2;

void Final(int estadoAtual)
{
    if (estadoAtual == estadoAceitacao)
    {
        printf("A cadeia pertence ao AFND.");
    }
    else
    {
        printf("A cadeia nao pertence ao AFND.");
    }
}

void Automato(char *cadeia, int tamCadeia)
{
    int estadoAtual = estadoInicial;

    int i, contPadrao = 0;
    for (i = 0; i < tamCadeia; i++)
    {
        if (cadeia[i] == '0' || cadeia[i] == '1')
        {
            estadoAtual = ler_Cadeia(estadoAtual, cadeia[i]);
        }

        // aqui ele vai ter passado pelo estado de aceitação, e ainda tem caracteres para continuar lendo
        if (estadoAtual == 3)
        {
            contPadrao++;
            estadoAtual = 0;
            // garante que vai continuar a ler a cadeia a partir do elemento que levou ao q3
            i--;
        }

        // verifica se está no fim da cadeia e se esstá no estado de aceitação
        if (i == tamCadeia - 1 && estadoAtual == 2)
        {
            contPadrao++;
        }
    }

    // verificar se está em um estado de aceitação
    Final(estadoAtual);

    printf("\nEstado ATUAL: %d\nPADROES encontrados: %d.", estadoAtual, contPadrao);
}

int main()
{
    char *cadeia;
    cadeia = (char *)malloc(sizeof(char) * 80);

    printf("Digite a cadeia: ");
    scanf("%s", cadeia);

    // tamanho da cadeia
    int tamCadeia = strlen(cadeia);

    // declara o estado inicial do automato
    Automato(cadeia, tamCadeia);

    return 0;
}
