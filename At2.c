#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Automato
int estadoInicial = 0 /*, estadoAceitacao = 2*/;
char letras[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digitos[] = "0123456789";
char oper[] = "+-";
char ponto = '.';

bool verificarCaractere(char c, char *vetor)
{
  int i = 0;
  while (vetor[i] != '\0')
  {
    if (vetor[i] == c)
    {
      return true;
    }
    i++;
  }
  return false;
}

int ler_Cadeia(int estadoAtual, char elementoAtualCadeia)
{
  if (estadoAtual == 0)
  {
    if (verificarCaractere(elementoAtualCadeia, digitos))
    {
      return 1;
    }
    else if (verificarCaractere(elementoAtualCadeia, oper))
    {
      return -1;
    }
  }
  else if (estadoAtual == -1)
  {
    if (verificarCaractere(elementoAtualCadeia, digitos))
    {
      return 1;
    }
    else if (verificarCaractere(elementoAtualCadeia, letras))
    {
      return 0;
    }
  }
  else if (estadoAtual == 1)
  {
    if (verificarCaractere(elementoAtualCadeia, digitos))
    {
      return 1;
    }
    else if (verificarCaractere(elementoAtualCadeia, oper) || verificarCaractere(elementoAtualCadeia, letras))
    {
      return -2;
    }
    else if (elementoAtualCadeia == ponto)
    {
      return 2;
    }
  }
  else if (estadoAtual == 2)
  {
    if (verificarCaractere(elementoAtualCadeia, digitos))
    {
      return 3;
    }
    else if (verificarCaractere(elementoAtualCadeia, oper) || verificarCaractere(elementoAtualCadeia, letras) || elementoAtualCadeia == ponto)
    {
      return 0;
    }
  }
  else if (estadoAtual == 3)
  {
    if (verificarCaractere(elementoAtualCadeia, digitos))
    {
      return 3;
    }
    else if (verificarCaractere(elementoAtualCadeia, oper) || verificarCaractere(elementoAtualCadeia, letras) || elementoAtualCadeia == ponto)
    {
      return -3;
    }
  }
}

void Automato(char *cadeia, int tamCadeia)
{
  int estadoAtual = estadoInicial;

  int i, padraoNumInt = 0, padraoNumReal = 0;
  for (i = 0; i < tamCadeia; i++)
  {
    if (verificarCaractere(cadeia[i], digitos) || verificarCaractere(cadeia[i], oper) || verificarCaractere(cadeia[i], letras) || cadeia[i] == ponto)
    {
      estadoAtual = ler_Cadeia(estadoAtual, cadeia[i]);
    }

    // aqui ele vai ter passado pelo estado de aceitação, e ainda tem caracteres para continuar lendo
    if (estadoAtual == -2)
    {
      padraoNumInt++;
      estadoAtual = 0;
      // garante que vai continuar a ler a cadeia a partir do elemento que levou ao encontro do padrão
      i--;
    }
    if (estadoAtual == -3)
    {
      padraoNumReal++;
      estadoAtual = 0;
      // garante que vai continuar a ler a cadeia a partir do elemento que levou ao encontro do padrão
      i--;
    }

    // verifica se está no fim da cadeia e se esstá no estado de aceitação
    if (i == tamCadeia - 1)
    {
      if (estadoAtual == 1)
      {
        padraoNumInt++;
      }
      else if (estadoAtual == 3)
      {
        padraoNumReal++;
      }
    }
  }

  printf("\nEstado ATUAL: %d\nPADROES para numeros inteiros encontrados: %d.\nPADROES para numeros reais encontrados: %d.", estadoAtual, padraoNumInt, padraoNumReal);
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