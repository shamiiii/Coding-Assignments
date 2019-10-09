// By Shamit Mani
// Adapted from "horizontal_balance.c" by Andrew Taylor

#include "captcha.h"

// find vertical balance point (like the vertical centre of volume or centroid) of image

double get_vertical_balance(int height, int width, int pixels[height][width]) {
    double row_sum = 0;
    int n_black_pixels = 0;
    for (int column = 0; column < width; column++) {
         for (int row = 0; row < height; row++){ 
            if (pixels[row][column] == 1) {
                row_sum = row_sum + row;
                n_black_pixels = n_black_pixels + 1;
            }
        }
    }
    return (row_sum/n_black_pixels + 0.5)/height;
}
