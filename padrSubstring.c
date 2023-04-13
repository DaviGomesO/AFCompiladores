#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char texto[] = "GTAGTACTAGT";
char padrao[] = "TACTA";

void ler_padrao(int indice, int tamPadrao){
    int aux = indice, p;
    for(p = 0; p < tamPadrao; p++){
        if(texto[aux] == padrao[p]){
            aux++;
        }else{
            break;
        }
    }

    if(aux == tamPadrao-1){
        printf("Foi encontrado o padrao no indice %d", indice);
    }
}

int main()
{

    int t = 0, p = 0;
    int tamTexto = strlen(texto);
    int tamPadrao = strlen(padrao);
    int indice = -1;

    printf(" tamanho texto: %d\n tamanho padrao: %d", tamTexto, tamPadrao);

    for(t; t < tamTexto; t++){
        if(texto[t] == padrao[p]){
            ler_padrao(t,tamPadrao);
        }
    }

    return 0;
}

/*

if(p == tamPadrao-1){
                indice = t - tamPadrao;
                printf("\nPadrao encontrado no indice %d", indice);
            }
for(t; t < tamTexto - tamPadrao; t++)
else{
            if(p == tamPadrao-1){
                indice = t-tamPadrao;
                printf("Indice do padrao encontrado: %d",indice);
            }else if(p != 0){
                p = 0;
                indice = -1;
            }
        }
*/
