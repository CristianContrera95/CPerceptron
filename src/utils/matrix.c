//
// Created by anybody on 13/11/19.
//

#include "matrix.h"
#include <stdio.h>

long double dot_product(long double *matrix_1, long double *matrix_2, const int len) {

    long double sum = 0;

    for (int i = 0; i < len; i++) {
        printf("%Lf * %Lf = %Lf\n", matrix_1[i], matrix_2[i], matrix_1[i] * matrix_2[i]);
        sum += matrix_1[i] * matrix_2[i];
    }
    printf("\n");
    return sum;
}
