//
// Created by anybody on 13/11/19.
//

#ifndef CPERCEPTRON_DATA_FRAME_H
#define CPERCEPTRON_DATA_FRAME_H

#include <stdlib.h>
#include <math.h>


struct data_frame_st {
    int row_size;
    int col_size;
    long double **value;
    int tag;
};

#endif //CPERCEPTRON_DATA_FRAME_H
