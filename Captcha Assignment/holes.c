//By Shamit Mani

#include <stdio.h>
#include "captcha.h"

int holes(int height, int width, int flooded_pixels[height][width]) {
	int i, j;
	double hole_count;

	//Starts middle column
	//Works down the pixels
	//If there is a transition from a 1 to a 0, this indicates a hole
	for(i = 0; i < height; i++){
		if(flooded_pixels[i][width/2] == 1 && flooded_pixels[i+1][width/2] == 0){
			hole_count++;
		} 
	}

	return hole_count;
}
