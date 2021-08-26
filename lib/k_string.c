/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include <stdbool.h>
#include <stddef.h>
#include "k_string.h"

/**
 * memchr - find char in str
 * 
 * scan first (length) bytes of (*src_void) 
 * for (c). Returns char (c)
 */
char *memchr(register int *src_void, int c, size_t length)
{
    unsigned char *src = (unsigned char *)src_void;
    while (length-- > 0)
    {
        if (*src == c)
            return src;
        src++;
    }
    return NULL;
}

/**
 * memcmp - compare two mem vals
 * 
 * Compares the first (count) bytes of (str1) 
 * and (str2). If str1 < str2, return -1, if 
 * str2 < str1, return 1, if str1 = str2, return
 * 0.
 */
int memcmp(int str1, int str2, size_t count)
{
    register const unsigned char *s1 = (const unsigned char *)str1;
    register const unsigned char *s2 = (const unsigned char *)str2;
    while (count-- > 0)
    {
        if (*s1++ != *s2++)
            return s1[-1] < s2[-1] ? -1 : 1;
    }
    return 0;
}

/**
 * memcpy - copys first n bytes
 * 
 * Copy the first n bytes of (*src) to 
 * (*dest). Return nothing.
 */
void memcpy(void *dest, void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    for (int i = 0; i < n; i++)
        cdest[i] = csrc[i];
}

// TODO: MEMMOVE()

/**
 * memset - copy c to 1stn chars of str
 * 
 * Copies the character c (an unsigned 
 * char) to the first n characters of 
 * the string pointed to, by the argument 
 * str.
 */
void *memset(void *b, int c, int len)
{
    int i;
    unsigned char *p = b;
    i = 0;
    while (len > 0)
    {
        *p = c;
        p++;
        len--;
    }
    return (b);
}

/**
 * strcat - concat strings
 * 
 * concatinate source to the end of 
 * destination. Return pointer to 
 * destination (redundant to use in 
 * MOST cases however)
 */
char *strcat(char *destination, const char *source)
{
    char *ptr = destination + strlen(destination);
    while (*source != '\0')
    {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}

/**
 * strncat - concat n chars of src
 * Appends the string pointed to, by 
 * src to the end of the string pointed 
 * to, by dest up to n characters long
 */
char *strncat(char *destination, const char *source, size_t num)
{
    char *ptr = destination + strlen(destination);
    while (*source != '\0' && num--)
    {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}

/**
 * strchr - search c in str
 * 
 * Searches for the first occurrence of 
 * the character c (an unsigned char) 
 * in the string pointed to, by the 
 * argument str.
 */
char *strchr(register const char *s, int c)
{
    do
    {
        if (*s == c)
        {
            return (char *)s;
        }
    } while (*s++);
    return (0);
}

/**
 * strcmp - compare two string
 * Compares two input strings and returns
 * bool true if same or bool false if 
 * different
 */
bool strcmp(char* s1, char* s2)
{
    if (sizeof(s1) / sizeof(s1[0]) == sizeof(s2) / sizeof(s2[0]))
    {
        for (int i = 0; i < sizeof(s1) / sizeof(s1[0]); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * strncmp - comp n bytes
 * 
 * Compares at most the first n bytes of 
 * str1 and str2.
 */
int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (*(unsigned char *)s1 - *(unsigned char *)s2);
    }
}


/**
 * strcpy - copy str
 * 
 * Copies the string pointed to, by src
 * to dest.
 */
char *strcpy(char *destination, char *source)
{
    char *start = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // add '\0' at the end
    return start;
}

/**
 * strncpy - copy n bytes of str
 * 
 * Copies up to n characters from the 
 * string pointed to, by src to dest.
 */

/**
 * strcspn - overlap of 2 strings
 * 
 * Calculates the length of the initial 
 * segment of str1 which consists entirely 
 * of characters not in str2.
 */
size_t strcspn(const char *s1, const char *s2)
{
    size_t ret = 0;
    while (*s1)
        if (strchr(s2, *s1))
            return ret;
        else
            s1++, ret++;
    return ret;
}

/**
 * strerror - error code to desc.
 * 
 * Searches an internal array for the error 
 * number errnum and returns a pointer 
 * to an error message string.
 */
// TODO: ADD

/**
 * strlen - get length of str
 * 
 * Computes the length of the string str 
 * to but not including the terminating 
 * null character.
 */
int strlen(const char *str)
{
    register const char *s;

    for (s = str; *s; ++s)
        ;
    return (s - str);
}

/**
 * strpbrk - find first char from char[]
 * 
 * Finds the first character in the string 
 * str1 that matches any character 
 * specified in str2.
 */
char *STRPBRK(const char *s, const char *accept)
{
    s += strcspn(s, accept);
    return *s ? (char *)s : NULL;
}

/**
 * strrchr - get last char in str from char
 * 
 * Searches for the last occurrence of the 
 * character c (an unsigned char) in the 
 * string pointed to by the argument str.
 */
char *strrchr(const char *s, int c)
{
    const char *found, *p;
    c = (unsigned char)c;
    if (c == '\0')
        return strchr(s, '\0');
    found = NULL;
    while ((p = strchr(s, c)) != NULL)
    {
        found = p;
        s = p + 1;
    }
    return (char *)found;
}

/**
 * strspn - len of overlap
 * 
 * Calculates the length of the initial 
 * segment of str1 which consists entirely
 * of characters in str2.
 */
unsigned int strspn(const char *s1, const char *s2)
{
    unsigned int len = 0;
    //return 0 if any one is NULL
    if ((s1 == NULL) || (s2 == NULL))
        return len;
    while (*s1 && strchr(s2, *s1++))
    {
        len++;
    }
    return len;
}

 
 
/**
 * strtok - break string on delim
 * 
 * Breaks string str into a series of tokens 
 * separated by delim.
 */
char *strtok(char *s, const char delim)
{
    static char *lasts;
    register int ch;
    if (s == 0)
        s = lasts;
    do
    {
        if ((ch = *s++) == '\0')
            return 0;
    } while (strchr(&delim, ch));
    --s;
    lasts = s + strcspn(s, &delim);
    if (*lasts != 0)
        *lasts++ = 0;
    return s;
}

/**
 * strxfrm - get first n bytes of str
 * 
 * Transforms the first n characters of the
 * string src into current locale and places
 * them in the string dest.
 */
size_t strxfrm(char *s1, char *s2, size_t n)
{
    size_t len = strlen(s2) + 1;
    if (len < n)
        n = len;
    memcpy(s1, s2, n);
    return len;
}

