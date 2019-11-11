#include <stdio.h>

typedef char *string_p;
typedef char string_a[];


void main () {
    printf("Main func\n\n");
    string_p var1 = "Hola mundo";
    string_a var2 = "Hola mundo";

    // print default vars
    printf("var1: %s\n", var1);
    printf("var2: %s\n", var2);

    // change default vars
//    var1 += 4;
//    *var1 = '-';
//    var1 -= 4;

    for(int i=0; i<9; i++) {
        if(var1[i] == ' ' ){
            var1[i] = '-';
        }
        printf("var1: %c\n", var1[i]);
    }

    var2[4] = '-';
    printf("var2: %s\n", var2);
}