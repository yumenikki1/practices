#include <stdio.h>

int main () {
int tag=0;
int guion=0;
int nose = 0;
char c;
while ((c = getchar()) != EOF) {
    if (c=='<'){
            tag=1;
            nose = 1;}
    else if (c=='>'){
            tag=0;
    }
         else if (tag == 0 && c != '>') {
                 if (c == ' ' && guion == 1){
            putchar('_');} else{
            putchar(c);}
            }
    else {
        if (nose == 1 && ((c == 'h')||(c=='s'))){
        guion = 1;}
           else if (c == '/'){
                guion = 0;
            }
            nose = 0;
            }
            }
}

