//
// Created by Kevin Ye on 10/12/2023.
// Copyright (c) KevinYe on 10/12/2023.
// ChatGPT

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 比较两个字符串的公共前缀
char *commonPrefix(char *str1, char *str2) {
    int i = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i]) {
        i++;
    }
    char *prefix = (char *) malloc(i + 1);
    strncpy(prefix, str1, i);
    prefix[i] = '\0';
    return prefix;
}

// 查找字符串数组中的最长公共前缀
char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    char *prefix = strs[0];
    for (int i = 1; i < strsSize; i++) {
        prefix = commonPrefix(prefix, strs[i]);
        if (strlen(prefix) == 0) {
            return "";
        }
    }

    return prefix;
}

int main() {
    char *strings[] = {"flower", "flow", "flight"};
    int n = sizeof(strings) / sizeof(strings[0]);

    char *result = longestCommonPrefix(strings, n);

    printf("%s\n", result);

    return 0;
}
