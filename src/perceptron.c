/*
 Created by anybody on 13/11/19.
*/

#include "perceptron.h"

int main (int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Error: few args.");
        exit(1);
    }

    config cfg = parse_config(argv[1]);

    csv_file csv = calloc(1, sizeof(struct csv_file_st));
    csv->file_path = cfg->file_path;
    csv->num_rows = cfg->rows;
    csv->num_cols = cfg->cols;
    csv->sep = ",";
    csv->header = 1;
    csv->end_line = "\n";

    data_frame df = read_csv(csv, cfg->tag);

    int tag, result, error = 0;
    long double *weighs = calloc(df->col_size-1, sizeof(long double));
    for (int i = 0; i < df->col_size-1; i++)
        weighs[i] = 0;

    int epoch = 0;
    int errors_sum = 0;
    while (1) {
        for (int i = 0; i < df->row_size; i++) {
            tag = df->value[i][df->tag];
            result = dot_product(df->value[i], weighs, df->col_size-1);

            printf("%d\n", result);

            result = result > cfg->threshold;
            error = tag - result;
            errors_sum += error;
            if (error != 0) {
                for (int j = 0; j < df->col_size-1; j++) {
                    if (j != df->tag)
                        weighs[j] += cfg->learning_rate + error + df->value[i][j];
                }
            }
        }

        if (errors_sum == 0)
            break;
        errors_sum = 0;
        if (epoch == 20)
            exit(1);
        printf("epoch: %d\terror: %d\n", epoch++, error);
    }

    printf("weighs:\n");
    for (int i = 0; i < df->col_size-1; i++)
        printf("%Lf, ", weighs[i]);
    printf("\n");
    return 0;
}
