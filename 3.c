//
// Created by Kevin Ye on 10/11/2023.
// Copyright (c) KevinYe on 10/11/2023.

#include <string.h>
#include <stdio.h>

int lengthOfLongestString(char *s) {
    int n = strlen(s);
    int max = 0;
    int hash[256] = {0};
    for (int i = 0, j = -1; j < n - 1;) {
        ++j;
        ++hash[s[j]];
        while (hash[s[j]] > 1) {
            --hash[s[i]];
            ++i;
        }
        if (j - i + 1 > max) max = j - i + 1;
    }
    return max;
}

int main(void) {
    char s[] = "abcabcbb";
    int answer = lengthOfLongestString(s);
    printf("%d\n", answer);
    return 0;
}
