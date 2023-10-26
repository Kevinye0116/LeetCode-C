//
// Created by Kevin Ye on 10/24/2023.
// Copyright (c) KevinYe on 10/24/2023.

#include <stdio.h>

#define min(a, b) (a<b?a:b)
#define max(a, b) (a>b?a:b)

int maxArea(const int *height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maximum = 0;

    while (left < right) {
        int area = min(height[right], height[left]) * (right - left);
        maximum = max(maximum, area);
        (height[left] < height[right]) ? (left++) : (right--);
    }
    return maximum;
}

int main(void) {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    int maximum = maxArea(height, heightSize);
    printf("%d\n", maximum);
    return 0;
}
