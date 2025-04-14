#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void read_weights_from_file(const char *filename, int *input_dim, int *output_dim, int ***weights) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("ERROR: Could not open file");
        exit(1);
    }

    char line[1024];

    // Read dimensions from the first line
    if (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d x %d", input_dim, output_dim);
    } else {
        fprintf(stderr, "ERROR: Failed to read dimensions\n");
        fclose(fp);
        exit(1);
    }

    // Allocate memory for weights
    *weights = (int **)malloc(sizeof(int *) * (*output_dim));
    for (int i = 0; i < *output_dim; i++) {
        (*weights)[i] = (int *)malloc(sizeof(int) * (*input_dim));
    }

    // Read weights line by line
    for (int i = 0; i < *output_dim; i++) {
        if (!fgets(line, sizeof(line), fp)) {
            fprintf(stderr, "ERROR: Not enough lines for weights\n");
            fclose(fp);
            exit(1);
        }

        int j = 0, k = 0, val = 0, sign = 1;
        while (line[j] != '\0' && k < *input_dim) {
            if (line[j] == '-') {
                sign = -1;
                j++;
            }

            if (isdigit(line[j])) {
                val = 0;
                while (isdigit(line[j])) {
                    val = val * 10 + (line[j] - '0');
                    j++;
                }
                (*weights)[i][k++] = sign * val;
                sign = 1;
            } else {
                j++; // Skip spaces or non-digit characters
            }
        }
    }

    fclose(fp);
}
