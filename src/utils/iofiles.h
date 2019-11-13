/*
 Created by anybody on 13/11/19.
*/

#ifndef CPERCEPTRON_IOFILES_H
#define CPERCEPTRON_IOFILES_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
#ifdef WINDOWS_OS
#include <windows.h> // this is for Windows
#endif
*/

#define BUFFER_SIZE 1000


struct config_st {
    char *file_path;
    int cols;
    int rows;
    int tag;

    float threshold;
    char *threshold_fun;
    float learning_rate;
    int max_iter;
    float tol;
    _Bool shuffle;
};


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
    int tag;
};


typedef struct csv_file_st *csv_file;
typedef struct data_frame_st *data_frame;
typedef struct config_st *config;


/* functions list */

char *read_line(FILE *f, int buffer);

data_frame read_csv(csv_file file);

config parse_config(const char *file_name);

#endif //CPERCEPTRON_IOFILES_H
