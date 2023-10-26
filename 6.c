//
// Created by Kevin Ye on 10/24/2023.
// Copyright (c) KevinYe on 10/24/2023.

#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *convert(char *s, int numRows) {
    int len = (int) strlen(s);

    if (numRows == 1 || len <= numRows) return s;

    char *result = (char *) malloc(len + 1);
    int step = 2 * (numRows - 1);
    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += step) {
            result[index++] = s[j];
            if (i > 0 && i < numRows - 1 && j + step - 2 * i < len) {
                result[index++] = s[j + step - 2 * i];
            }
        }
    }

    result[len] = '\0';
    return result;
}

int main(void) {
    char s[] = {"PAYPALISHIRING"};
    int numRows = 4;
    char *result = convert(s, numRows);
    printf("%s\n", result);
    free(result);
    return 0;
}
