#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define strlimit 50
#define ACTIVE 1
#define INACTIVE 0

int main(){
int s[strlimit];
char str[strlimit];
int n = -1, top = -1, o, a, e, succ;
a = o = e =  succ = 0;
int oper = 0, nums = 0;
while (1){
// ASK FOR INPUT
if (e == 0) {
scanf("%s", &str);
e = 1;
n++;
// EVALUATE IF IT'S A VALID INPUT
       for (int i = 0; i <= strlen(str); i ++){
        if (isdigit(str[n])) nums++;
        if (ispunct(str[n])) oper++;
        n++;
        }
        if (oper < (nums - 1)){
        printf("too many operands\n");
        o = a = oper = nums = 0;
        n = top = -1;
        succ = 1;
        continue;
    }
        if (oper > (nums - 1)){
        printf("too many operators\n");
        o = a = oper = nums = 0;
        n = top = -1;
        succ = 1;
        continue;
    }
    n = -1;
    continue;
}
//WHILE THE INPUT STRING IS NOT A NEW LINE
if (str[n] != '\n'){
n++;
if (isdigit(str[n]))
{
a = str[n] - '0';
s[++top] = a;
continue;
}
if (ispunct(str[n])){
        if (top-1 < 0 && succ == 0){
            printf("syntax error\n");
            succ = 1;
            continue;
        }
switch (str[n]){
case '+':
o = s[top -1] + s[top];
top = top - 2;
s[++top] = o;
break;
case '-':
o = s[top -1] - s[top];
top = top - 2;
s[++top] = o;
break;
case '*':
o = s[top -1] * s[top];
top = top - 2;
s[++top] = o;
break;
case '/':
o = s[top -1] / s[top];
top = top - 2;
s[++top] = o;
break;
default:
printf("only + - * / operators are known\n");
e = o = a = oper = nums = 0; succ = 1; n = top = -1;
break;
}
continue;
}
}
// IF IT WAS A VALID INPUT
if (succ == 0){
printf("The value of the expresion is: %d\n", o);
e = o = a = oper = nums = 0;
n = top = -1;
}
else {e = o = a = oper = nums = succ = 0; n = top = -1;} // ELSE JUST RESET
}
return 0;
}
