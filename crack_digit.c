// Adapted from crack_digit.c by Andrew Taylor from lab07
//Shamit Mani z5157509

#include <stdio.h>
#include "captcha.h"

void analyze_image(int height, int width, int pixels[height][width]);
int identify_digit(double horizontal_balance);

int main(int argc, char *argv[]) {
    int height, width;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    // first get image dimensions
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    // now declare appropriate array
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        analyze_image(height, width, pixels);
    }
    return 0;
}

void analyze_image(int height, int width, int pixels[height][width]) {
    int start_row, start_column, box_width, box_height;

    get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

    int box_pixels[box_height][box_width];
    copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);
    flood_fill(box_height, box_width, box_pixels);
    double horizontal_balance = get_horizontal_balance(box_height, box_width, box_pixels);
    double vertical_balance = get_vertical_balance(box_height, box_width, box_pixels);
    int n_holes = holes(box_height, box_width, box_pixels);
    
    int digit;
    	if(hole_position(box_height, box_width, box_pixels) == 1){
    		digit = 6;
    	} else if(hole_position(box_height, box_width, box_pixels) == 2){
    		digit = 9;
    	} else if(hole_position(box_height, box_width, box_pixels) == 3){
    		digit = 0;
    	}

    printf("%c\n", digit);
}

