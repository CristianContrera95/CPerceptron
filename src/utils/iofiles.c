//
// Created by anybody on 13/11/19.
//

#include "iofiles.h"


char *read_line(FILE *f, const int buffer) {

    int buff_size = buffer;
    int chars_readed = 0;
    char c;
    char *line = (char*) malloc (buff_size*sizeof(char));

    if (f == NULL) {
        printf("Error: file pointer is null.\n");
        exit(1);
    }

    while ((c = fgetc(f)) != '\n') {
        if (c == EOF) {
            /* we assume that no line was created */
            free(line);
            if (chars_readed != 0) {
                printf("Error: file has a bad format (last line).\n");
                exit(1);
            }
            return "EOF";
        }

        line[chars_readed++] = c;
        if (chars_readed == buff_size) {
            buff_size += (int)buffer*0.2;
            line = realloc(line, (buff_size+1)*sizeof(char));
        }
    }
    line[chars_readed] = '\0';

    return line;
}


data_frame read_csv(csv_file file, const int tag) {

    int row = 0, col = 0, line_len = 0;
    long double num;
    char *line, *str_value;
    data_frame df = calloc(1, sizeof(struct data_frame_st));

    FILE* f = fopen(file->file_path, "r");
    if (f == NULL)
        printf("Error: Couldn't open csv file in path: %s", file->file_path);

    // create data-frame matrix
    df->value = (long double**)malloc(file->num_rows*sizeof(long double*));
    for (int i = 0; i < file->num_rows; i++)
        df->value[i] = (long double*)malloc(file->num_cols*sizeof(long double));

    if (file->header)
        free(read_line(f, 200));

    // fill data-frame matrix
    while (strcmp((line = read_line(f, file->num_cols*10)), "EOF") != 0) {
        str_value = strtok(line, file->sep);
        col = 0;
        while(str_value != NULL) {
            sscanf(str_value, "%Lf", &num);
            df->value[row][col] = num;
            str_value = strtok(NULL, file->sep);
            col++;
        }
        row++;
        free(line);
    }
    fclose(f);

    df->row_size = row;
    df->col_size = col;
    df->tag = tag;
    return df;
}


config parse_config(const char *file_name) {

    int n_value, line_num = 0;
    char *line, *null;  // null is to hide the warnings
    config cfg = calloc(1, sizeof(struct config_st));

    FILE* f = fopen(file_name, "r");
    if (f == NULL)
        printf("Error: Couldn't open cfg file in path: %s", file_name);

    cfg->file_path = calloc(100, sizeof(char));
    cfg->threshold_fun = calloc(10, sizeof(char));

    while (strcmp((line = read_line(f, 100)), "EOF") != 0) {
        if (sscanf(line, "file_path=%s\n", cfg->file_path))
            ;
        else if (sscanf(line, "columns=%d\n", &cfg->cols))
            ;
        else if (sscanf(line, "rows=%d\n", &cfg->rows))
            ;
        else if (sscanf(line, "tag=%d\n", &cfg->tag))
            ;
        else if (sscanf(line, "threshold=%f\n", &cfg->threshold))
            ;
        else if (sscanf(line, "threshold_function=%s\n", cfg->threshold_fun))
            ;
        else if (sscanf(line, "learning_rate=%f\n", &cfg->learning_rate))
            ;
        else if (sscanf(line, "max_iter=%d\n", &cfg->max_iter))
            ;
        else if (sscanf(line, "tol=%f\n", &cfg->tol))
            ;
        else if (sscanf(line, "shuffle=%d\n", (int*)&cfg->shuffle))
            ;
        else if (sscanf(line, "#%s\n", null_) || sscanf(line, ";%s\n", null_) || strcmp(line, "\n"))
            ;
        else
            printf("Error: bad line %d in config file\n\t\"%s\"", line_num, line);
        line_num++;

        //free(line);
    }
    fclose(f);

    return cfg;
}
