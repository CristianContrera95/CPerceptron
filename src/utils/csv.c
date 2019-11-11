/*
 Created by Cristian Contrera on 11/11/19.
*/

#include "csv.h"

#define BUFFER_SIZE 1000


char *read_line(FILE *f) {

    int buff_size = BUFFER_SIZE;
    int chars_readed = 0;
    char c;
    char *line = (char*) malloc (buff_size*sizeof(char));

    if (f == NULL) {
        printf("Error: file pointer is null.");
        exit(1);
    }

    while ((c = fgetc(f)) != '\n') {
        if (c == EOF) {
            /* we assume that no line was created */
            free(line);
            if (chars_readed != 0)
                printf("Error: file has a bad format (last line).");
            return "EOF";
        }

        line[chars_readed++] = c;
        if (chars_readed == buff_size) {
            buff_size = buff_size + 200;
            line = realloc(line, (buff_size+1)*sizeof(char));
        }
    }
    line[chars_readed++] = '\0';

    return line;
}


data_frame *read_csv(csv_file* file) {

    int rows = 0;
    char *line;

    FILE* f = fopen(file->file_path, "r");
    if (!f)
        printf("Error: Couldn't open csv file in path: %s", file->file_path);

    while ((line = read_line(f)) != "EOF") {
        printf("line %d: %s\n", rows++, line);
        /* TODO:
         *  1- split line by commas and cast these values in double
        */
    }
    fclose(f);

}
