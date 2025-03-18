#include "c_img.h"
#include "seamcarving.h"

void calc_energy(struct rgb_img *im, struct rgb_img **grad) {
    '''compute the dual-gradient energy function, and place it in the struct rgb_img *grad'''

    for (int i = 0; i < rgb_img->height; i++) {
        for (int j = 0; j < rgb_img->wdith; j++) {

            if (i == 0 || j == 0) {
                continue; // Figure out how to calculate edge pixels (see website)
            }

            // Calculating Delta X

            int R_x = get_pixel(im, i, j + 1, 0) -  get_pixel(im, i, j - 1, 0); 
            int G_x = get_pixel(im, i, j + 1, 1) -  get_pixel(im, i, j - 1, 1);
            int B_x = get_pixel(im, i, j + 1, 2) -  get_pixel(im, i, j - 1, 2);

            int Delta_x_squr = // R_x ^2 ...

            // Calculating Delta Y

            int R_y = get_pixel(im, i + 1, j, 0) -  get_pixel(im, i - 1, j, 0); 
            int G_y = get_pixel(im, i + 1, j, 1) -  get_pixel(im, i - 1, j, 1);
            int B_y = get_pixel(im, i + 1, j, 2) -  get_pixel(im, i - 1, j, 2);

            int Delta_y_squr = // R_x ^2 ...            


            
        }
    }

}
void dynamic_seam(struct rgb_img *grad, double **best_arr) {
    '''allocates and computes the dunamic array *best_arr. (*best_arr)[i*width+j] contains the 
    minimum cost of a seam from the top of grad to the point (i,j)'''

}
void recover_path(double *best, int height, int width, int **path) {
    '''allocates a path through the minimum seam as defined by the array best'''

}
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {
    '''creates the destination image, and writes to it the source image, with the seam removed'''

}