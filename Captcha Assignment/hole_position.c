//By Shamit Mani

#include <stdio.h>
#include "captcha.h"

// if the digit has a hole, this returns the position of the hole within the image
int hole_position(int height, int width, int pixels[height][width]){
	int i, j;
	int bottom = 0, top = 0;

	for(j = 0; j < width; j++){
		if(pixels[height/4][j] == 1 && pixels[height/4][j+1] == 0){
			bottom = 1;
		}
	}

	for(j = 0; j < width; j++){
		if(pixels[height*3/4][j] == 1 && pixels[height*3/4][j+1] == 0){
			top = 2;
		}
	}

	return bottom + top;
}
