/*
 Created by Cristian Contrera on 11/11/19.
*/

#ifndef CPERCEPTRON_PARSE_CFG_H
#define CPERCEPTRON_PARSE_CFG_H

#include <stdio.h>
#include "./csv.h"


struct config_st {
    char *file_path;
    int cols;
    int rows;
    int tag;

    float threshold;
    char *threshold_fun;
    float learning_rate;
};


typedef struct config_st *config;


config parse_config(const char *file_name);

#endif //CPERCEPTRON_PARSE_CFG_H
