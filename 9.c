//
// Created by Kevin Ye on 10/12/2023.
// Copyright (c) KevinYe on 10/12/2023.

#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    long a = 0, b = x;
    if (x < 0) return false;
    else {
        while (b != 0) {
            a = a * 10 + b % 10;
            b /= 10;
        }
        if (x == a) return true;
        else return false;
    }
}

int main(void) {
    int x = 121;
    if (isPalindrome(x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
