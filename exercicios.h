#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int *gasto_min(int valor, int *valores, int n)
{
  int *qtds = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++)
  {
    qtds[i] = valor / valores[i];
    valor -= qtds[i] * valores[i];
  }
  //        valor -= (qtds[i] = valor / valores[i]) * valores[i];

  return qtds;
}

void ex1()
{
  int seg;
  printf("Informe um tempo em segundos: ");
  scanf("%d", &seg);
  int tempos[] = {3600, 60, 1};
  int *tempo = gasto_min(seg, tempos, 3);
  printf("Formatado: %02d:%02d:%02d\n", tempo[0], tempo[1], tempo[2]);
  free(tempo);
}

void ex2()
{
  int v[3], i;
  float soma = 0;
  printf("Informe 3 valores inteiros\n");
  for (i = 0; i < 3; i++)
  {
    printf("%d: ", i);
    scanf("%d", &v[i]);
    soma += v[i];
  }
  printf("A media destes valores e: %f\n", soma / 3.0);
}

void ex3()
{
  float h, v0, ang;
  printf("Tragetória parabólica\n");
  printf("Digite a altura relativa ao solo de onde o progétil é lançado: ");
  scanf("%f", &h);
  printf("Digite a velocidade inicial em m/s: ");
  scanf("%f", &v0);
  printf("Digite o angulo de lançamento: ");
  scanf("%f", &ang);
  float g = 9.81;
  float v0y = v0 * sin(ang);
  float t = (v0y + h) / g;
  float v0x = v0 * cos(ang);
  // v0*cos(ang) * t;
  // v0*cos(ang) * (v0y / g);
  // v0*cos(ang) * v0*sen(ang) / g;
  // v0^2 * cos(ang) * sen(ang) / g;
  float D = v0x * t;
}

void ex4()
{
  int num;
  printf("Informe um numero inteiro: ");
  scanf("%d", &num);
  if (num % 2 == 0)
    printf("%d e par.\n", num);
  else
    printf("%d e impar.\n", num);
}

void ex5()
{
  int v[3], i, soma = 0, maior = 0, iguais = 0;
  printf("Informe tres valores\n");
  for (i = 0; i < 3; i++)
  {
    printf("%d: ", i);
    scanf("%d", &v[i]);
    soma += v[i];
    if (v[0] == v[i])
      ++iguais;
  }
  for (i = 0; i < 3; i++)
  {
    if (soma - v[i] <= v[i])
    {
      printf("Não e possivel formar um triangulo com esses valores.\n");
      break;
    }
  }

  switch (iguais)
  {
  case 1:
    printf("Estes valores formar um triangulo escaleno.\n");
    break;
  case 2:
    printf("Estes valores formam um triangulo isosceles.\n");
    break;
  case 3:
    printf("Estes valores formam um triangulo equilatero.\n");
    break;
  }
}

void ex6()
{
  float menor, medio, maior;
  printf("Digite 3 valores\n");
  printf("1: ");
  scanf("%f", &menor);
  medio = maior = menor;

  printf("2: ");
  scanf("%f", &medio);
  if (medio > maior)
  {
    menor = maior;
    maior = medio;
  }
  else if (medio < menor)
  {
    maior = menor;
    menor = medio;
  }
  printf("3: ");
  scanf("%f", &medio);
  int temp;
  if (medio > maior)
  {
    printf("Troca\n");
    temp = maior;
    maior = medio;
    medio = temp;
  }
  else if (medio < menor)
  {
    temp = menor;
    menor = medio;
    medio = temp;
  }

  printf("O maior valor foi: %f\n", maior);
  printf("O valor medio foi: %f\n", medio);
  printf("O menor valor foi: %f\n", menor);
}

void ex7()
{
  char c;
  float v1, v2, r;
  printf("Digite um simbulo de operacao(+,-,*,/): ");
  scanf("%c", &c);
  printf("Digite dois numeros reais\n1: ");
  scanf("%f", &v1);
  printf("2: ");
  scanf("%f", &v2);
  switch (c)
  {
  case '+':
    r = v1 + v2;
    break;
  case '-':
    r = v1 - v2;
    break;
  case '*':
    r = v1 * v2;
    break;
  case '/':
    r = v1 / v2;
    break;
  }
  printf("O resultado e: %f\n", r);
}

void ex8()
{
  int v;
  do
  {
    printf("Informe sua nota: ");
    scanf("%d", &v);
  } while (v < 0 || v > 100);

  if (v >= 70)
    printf("Voce esta aprovado!\n");
  else if (v < 70 && v >= 40)
    printf("Voce esta na media!\n");
  else
    printf("Voce foi repovado!\n");
}

void ex9()
{
  char unidade[11][7] = {"zero", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez"};
  char entre10e20[9][10] = {"onze", "doze", "treze", "catorze", "quinze", "dezeseis", "dezessete", "dezoito", "dezenove"};
  char dezena[9][10] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa", "cem"};
  int v;
  do
  {
    printf("Digite um numero inteiro: ");
    scanf("%d", &v);
  } while (v < 0 || v >= 100);
  char str[64];
  int d = v / 10;
  int u = v % 10;
  if (v <= 10)
  {
    strcpy(str, unidade[v]);
  }
  else if (v < 20)
  {
    strcpy(str, entre10e20[v - 11]);
  }
  else
  {
    strcpy(str, dezena[d - 2]);
    if (u != 0)
    {
      strcat(str, " e ");
      strcat(str, unidade[u]);
    }
  }
  printf("O numero digitado foi o %s\n", str);
}

void ex10()
{
  float vmax, v;
  printf("Informe a velocidade maxima da avenida: ");
  scanf("%f", &vmax);
  printf("Informe a velocidade do motorista: ");
  scanf("%f", &v);

  if (v <= vmax)
    printf("O motorista nao pagou multa.\n");
  else
    printf("O motorista pagou R$ %.2f de multa.\n", ((v - vmax) * 5));
}

int eh_bissexto(int ano)
{
  return ((!(ano % 4) && (ano % 100)) || !(ano % 400));
}

int dias_do_mes(int mes, int ano)
{
  switch (mes)
  {
  case 1: return 31;
  case 2: return eh_bissexto(ano) ? 29 : 28;
  case 3: return 31;
  case 4: return 30;
  case 5: return 31;
  case 6: return 30;
  case 7: return 31;
  case 8: return 31;
  case 9: return 30;
  case 10: return 31;
  case 11: return 30;
  }
  return 31;
}

void ex11()
{
  int mes, ano;
  do
  {
    printf("Digite um mes: ");
    scanf("%d", &mes);
  } while (mes < 0 || mes > 12);
  do
  {
    printf("Digite um ano: ");
    scanf("%d", &ano);
  } while (ano < 0);

  char *meses[] = {"janeiro\0", "fevereiro\0", "marco\0", "abril\0", "maio\0", "junho\0", "julho\0", "agosto\0", "setembro\0", "outubro\0", "novembro\0", "dezembro\0"};
  int dias = dias_do_mes(mes, ano);
  if (eh_bissexto(ano))
    printf("(Ano bissexto) ");
  printf("O mes de %s tem %d dias.\n", meses[mes - 1], dias);
}

void ex12()
{
  int valor;
  printf("Informe um dado valor em R$: ");
  scanf("%d", &valor);

  int notas[] = {100, 50, 20, 10, 5, 2, 1};
  char str_notas[7][10] = {"cem", "cinquenta", "vinte", "dez", "cinco", "dois", "um"};
  int n_notas = sizeof(notas) / sizeof(int);
  int *qtds = gasto_min(valor, notas, n_notas);
  for (int i = n_notas - 1; i >= 0; --i)
    printf("% 4d R$(%9s): %d\n", notas[i], str_notas[i], qtds[i]);
  free(qtds);
}

void ex13()
{
  int h, i;
  float valorh, soma = 0;
  printf("Informe a quantidade de horas trabalhadas: ");
  scanf("%d", &h);
  printf("Informe o valor por horas trabalhadas: ");
  scanf("%f", &valorh);

  int mais60 = h - 60 > 0 ? h - 60 : 0;
  int mais40 = h - 40 - mais60 > 0 ? h - 40 - mais60 : 0;
  int normal = h - mais40 - mais60;

  int qtds[3] = {normal, mais40, mais60};
  float valores[3] = {normal, mais40, mais60};
  float porcentagem[3] = {0, 0.5, 1};

  for (i = 0; i < 3; i++)
  {
    valores[i] *= valorh;
    valores[i] += (porcentagem[i] * valores[i]);
    soma += valores[i];
  }
  printf("Valores recebidos pelas horas trabalhadas\n");
  for (i = 0; i < 3; i++)
    printf("Para %dh: %.2f R$\n", qtds[i], valores[i]);
  printf("Salario total: %.2f R$\n", soma);
}

bool eh_especial_1(unsigned int num)
{
  if (num < 1000 || num > 9999)
    return false;
  int raiz = sqrt(num);
  // (fabsf(roundf(sqrt(num)) - sqrt(num)) <= 0.00001f)  --> verifica se um float é inteiro
  // Se a raiz quadrada é inteira, podemos continuar verificando
  if (raiz * raiz == num)
  {
    char strnum[16], buff1[5], buff2[5];
    sprintf(strnum, "%d", num);            // Transformo meu inteiro em uma string
    strncpy(buff1, strnum, 2);             // Pego os 2 primeiro digitos
    strcpy(buff2, strnum + 2);             // Pego os 2 ultimos digitos
    if (atoi(buff1) + atoi(buff2) == raiz) // Verifico se a soma é igual a raiz
      return true;
  }
  return 0;
}

void ex17()
{
  for (int i = 1000; i < 10000; i++)
    if (eh_especial_1(i))
      printf("%d ", i);
  printf("\n");
}

void ex18()
{
  int a, b, c, i;
  a = b = 1;
  printf("Os 15 primeiros termos da serie de Fibonacci sao\n");
  printf("Termo  1: %d\n", a);
  printf("Termo  2: %d\n", b);
  for (i = 3; i <= 15; i++)
  {
    c = a + b;
    printf("Termo %2.d: %d\n", i, c);
    a = b;
    b = c;
  }
}

bool eh_perfeito(unsigned long long int num)
{
  unsigned long long int soma = 0, i;
  for (i = num / 2; i > 0; i--)
    if (num % i == 0)
      soma += i;
  return soma - num == 0;
}

int eh_primo(int x) {
  if (x < 4) return 1;
  if (x % 2 == 0 || x % 3 == 0) return 0;

  int n = sqrt(x);

  if (x % n == 0) return 0; 

  for (int i = 5, w = 2; i < n; i = i + w, w = 6 - w)
    if (x % i == 0)
      return 0;

  return 1;
}

void ex19()
{
  unsigned long long int i, perf = 0;
  unsigned long long int lim = 100;
  // p lim pertencente [10000, 100000], existe lim em que o primeiro for é mais rapida que a 2
  // Porem nem todos os primos forma numeros perfeitos
  for (i = 2;; i++)
  {
    if (eh_primo(i))
    {
      perf = pow(2, i - 1) * (pow(2, i) - 1);
      if (perf < 0 || perf >= lim)
        break;
      if (eh_perfeito(perf))
        printf("%lld ", perf);
    }
  }
  printf("\n");
  for (i = 2; i <= lim; i += 2)
    if (eh_perfeito(i))
      printf("%lld ", i);
  printf("\n");
}

void ex20()
{
  double num;
  do
  {
    printf("Informe um numero positivo: ");
    scanf("%lf", &num);
  } while (num <= 0);

  if (eh_primo(num))
    printf("O numero %.0lf e primo.\n", num);
}

void ex22()
{
  int n1, n2;
  printf("Informe dois numeros\n1: ");
  scanf("%d", &n1);
  printf("2: ");
  scanf("%d", &n2);

  int quoc = 0, rest;
  int t = n1 >= n2 ? n1 : n2;
  int c = n1 >= n2 ? n2 : n1;
  while (t > 0)
  {
    t -= c;
    quoc++;
  }
  quoc = t != 0 ? quoc - 1 : quoc;
  rest = t != 0 ? t + c : t;
  printf("O quociente da divisao e: %d\n", quoc);
  printf("O resto da divisao e: %d\n", rest);
}

void ex23()
{

}

double raiz_quadrada(double X)
{
  double xant = X, xs = X + 1;
  while (xant - xs != 0)
  {
    xant = xs;
    xs = (xs + (X / xs)) / 2;
  }
  return xs;
}

void ex44()
{
  double x;
  printf("Raiz quadrada numericamente\n");
  do
  {
    printf("Digite um numero positivo: ");
    scanf("%lf", &x);
  } while (x <= 0);
  printf("A raiz quadrada de %.2f e %lf.\n", x, raiz_quadrada(x));
  printf("A raiz real e: %lf\n", sqrt(x));
}

void ex45() {
  unsigned int x, y, m;
  unsigned int temp;
  x = y = 0;

  printf("Inverter número\n");

  printf("Informe um número positivo: ");
  scanf("%u", &x);

  int n = log(x) / log(10);
  m = pow(10, n);

  while (x > 0) {
    y += (x % 10) * m;
    x /= 10;
    m /= 10;
  }

  printf("O número %u invertido é %u\n", x, y);
}

int minutosDeJogo(int h1, int m1, int h2, int m2) {
  int inicio = h1 * 60 + m1;
  int fim = h2 * 60 + m2;
  if (inicio < fim) return inicio - fim;

  int dia = 24 * 60;
  return (dia - inicio) + fim;
}

void ex48() {
  printf("Tempo do jogo\n");
  printf("Digite o horário inicial no período de 24 horas (hh:mm): ");
  int h1, m1, h2, m2;
  scanf("%d:%d", &h1, &m1);
  printf("Digite o horário final no período de 24 horas (hh:mm): ");
  scanf("%d:%d", &h2, &m2);

  printf("A duração em minutos do jogo é de: %d min\n", minutosDeJogo(h1, m1, h2, m2));
}

int arredonda(double x) {
  if (x > 0) return x + 0.5;
  return -arredonda(-x);
}

void ex49() {
  printf("Arredondar número\n");
  printf("Digite um número flutuante: ");
  double x;
  scanf("%lf", &x);
  printf("O número %.2lf arredondado é %d\n", x, arredonda(x));
}

unsigned char calcularParidade(unsigned char b) {
  int bits;
  for (bits = 0; b > 0; b >>= 1)
    bits += b & 1;
  return bits % 2;
}

void ex50() {
  printf("Verifica se a quantidade de bits é ímpar");

  printf("Digite um valor de 0 a 255: ");
  unsigned char x;
  getchar();

  printf("A paridade do valor %d é: %d\n", x, calcularParidade(x));
}

int fibonacci(int x) {
  if (x <= 2) return 1;
  return fibonacci(x - 1) + fibonacci(x - 2);
}

void ex52() {
  printf("Fibonacci recursivo\n");

  int x;
  printf("Informe um número: ");
  scanf("%d", &x);

  printf("O %dº número de fibonnaci é: %d\n", x, fibonacci(x));
}

int somaDigitos(int n) {
  if (n < 0) return somaDigitos(-n);
  if (n == 0) return 0;
  return n % 10 + somaDigitos(n / 10);
}

void ex56() {
  printf("Soma digitos recursivo\n");
  int x;
  printf("Informe um número: ");
  scanf("%d", &x);

  printf("A soma dos digitos de %d é: %d\n", x, somaDigitos(x));
}

int somatorio(int n) {
  if (n <= 0) return 0;
  return n + somatorio(n - 1);
  // return n <= 0 ? 0 : n + somatorio(n - 1);
}

void ex57() {
  printf("Somatorio recuursivo\n");
  int x;
  printf("Informe um número: ");
  scanf("%u", &x);
  
  printf("A soma dos numeros até %d é: %d\n", x, somatorio(x));
}

int contaDigitos(int x, int d) {
  if (x <= 0) return 0;
  if (x % 10 == d) return 1 + contaDigitos(x / 10, d);
  return contaDigitos(x / 10, d);
  // return x <= 0 ? 0 : (x % 10 == d) + contaDigitos(x / 10, d);
}

void ex58() {
  printf("Conta um determinado digito de um número\n");

  int x, d;
  printf("Informe um número e um digito: ");
  scanf("%d %d", &x, &d);

  printf("O número de vezes que %d aparece em %d é de: %d\n", d, x, contaDigitos(x, d));
}

void ex63() {
  printf("Entendendo com ponteiros\n");
  int a, b, c, d;
  float e, f, g, h;
  char v[10];
  int x;
  float *p = &f;
  p++;
  if ((void *) p == (void *) &b) printf("Apontando para b\n");
  else if ((void *) p == (void *) &c) printf("Apontando para c\n");
  else if ((void *) p == (void *) &d) printf("Apontando para d\n");
  else if ((void *) p == (void *) &e) printf("Apontando para e\n");
  else if ((void *) p == (void *) &f) printf("Apontando para f\n");
  else if ((void *) p == (void *) &g) printf("Apontando para g\n");
  else if ((void *) p == (void *) &h) printf("Apontando para h\n");
  else if ((void *) p == (void *) v) printf("Apontando para v\n");
  else if ((void *) p == (void *) &x) printf("Apontando para x\n");
  else printf("Apontando para o limbo\n");
}