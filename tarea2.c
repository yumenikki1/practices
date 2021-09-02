#include <stdio.h>
#define LEN 10   //Longitud de caracteres en binario

int primo(int i) {
  int d;
  for (d = 2; d < i; d++) {
    if (i % d == 0) {
      return 0;
    }
  }
  return 1;
}
void binario(int a, int m){
    int g = m;
    int b[m];
    while (a > 0 || g > 0) {
    b[--g] = a % 2;
    a = a >> 1;
    }
     for (g = 0; g < m; g++) {
    printf("%d", b[g]);
  }
}

int main() {
    int k = 10;   // cantidad de numeros primos a imprimir en binario
    int i;
    int r=1;
    for (i = 1; r <= k; i++){
        if (primo(i) == 1){
        binario(i, LEN);
        printf("\n");
        r++;
}
}
  return 0;
}
