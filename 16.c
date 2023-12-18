//
// Created by Kevin Ye on 11/23/2023.
// Copyright (c) KevinYe on 11/23/2023.

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  return *(int *) a - *(int *) b;
}

int threeSumClosest(int *nums, int numsSize, int target) {
  int n = numsSize;
  int best = 1e7;
  qsort(nums, n, sizeof(nums[0]), cmp);

  for (int i = 0; i < n; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int j = i + 1, k = n - 1;
    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum == target) {
        return target;
      }
      if (abs(sum - target) < abs(best - target)) {
        best = sum;
      }
      if (sum > target) {
        int k0 = k - 1;
        while (j < k0 && nums[k0] == nums[k]) {
          --k0;
        }
        k = k0;
      } else {
        int j0 = j + 1;
        while (j0 < k && nums[j0] == nums[j]) {
          ++j0;
        }
        j = j0;
      }
    }
  }
  return best;
}

int main(void) {
  int num[] = { -1, 2, 1, -4 };
  int numSize = sizeof(num) / sizeof(num[0]);
  int target = 1;
  int result = threeSumClosest(num, numSize, target);
  printf("%d\n", result);
  return 0;
}
