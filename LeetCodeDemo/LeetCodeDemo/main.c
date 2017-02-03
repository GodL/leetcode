//
//  main.c
//  LeetCodeDemo
//
//  Created by 李浩 on 2017/2/2.
//  Copyright © 2017年 李浩. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 two sum
 the returned must be malloced and freed.
 */
int* twoSum(int* nums, int numsSize, int target)
{
    if (nums == NULL ||numsSize <= 1) return NULL;
    int* result = calloc(2, sizeof(int));
    for (int i=0; i<numsSize-1; i++) {
        int num1 = *(nums+i);
        for (int j = i+1; j<numsSize; j++) {
            int num2 = *(nums+j);
            if (num1 + num2 == target) {
                *result = i;
                *(result+1) = j;
                return result;
            }
        }
    }
    return NULL;
}

/*
 add two numbers
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL||l2 == NULL) return NULL;
    struct ListNode* result_node = malloc(sizeof(struct ListNode));
    result_node->next = NULL;
    result_node->val = 0;
    struct ListNode* result = result_node;
    int sum = 0;
    while (l1 != NULL||l2 != NULL) {
        if (sum>=10) {
            result_node->val = 1;
        }
        sum = 0;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += result_node->val;
        result_node->val = sum%10;
        if (l1 != NULL || l2 != NULL) {
            result_node->next = malloc(sizeof(struct ListNode));
            result_node->next->next = NULL;
            result_node->next->val = 0;
            result_node = result_node->next;
        }else if (sum >= 10) {
            result_node->next = malloc(sizeof(struct ListNode));
            result_node->next->next = NULL;
            result_node->next->val = 1;
        }
    }
    return result;
}

/*
 Longest Substring Without Repeating Characters
 */
int lengthOfLongestSubstring(char* s)
{
    if (s == NULL) return 0;
    int str_length = (int)strlen(s);
    char* compare = malloc(sizeof(char)*str_length);
    int max_length = 0;
    int temp_length = 1;
    for (int i = 0; i<str_length-1; i++) {
        for (int j = i+1; j<str_length; j++) {
            char a = *(s+i);
            char b = *(s+j);
            if (b != a) {
                temp_length += 1;
            }else {
                max_length = max_length<temp_length?temp_length:max_length;
                temp_length = 1;
                break;
            }
        }
    }
    return max_length;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = lengthOfLongestSubstring("abcabcbb");
    printf("Hello, World!\n");
    return 0;
}

