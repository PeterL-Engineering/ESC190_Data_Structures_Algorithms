#include "c_img.h"
#include "seamcarving.h"
#include <math.h>
#include <stdint.h>

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
    '''allocates and computes the dynamic array *best_arr. (*best_arr)[i*width+j] contains the 
    minimum cost of a seam from the top of grad to the point (i,j)'''

    height = rgb_img->grad->height;
    width = rgb_img->grad->width;

    // Allocate memory for best_arr as a flattened 1D array
    
    *best_arr = (double *)malloc(height * width * sizeof(double));
    if (*best_arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double energy = get_pixel(grad, i, j, 0); // Extract the grayscale energy

            if (i == 0) {
                (*best_arr)[i * width + j] = energy;
                continue;  // Skip further processing for first row
            }

            // Find the minimum cost from the previous row

            double min_cost = DBL_MAX;
            if (j > 0) {
                min_cost = fmin(min_cost, (*best_arr)[(i - 1) * width + (j - 1)]);
            }
            min_cost = fmin(min_cost, (*best_arr)[(i - 1) * width + j]);
            if (j < width - 1) {
                min_cost = fmin(min_cost, (*best_arr)[(i - 1) * width + (j + 1)]);
            }

            (*best_arr)[i * width + j] = energy + min_cost;
        }
    }
}

void recover_path(double *best, int height, int width, int **path) {
    '''allocates a path through the minimum seam as defined by the array best'''

}
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {
    '''creates the destination image, and writes to it the source image, with the seam removed'''

}