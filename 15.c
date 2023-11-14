//
// Created by Kevin Ye on 11/7/2023.
// Copyright (c) KevinYe on 11/7/2023.

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    if (numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);

    int **result = (int **) malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *) malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result[*returnSize] = (int *) malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main(void) {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;

    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}

