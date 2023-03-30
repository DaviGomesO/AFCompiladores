#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_Cadeia(int estadoAtual, char elementoAtualCadeia){
    if(estadoAtual == 0){
        if(elementoAtualCadeia == '0'){
            return 0;
        }else if(elementoAtualCadeia == '1'){
            return 1;
        }
    }else if(estadoAtual == 1){
        if(elementoAtualCadeia == '0'){
            return 1;
        }else if(elementoAtualCadeia == '1'){
            return 2;
        }
    }else if(estadoAtual == 2){
        if(elementoAtualCadeia == '0' || elementoAtualCadeia == '1'){
            return 3;
        }
    }
}

int main()
{
    char *cadeia;
    cadeia = (char*)malloc(sizeof(char) * 80);

    printf("Digite a cadeia: ");
    scanf("%s",cadeia);

    //tamanho da cadeia
    int tamCadeia = strlen(cadeia);

    //declara o estado inicial do automato
    int estadoAtual = 0;

    int i, contPadrao = 0;
    for(i = 0; i < tamCadeia; i++){
        estadoAtual = ler_Cadeia(estadoAtual, cadeia[i]);

        if(estadoAtual == 3){
            contPadrao++;
            estadoAtual = 0;
            i--;
        }

        if(i == tamCadeia-1 && estadoAtual == 2){
            contPadrao++;
        }
    }

    //verificar se está em um estado de aceitação

    printf("\nEstado ATUAL: %d\nForam encontrados %d padroes.", estadoAtual, contPadrao);

    return 0;
}
