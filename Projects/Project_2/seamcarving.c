#include "c_img.h"
#include "seamcarving.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h> // malloc and exit
#include <float.h> // double
#include <stdio.h> // printf

void compute_delta(struct rgb_img *im, int i1, int i2, int j1, int j2, int *delta_sq) {
    int R = get_pixel(im, i1, j1, 0) - get_pixel(im, i2, j2, 0);
    int G = get_pixel(im, i1, j1, 1) - get_pixel(im, i2, j2, 1);
    int B = get_pixel(im, i1, j1, 2) - get_pixel(im, i2, j2, 2);
    *delta_sq = R * R + G * G + B * B;
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad) {
    '''compute the dual-gradient energy function, and place it in the struct rgb_img *grad'''
    int height = rgb_img->height;
    int width = rgb_img->width;

    // Allocate memory for the gradient image
    '''Idk if we need to modify the given struct'''

    create_img(grad, height, width);    

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // Handle boundary wrapping

            int left = (j == 0) ? width - 1 : j - 1;
            int right = (j == width - 1) ? 0 : j + 1;
            int up = (i == 0) ? height - 1 : i - 1;
            int down = (i == height - 1) ? 0 : i + 1;

            // Compute Δx² and Δy²

            int Delta_x_squr, Delta_y_squr;
            compute_delta(im, i, i, right, left, &Delta_x_squr);
            compute_delta(im, down, up, j, j, &Delta_y_squr);

            // Compute energy

            int energy = (int)(sqrt(Delta_x_squr + Delta_y_squr));
            uint8_t pixel_value = (uint8_t)(energy / 10);

            // Store energy in the gradient image

            set_pixel(*grad, i, j, pixel_value, pixel_value, pixel_value);
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr) {
    int height = grad->height;
    int width = grad->width;

    // Allocate memory for 2 rows only
    double *prev_row = (double *)malloc(width * sizeof(double));
    double *curr_row = (double *)malloc(width * sizeof(double));
    
    if (!prev_row || !curr_row) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize first row
    for (int j = 0; j < width; j++) {
        prev_row[j] = get_pixel(grad, 0, j, 0);
    }

    // Compute DP row by row
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double energy = get_pixel(grad, i, j, 0);

            // Find min cost from previous row
            double min_cost = prev_row[j]; // Middle
            if (j > 0) min_cost = fmin(min_cost, prev_row[j - 1]); // Left
            if (j < width - 1) min_cost = fmin(min_cost, prev_row[j + 1]); // Right

            curr_row[j] = energy + min_cost;
        }

        // Swap pointers instead of copying arrays
        double *temp = prev_row;
        prev_row = curr_row;
        curr_row = temp;
    }

    // Store the final row in best_arr (caller must allocate memory)
    *best_arr = prev_row;

    // Free extra memory (curr_row is unused after the last swap)
    free(curr_row);
}


void recover_path(double *best, int height, int width, int **path) {
    '''allocates a path through the minimum seam as defined by the array best'''
    
    // Allocate memory
    *path = (int *)malloc(height * sizeof(int));
    if (*path == NULL) {
        printf("Cannot allocate memory\n");
        exit(1);
    }

    // Find column with minimum energy in the last row
    int min_col = 0;
    double min_val = best[(height - 1) * width]; // Initialize to first pixel in last row

    for (int j = 1; j < width; j++) {
        if (best[(height - 1) * width + j] < min_val) {
            min_val = best[(height - 1) * width + j];
            min_col = j;
        }
    }

    // Store the minimum column in the path
    (*path)[height - 1] = min_col;

    // Trace the path back from the bottom to the top
    for (int i = height - 2; i >= 0; i--) {
        int j = (*path)[i + 1]; // Column of min energy in the row below
        int best_j = j;
        double min_cost = best[i * width + j]; // Start with middle pixel

        // Check left diagonal
        if (j > 0 && best[i * width + (j - 1)] < min_cost) {
            min_cost = best[i * width + (j - 1)];
            best_j = j - 1;
        }

        // Check right diagonal
        if (j < width - 1 && best[i * width + (j + 1)] < min_cost) {
            min_cost = best[i * width + (j + 1)]; // Update min_cost
            best_j = j + 1;
        }

        // Store the best column for the current row
        (*path)[i] = best_j;
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {
    '''creates the destination image, and writes to it the source image, with the seam removed'''

}