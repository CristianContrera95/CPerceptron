/*
 Created by Cristian Contrera on 11/11/19.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct csv_file_st {
    char *file_path;
    char *sep;
    char *end_line;
    _Bool header;
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


data_frame *read_csv(csv_file* file);