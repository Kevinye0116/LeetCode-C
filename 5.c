//
// Created by Kevin Ye on 10/17/2023.
// Copyright (c) KevinYe on 10/17/2023.

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int expandAroundCenter(const char *s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char *longestPalindrome(const char *s) {
    int start = 0;
    int end = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int maxLen = len1 > len2 ? len1 : len2;

        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    char *result = (char *) malloc(end - start + 2);
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';
    return result;
}

int main(void) {
    char s[] = "babad";
    char *result = longestPalindrome(s);
    printf("%s\n", result);
    free(result);
    return 0;
}
