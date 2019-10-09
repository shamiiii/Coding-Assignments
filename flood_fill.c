//By Shamit Mani
#include <stdio.h>
#include "captcha.h"

//I don't even know if this is an actual flood fill algorithm but that's what I'm calling it
//Converts all the 0s that are not within a hole into a 2
void flood_fill(int height, int width, int flooded_pixels[height][width]){
	int i, j;

	//Converts 0s on the two side edges of the rectangle into 2s
	for(i = 0; i < height; i++) {
		if(flooded_pixels[i][0] == 0) {
			flooded_pixels[i][0] = 2;
		}
		if(flooded_pixels[i][width-1] == 0) {
			flooded_pixels[i][width-1] = 2;
		}
	}

	//Converts 0s on top and bottom edges of rectangle into 2s
	for(i = 0; i < width; i++) {
		if(flooded_pixels[0][j] == 0) {
			flooded_pixels[0][j] = 2;
		}
		if(flooded_pixels[height-1][j] == 0) {
			flooded_pixels[height-1][j] = 2;
		}
	}

	//Converts any 0s that are adjacent to 2 into a 2 as well
	//Initially, the flood fill missed a lot of the 0s it was meant to convert into 2s
	//I found that repeating the flood fill several times helped to fill in these areas
	//Hence why the procedure is nested within another for loop that loops 20 times to make sure it gets everything
	
	for(int k = 0; k < 20; k++) {
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++) {
			if(flooded_pixels[i][j] == 0 && (flooded_pixels[i][j - 1] == 2 || flooded_pixels[i][j + 1] == 2 || flooded_pixels[i - 1][j] == 2 || flooded_pixels[i + 1][j] == 2 ||flooded_pixels[i+1][j+2] == 2 || flooded_pixels[i+1][j-1] == 2 || flooded_pixels[i-1][j-1] == 2 || flooded_pixels[i-1][j+1] == 2)) {
				flooded_pixels[i][j] = 2;
			}
		}
	}
	for(j = 0; j < width; j ++) {
		for(i = 0; i < height; i++){
			if(flooded_pixels[i][j] == 0 && (flooded_pixels[i][j - 1] == 2 || flooded_pixels[i][j + 1] == 2 || flooded_pixels[i - 1][j] == 2 || flooded_pixels[i + 1][j] == 2 ||flooded_pixels[i+1][j+2] == 2 || flooded_pixels[i+1][j-1] == 2 || flooded_pixels[i-1][j-1] == 2 || flooded_pixels[i-1][j+1] == 2)) {
				flooded_pixels[i][j] = 2;
			}
		}
	}
	}



}