//
// Created by Kevin Ye on 10/13/2023.
// Copyright (c) KevinYe on 10/13/2023.


#include <stdio.h>
#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int x = nums1Size;
    int y = nums2Size;
    int low = 0, high = x;

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = (x + y + 1) / 2 - partition1;

        int max1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int max2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];

        int min1 = (partition1 == x) ? INT_MAX : nums1[partition1];
        int min2 = (partition2 == y) ? INT_MAX : nums2[partition2];

        if (max1 <= min2 && max2 <= min1) {
            if ((x + y) % 2 == 0) {
                return (fmax(max1, max2) + fmin(min1, min2)) / 2.0;
            } else {
                return (fmax(max1, max2));
            }
        } else if (max1 > min2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }
    return 0;
}

int main(void) {
    int nums1[] = {1, 2}, nums2[] = {3, 4};
    double answer = findMedianSortedArrays(nums1, 2, nums2, 2);
    printf("%f\n", answer);
}
