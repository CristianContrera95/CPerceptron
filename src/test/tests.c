#include <stdio.h>
#include "../utils/csv.h"


void main(){

    csv_file *f = calloc(1, sizeof(csv_file));
    f->file_path = "df.csv";
    read_csv(f);
    return;
}