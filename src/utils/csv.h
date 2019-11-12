/*
 Created by Cristian Contrera on 11/11/19.
*/
#ifndef CPERCEPTRON_CSV_H
#define CPERCEPTRON_CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct csv_file_st {
    char *file_path;
    char *sep;
    char *end_line;
    _Bool header;
    int num_cols;
    int num_rows;
    /* TODO:
     *  1- Add skip lines
     */
};

struct data_frame_st {
    int row_size;
    int col_size;
    long double **value;
};


typedef struct csv_file_st csv_file;
typedef struct data_frame_st data_frame;


/* functions list */

char *read_line(FILE *f);

data_frame *read_csv(csv_file* file);


#endif //CPERCEPTRON_CSV_H
