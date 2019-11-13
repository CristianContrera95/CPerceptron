/*
 Created by Cristian Contrera on 11/11/19.
*/

#include "parse_cfg.h"


config parse_config(const char *file_name) {

    int n_value, line_num = 0;
    char *line;
    config cfg = calloc(1, sizeof(struct config_st));

    FILE* f = fopen(file_name, "r");
    if (f == NULL)
        printf("Error: Couldn't open cfg file in path: %s", file_name);

    cfg->file_path = calloc(100, sizeof(char));
    cfg->threshold_fun = calloc(10, sizeof(char));

    while (strcmp((line = read_line(f, 100)), "EOF")) {
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
        else if (sscanf(line, "#%s\n", NULL) || sscanf(line, ";%s\n", NULL) || strcmp(line, "\n"))
            ;
        else
            printf("Error: bad line %d in config file\n\t\"%s\"", line_num, line);
        line_num++;

        //free(line);
    }
    fclose(f);

    return cfg;
}
