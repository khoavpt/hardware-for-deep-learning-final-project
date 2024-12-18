#include <stdio.h>
#include "conv2D.h"

void print_output(result_t output[IMAGE_ROWS - KERNEL_ROWS + 1][IMAGE_COLS - KERNEL_COLS + 1]) {
    for (int i = 0; i < IMAGE_ROWS - KERNEL_ROWS + 1; i++) {
        for (int j = 0; j < IMAGE_COLS - KERNEL_COLS + 1; j++) {
            printf("%4d ", output[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Test case 1: Basic input and kernel
    image_t input1[IMAGE_ROWS][IMAGE_COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    kernel_t kernel1[KERNEL_ROWS][KERNEL_COLS] = {
        {1, 0, -1},
        {1, 0, -1},
        {1, 0, -1}
    };
    result_t output1[IMAGE_ROWS - KERNEL_ROWS + 1][IMAGE_COLS - KERNEL_COLS + 1] = {0};
    conv2d(input1, kernel1, output1);
    printf("Test Case 1 Output:\n");
    print_output(output1);

    // Test case 2: All-zero kernel
    kernel_t kernel2[KERNEL_ROWS][KERNEL_COLS] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    result_t output2[IMAGE_ROWS - KERNEL_ROWS + 1][IMAGE_COLS - KERNEL_COLS + 1] = {0};
    conv2d(input1, kernel2, output2);
    printf("Test Case 2 Output (Zero Kernel):\n");
    print_output(output2);

    // Test case 3: Identity kernel
    kernel_t kernel3[KERNEL_ROWS][KERNEL_COLS] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    result_t output3[IMAGE_ROWS - KERNEL_ROWS + 1][IMAGE_COLS - KERNEL_COLS + 1] = {0};
    conv2d(input1, kernel3, output3);
    printf("Test Case 3 Output (Identity Kernel):\n");
    print_output(output3);

    // Test case 4: Negative input
    image_t input4[IMAGE_ROWS][IMAGE_COLS] = {
        {-1, -2, -3, -4, -5},
        {-6, -7, -8, -9, -10},
        {-11, -12, -13, -14, -15},
        {-16, -17, -18, -19, -20},
        {-21, -22, -23, -24, -25}
    };
    result_t output4[IMAGE_ROWS - KERNEL_ROWS + 1][IMAGE_COLS - KERNEL_COLS + 1] = {0};
    conv2d(input4, kernel1, output4);
    printf("Test Case 4 Output (Negative Input):\n");
    print_output(output4);

    return 0;
}
