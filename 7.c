//
// Created by Kevin Ye on 10/26/2023.
// Copyright (c) KevinYe on 10/26/2023.

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int result = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        // Check for overflow before updating the result
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
            return 0;
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
            return 0;
        }

        result = result * 10 + pop;
    }

    return result;
}


int main(void) {
    int x = 1534236469;
    int answer = reverse(x);
    printf("%d\n", answer);
    return 0;
}
