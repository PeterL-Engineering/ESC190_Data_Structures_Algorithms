#include "c_img.h"

// Question 1

// Change IMG_BRIGHTNESS & OUTPUT_FILE_NAME for each iteration

#define IMG_BRIGHTNESS 1.5
#define OUTPUT_FILE_NAME "out1.bin"

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(){

    struct rgb_img *im;

    read_in_img(&im, "skule_cannon.bin");

    // Setting the brightness

    for (int i = 0; i < im->height; i++) {
        for (int j = 0; j < im->width; j++) {

            // Pixel value must be <= 255 to prevent overflow

            int r = min(255, IMG_BRIGHTNESS * get_pixel(im, i, j, 0));
            int g = min(255, IMG_BRIGHTNESS * get_pixel(im, i, j, 1));
            int b = min(255, IMG_BRIGHTNESS * get_pixel(im, i, j, 2));
            set_pixel(im, i, j, r, g, b);
        }
    }

    // Writing adjusted image to new output file

    write_img(im, OUTPUT_FILE_NAME);

}
// Question 2 (See Lab_9.py)

