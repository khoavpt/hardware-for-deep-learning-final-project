#include "conv2D.h"

void conv2d(image_t input[IMAGE_ROWS][IMAGE_COLS],
            kernel_t kernel[KERNEL_ROWS][KERNEL_COLS],
            result_t output[IMAGE_ROWS - KERNEL_ROWS + 1][IMAGE_COLS - KERNEL_COLS + 1]) {

    #pragma HLS ARRAY_PARTITION variable=kernel complete dim=0
    #pragma HLS ARRAY_PARTITION variable=input complete dim=0
	#pragma HLS ARRAY_PARTITION variable=output complete dim=0


    for (int x = 0; x < IMAGE_ROWS - KERNEL_ROWS + 1; x++) {
        #pragma HLS PIPELINE
        for (int y = 0; y < IMAGE_COLS - KERNEL_COLS + 1; y++) {
            int sum = 0;
            for (int i = 0; i < KERNEL_ROWS; i++) {
				#pragma HLS UNROLL
                for (int j = 0; j < KERNEL_COLS; j++) {
                    #pragma HLS UNROLL
                    sum += input[x + i][y + j] * kernel[i][j];
                }
            }
            output[x][y] = sum;
        }
    }
}
