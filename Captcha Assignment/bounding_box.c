//Created by Shamit Mani
//Created on 16/04/2017
#include <stdio.h>

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width) {

		int i, j;
		int box_width_count[width], box_height_count[height];
		*box_height = 0;
		*box_width = 0;

		for(i = 0; i < height; i++) {
			for(j = 0; j < width; j++) {
				if(pixels[i][j] == 1) {
					box_height_count[i] = 1;
				}
			}
		}	
		for(j = 0; j < width; j++) {
			for(i = 0; i < height; i++) {
				if(pixels[i][j] == 1) {
					box_width_count[j] = 1;
				}
			}
		}

		for(i = 0; i < height; i++) {
			if(box_height_count[i] == 1) {
				*box_height = *box_height + box_height_count[i]; 
			}
		}
		for(j = 0; j < width; j++) {
			if(box_width_count[j] == 1) {
				*box_width = *box_width + box_width_count[j];
			}
		}

		for(i = 0; i < height; i++) {
			for(j = 0; j < width; j++) {
				if(pixels[i][j] == 1){
					break;
				}
			}
				if(pixels[i][j] == 1){
					break;
				}
		}
			*start_row = i;

		for(j = 0; j < width; j++) {
			for(i = 0; i < height; i++) {
				if(pixels[i][j] == 1){
					break;
				}
			}
			if(pixels[i][j] == 1){
					break;
				}
		}
			*start_column = j;


}
