#include <stdio.h>
#include <ctype.h>
#define ON 1
#define OFF 0

int main() {
  char c;
  int s = OFF, p, q = OFF, e = OFF;

  while ((c = getchar()) != EOF) {
    p = OFF;
    if (ispunct(c) && ((c != '(') && (c != ')') && (c != '"')&&(c != '[') && (c != ']')&&(c != '{') && (c != '}'))){
      p = ON;
      }
      switch(c){
    case '"':
        if (q == OFF){
           q = ON;
        } else q = OFF;
        break;
    case '(':
    case '[':
    case '{':
      e = ON;
      break;
    case ']':
    case '}':
    case ')':
      e = OFF;
      break;
    }
      if (isdigit(c) && e == OFF && !s && !q) {
	putchar('X');
	s = ON;
      }
     if ((!isdigit(c)) && !e && s){
        s=OFF;
     }
    if (!p && !s) {
      putchar(c);
    }
}
  return 0;
}
