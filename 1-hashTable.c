//
// Created by Kevin Ye on 10/17/2023.
// Copyright (c) KevinYe on 10/17/2023.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  int index;
  struct Node *next;
} Node;

typedef struct HashTable {
  Node **table;
  int size;
} HashTable;

HashTable *createHashTable(int size) {
    HashTable *ht = (HashTable *) malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (Node **) malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert(HashTable *ht, int val, int index) {
    int key = abs(val) % ht->size;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->val = val;
    newNode->index = index;
    newNode->next = ht->table[key];
    ht->table[key] = newNode;
}

Node *search(HashTable *ht, int val) {
    int key = abs(val) % ht->size;
    Node *current = ht->table[key];
    while (current != NULL) {
        if (current->val == val) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    HashTable *ht = createHashTable(numsSize * 2);
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        Node *node = search(ht, complement);
        if (node != NULL) {
            int *result = (int *) malloc(sizeof(int) * 2);
            result[0] = node->index;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        insert(ht, nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    if (result != NULL) {
        printf("The indices are: %d and %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
