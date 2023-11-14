//
// Created by Kevin Ye on 10/29/2023.
// Copyright (c) KevinYe on 10/29/2023.

#include <stdio.h>
#include <string.h>

int hIndex(const int *citations, int citationsSize);

int main(void) {
    int citations[] = {3, 0, 6, 1, 5};
    int citationSize = sizeof(citations) / sizeof(citations[0]);
    int answer = hIndex(citations, citationSize);
    printf("%d\n", answer);
    return 0;
}

int hIndex(const int *citations, int citationsSize) {
    int n = citationsSize, tot = 0;
    int counter[n + 1];
    memset(counter, 0, sizeof(counter));
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n) {
            counter[n]++;
        } else {
            counter[citations[i]]++;
        }
    }
    for (int i = n; i >= 0; i--) {
        tot += counter[i];
        if (tot >= i) {
            return i;
        }
    }
    return 0;
}