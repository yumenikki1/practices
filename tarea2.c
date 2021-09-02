#include <stdio.h>
#define LEN 10  //Longitud de caracteres en binario

int primo(int i) {
  int d;
  for (d = 2; d < i; d++) {
    if (i % d == 0) {
      return 0;
    }
  }
  return 1;
}
void binarioinvertido(int a, int m){
    while (a > 0 || m > 0) {
    printf("%d", a % 2);
    a = a >> 1;
    m--;
    }
}
int main() {
    int k = 10;  // cantidad de numeros primos a imprimir en binario
    int i;
    int r=1;
    for (i = 1; r <= k; i++){
        if (primo(i) == 1){
        binarioinvertido(i, LEN);
        printf("\n");
        r++;
}
}
  return 0;
}
