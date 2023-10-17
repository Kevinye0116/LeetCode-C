//
// Created by Kevin Ye on 10/6/2023.
// Copyright (c) KevinYe on 10/6/2023.

#include <stdio.h>
#include <malloc.h>

int *twoSum(const int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *result = (int *) malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main(void) {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int *result = twoSum(nums, 4, target, &returnSize);
    printf("%d %d\n", result[0], result[1]);
    free(result);
    return 0;
}