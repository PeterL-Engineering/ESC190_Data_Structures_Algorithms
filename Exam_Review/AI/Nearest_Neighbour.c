#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_SIZE 784  // 28 x 28 pixels

// Image structure
typedef struct {
    unsigned char pixels[IMG_SIZE];  // Flattened grayscale pixel values
    int label;  // Image label (e.g., digit 0–9)
} Image;

// Calculate Euclidean distance between two images
double image_distance(Image a, Image b) {
    double sum = 0.0;
    for (int i = 0; i < IMG_SIZE; i++) {
        double diff = (double)a.pixels[i] - (double)b.pixels[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

// Find the label of the closest training image (1-NN)
int one_nn_image(Image* train, int train_size, Image test_img) {
    int closest_index = 0;
    double min_dist = image_distance(train[0], test_img);

    for (int i = 1; i < train_size; i++) {
        double dist = image_distance(train[i], test_img);
        if (dist < min_dist) {
            min_dist = dist;
            closest_index = i;
        }
    }

    return train[closest_index].label;
}

// Evaluate accuracy on the test set
double evaluate_accuracy(Image* train, int train_size, Image* test, int test_size) {
    int correct = 0;

    for (int i = 0; i < test_size; i++) {
        int predicted = one_nn_image(train, train_size, test[i]);
        if (predicted == test[i].label) {
            correct++;
        }
    }

    return (double)correct / test_size * 100.0;
}