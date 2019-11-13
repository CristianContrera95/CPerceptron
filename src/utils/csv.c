/*
 Created by Cristian Contrera on 11/11/19.
*/

#include "csv.h"

#define BUFFER_SIZE 1000


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


data_frame read_csv(csv_file file) {

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
    while (strcmp((line = read_line(f, file->num_cols*10)), "EOF")) {
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
    return df;
}
