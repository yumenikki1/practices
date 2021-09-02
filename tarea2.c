#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define LEN 10
int prime(int i) {
  int d;
  for (d = 2; d < i; d++) {
    if (i % d == 0) {
      return FALSE;
    }
  }
  return TRUE;
}
void binarioinvertido(int a, int m){
while (a > 0 || m > 0) {
    printf("%d", a % 2);
    a = a >> 1;
    m--;
  }
}
int main() {
    int k = 12;
  int i;
    int r=1;
  for (i = 1; r <= k; i++){
  if (prime(i) == TRUE){
       binarioinvertido(i, LEN);
  printf("\n");
  r++;
}
}
  return 0;
}
