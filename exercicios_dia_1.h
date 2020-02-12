#include <stdio.h> // printf, scanf
#include <math.h> // sqrt

// 1: (int - fácil): Dado um número inteiro positivo n, calcular a soma dos n primeiros números inteiros positivos
int somar_n_positivos_com_for(int n) {
  int soma = 0;

  for (int i = 1; i <= n; i++) {
    soma += i;
  }

  return soma;
}

int somar_n_positivos_com_formula(int n) {
  return (n * (n + 1)) / 2;
}

// 2: (int - médio): Faça uma função que verifica se um número é primo ou não.
int numero_e_primo(int numero) {
  if (numero < 4) return 1;

  for (int i = 2; i < numero; i++) {
    if (numero % i == 0) {
      return 0;
    } 
  }

  return 1;
}

int numero_e_primo_melhorado(int numero) {
  if (numero < 4) return 1;
  
  if (numero % 2 == 0) return 0;
  if (numero % 3 == 0) return 0;

  int limite = sqrt(numero);

  if (numero % limite == 0) return 0; 

  int w = 2;
  for (int i = 5; i < limite; i = i + w, w = w == 2 ? 4 : 2) {
    if (numero % i == 0) {
      return 0;
    } 
  }

  return 1;
}

// 3: (int - difícil): Dado uma quantidade em centavos, mostrar o menor número de moedas necessárias para formar esta quantia.
// - Dado 90 centavos, sendo que há moedas de 1, 5, 10, 25 e 50, quantas moedas no mínimo, serão necessárias para formar 90 centavos?
void mostrar_menor_numero_de_moedas(int centavos) {
  int total = centavos;
 
  int cinquenta = 0;
  int vinte_cinco = 0;
  int dez = 0;
  int cinco = 0;
  int um = 0;
  
  while (total >= 50) {
    total -= 50;
    cinquenta = cinquenta + 1;
  }
  while (total >= 25) {
    total -= 25;
    vinte_cinco = vinte_cinco + 1;
  }
  while (total >= 10) {
    total -= 10;
    dez = dez + 1;
  }
  while (total >= 5) {
    total -= 5;
    cinco = cinco + 1;
  }
  while (total >= 1) {
    total -= 1;
    um = um + 1;
  }

  printf("O valor de %d centavos pode ser dividido em: \n", centavos);
  printf("%d moedas de cinquenta (50)\n", cinquenta);
  printf("%d moedas de vinte_cinco (25)\n", vinte_cinco);
  printf("%d moedas de dez (10)\n", dez);
  printf("%d moedas de cinco (5)\n", cinco);
  printf("%d moedas de um (1)\n", um);
}

void mostrar_menor_numero_de_moedas_melhorado(int centavos) {
  int total = centavos;
 
  int cinquenta = total / 50;
  total -= cinquenta * 50;

  int vinte_cinco = total / 25;
  total -= vinte_cinco * 25;

  int dez = total / 10;
  total -= dez * 10;

  int cinco = total / 5;
  total -= cinco * 5;
  
  int um = total;

  printf("O valor de %d centavos pode ser dividido em: \n", centavos);
  printf("%d moedas de cinquenta (50)\n", cinquenta);
  printf("%d moedas de vinte_cinco (25)\n", vinte_cinco);
  printf("%d moedas de dez (10)\n", dez);
  printf("%d moedas de cinco (5)\n", cinco);
  printf("%d moedas de um (1)\n", um);
}

int exercicios_dia_1() {
  printf("Exercício 1\n");
  printf("%d\n", somar_n_positivos_com_for(100));
  printf("%d\n", somar_n_positivos_com_formula(100));

  printf("\nExercício 2\n");
  int primos = 0;
  for (int i = 1; primos <= 100; i++) {
    if (numero_e_primo_melhorado(i)) {
      printf("%d ", i);
      primos++;
    }
  }
  printf("\n");

  printf("\nExercício 3\n");
  mostrar_menor_numero_de_moedas(1234);

  printf("\n");
  mostrar_menor_numero_de_moedas_melhorado(1234);

  return 0;
}
