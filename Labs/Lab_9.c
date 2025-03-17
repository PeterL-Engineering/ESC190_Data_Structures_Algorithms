#include "c.img.h"

// Question 1

// Change IMG_BRIGHTNESS & OUTPUT_FILE_NAME for each iteration

#define IMG_BRIGHTNESS 1.5
#define OUTPUT_FILE_NAME "out1.bin"

struct rgb_img *im;

read_in_img(&im, "skule_cannon.bin");

// Setting the brightness

for (i = 0; i < im.height; i++) {
    for (j = 0; j < im.width; j++) {

        // Pixel value must be <= 255 to prevent overflow

        r = min(255, IMG_BRIGHTNESS * get_pixel(im, i, j, 0));
        g = min(255, IMG_BRIGHTNESS * get_pixel(im, i, j, 1));
        b = min(255, IMG_BRIGHTNESS * get_pixel(im, i, j, 2));
        set_pixel(im, i, j, r, g, b);
    }
}

// Writing adjusted image to new output file

write_img(im, OUTPUT_FILE_NAME);

