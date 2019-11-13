#include <stdio.h>
#include "../utils/csv.h"
#include "../utils/parse_cfg.h"


int main(int argc, char const *argv[]){

    if (strcmp(argv[1], "read_csv") || strcmp(argv[1], "all")) {
        printf("\n\n-------------Test read_csv() ------------------\n\n");
        csv_file f = calloc(1, sizeof(struct csv_file_st));
        f->file_path = "../../data/df_example.csv";
        f->header = 1;
        f->sep = ",";
        f->num_cols = 4;
        f->num_rows = 3;
        data_frame df = read_csv(f);

        printf("df.shape: (%d, %d)\n", df->row_size, df->col_size);
        for (int i = 0; i < df->row_size; i++) {
            printf("col %d: ", i);
            for (int j = 0; j < df->col_size; j++)
                printf("%Lf ", df->value[i][j]);
            printf("\n");
        }
    }


    if (strcmp(argv[1], "parse_config") || strcmp(argv[1], "all")) {
        printf("\n\n-------------Test parse_config() ------------------\n\n");
        config cfg = parse_config("../../cfg/perceptron.cfg");
        printf("%s\n%d, %d\n", cfg->file_path, cfg->cols, cfg->rows);
    }

    return 0;
}
