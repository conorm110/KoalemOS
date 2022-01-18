/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "string.h"
#include <stdbool.h>

/**
 * swap() - swaps two nums
 * 
 * swaps pointers to two numbers
 * effectivly swapping their memory locaitons
 */
void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

/**
 * reverse() - reverse string
 * 
 * reverse string. ex: "abc" ->
 * "cba"
 */
void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        swap((str + start), (str + end));
        start++;
        end--;
    }
}

/**
 * itoa() - int to string
 * 
 * converts int to string and
 * adjusts for the ints base. 
 */
char *itoa(int num, char *str, int base)
{
    int i = 0;
    bool isNegative = false;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';

    reverse(str, i);

    return str;
}