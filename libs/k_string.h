#include <stdbool.h>
#include <stddef.h>

char *memchr(register int *src_void, int c, size_t length);
int memcmp(int str1, int str2, size_t count);
void memcpy(void *dest, void *src, size_t n);
// TODO: memmove()
void *memset(void *b, int c, int len);
char *strcat(char *destination, const char *source);
char *strncat(char *destination, const char *source, size_t num);
char *strchr(register const char *s, int c);
bool strcmp(char s1[], char s2[]);
int strncmp(const char *s1, const char *s2, size_t n);
int strcoll(const char *s1, const char *s2);
char *strcpy(char *destination, char *source);
size_t strcspn(const char *s1, const char *s2);
// TODO: strerror()
int strlen(const char *str);
char *STRPBRK(const char *s, const char *accept);
char *strrchr(const char *s, int c);
unsigned int strspn(const char *s1, const char *s2);
const char *strstr(const char *X, const char *Y, int m, int n);
char *strtok(char *s, const char delim);
size_t strxfrm(char *s1, const char *s2, size_t n);

// Find place for this
char *remove_first_chars(char s1[], int n);