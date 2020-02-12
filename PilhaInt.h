#ifndef PILHA_INT
#define PILHA_INT
#include <stdio.h>
#include <stdlib.h>

/*
 * Descrição:
 * - TAD da estrutura de dados pilha, para inteiros. Simula o empilhamento de valores.
 * 
 * Exemplos práticos:
 * - Comportamento de funções recursivas
 * - Mecanismo de desfazer/refazer de editores de texto.
 * - Um dos mecanismo de navegação de páginas web.
 * 
 * Observação:
 * - Deve se ter em mente que estruturas em C não se responsabilizam sobre a má utilização
 *  de suas estruturas de dados, e que cada programador deve ser responsável por verificar
 *  se a estrutura esta nas condições certas para realizar cada operação.
 * 
 * - Por exemplo, tentar obter um valor utilizando as funções PilhaInt_obter, ou
 *  PilhaInt_remover em uma pilha vazia, resultará em um erro de ponteiro inválido. Então,
 *  caso você não desenvolva uma lógica que não controlada para a utilização da pilha para
 *  que ela não caia neste contexto, você deve fazer a chamada da função PilhaInt_vazia para
 *  verificar se a operação é válida.
 */

typedef struct NoPilhaInt {
  int valor;
  struct NoPilhaInt *anterior;
} NoPilhaInt;

typedef struct PilhaInt {
  NoPilhaInt *topo;
} PilhaInt;

int PilhaInt_vazia(PilhaInt* pilha);
int PilhaInt_remover(PilhaInt* pilha);

/*
 * Cria uma nova pilha de inteiros.
 * 
 * @return Retorna uma pilha de inteiro vazia.
 */
PilhaInt* PilhaInt_criar() {
  PilhaInt* pilha = malloc(sizeof(PilhaInt));
  pilha->topo = NULL;
  return pilha;
}

/*
 * Remove todos os elementos da pilha e a destrói uma pilha de inteiros.
 * 
 * @param pilha: Pilha que deve ser destruída.
 */
void PilhaInt_destruir(PilhaInt* pilha) {
  while (!PilhaInt_vazia(pilha)) {
    PilhaInt_remover(pilha);
  }

  free(pilha);
}

/*
 * Adiciona um novo elemento inteiro a pilha.
 * 
 * @param pilha: Pilha que receberá o novo elemento.
 * @param valor: Valor que será adicionado a pilha.
 */
void PilhaInt_adicionar(PilhaInt* pilha, int valor) {
  NoPilhaInt* novo = malloc(sizeof(NoPilhaInt));
  novo->valor = valor;
  novo->anterior = pilha->topo;
  pilha->topo = novo;
}

/*
 * Remove e obtem o elemento do topo da pilha.
 * 
 * @param pilha: Pilha que sofrerá com a remoção do elemento do topo.
 * @return Retorna o valor removido.
 */
int PilhaInt_remover(PilhaInt* pilha) {
  int valor = pilha->topo->valor;
  NoPilhaInt *anterior = pilha->topo->anterior;
  free(pilha->topo);
  pilha->topo = anterior;
  return valor;
}

/*
 * Obtem o elemento do topo da pilha, sem removê-lo.
 * 
 * @param pilha: Pilha que desejo conhecer o valor que está no topo.
 * @return Retorna o valor que se encontra no topo da pilha.
 */
int PilhaInt_obter(PilhaInt* pilha) {
  return pilha->topo->valor;
}

/*
 * Verifica se uma pilha esta vazia.
 * 
 * @param pilha: Pilha que desejo saber se esta vazia ou não.
 * @return Retorna 1 caso a pilha esteja vazia. Caso contrário, retorna 0.
 */
int PilhaInt_vazia(PilhaInt* pilha) {
  if (pilha->topo == NULL) 
    return 1;
  return 0;
}

/*
 * Imprime todos os elementos da pilha, começando pelo topo.
 *
 * @param pilha: Pilha de inteiros a ser impressa.
 */
void PilhaInt_imprimir(PilhaInt* pilha) {
  NoPilhaInt* auxiliar = pilha->topo;

  printf("PilhaInt(");
  while (auxiliar != NULL && auxiliar->anterior != NULL) {
    printf("%d, ", auxiliar->valor);
    auxiliar = auxiliar->anterior;
  }
  if (auxiliar != NULL) {
    printf("%d)", auxiliar->valor);
  }
}

#endif
