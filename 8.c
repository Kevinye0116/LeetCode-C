//
// Created by Kevin Ye on 10/27/2023.
// Copyright (c) KevinYe on 10/27/2023.

#include <stdio.h>
#include <limits.h>

int myAtoi(const char *s) {
    int i = 0;
    while (s[i] == ' ') i++;
    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    long result = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
        i++;
    }
    return sign * result;
}

int main(void) {
    char s[] = {"4193 with words"};
    int answer = myAtoi(s);
    printf("%d\n", answer);
    return 0;
}
