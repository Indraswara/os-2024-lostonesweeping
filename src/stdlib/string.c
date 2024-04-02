#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "header/stdlib/string.h"

void* memset(void *s, int c, size_t n) {
    uint8_t *buf = (uint8_t*) s;
    for (size_t i = 0; i < n; i++)
        buf[i] = (uint8_t) c;
    return s;
}

void* memcpy(void* restrict dest, const void* restrict src, size_t n) {
    uint8_t *dstbuf       = (uint8_t*) dest;
    const uint8_t *srcbuf = (const uint8_t*) src;
    for (size_t i = 0; i < n; i++)
        dstbuf[i] = srcbuf[i];
    return dstbuf;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *buf1 = (const uint8_t*) s1;
    const uint8_t *buf2 = (const uint8_t*) s2;
    for (size_t i = 0; i < n; i++) {
        if (buf1[i] < buf2[i])
            return -1;
        else if (buf1[i] > buf2[i])
            return 1;
    }

    return 0;
}

void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *dstbuf       = (uint8_t*) dest;
    const uint8_t *srcbuf = (const uint8_t*) src;
    if (dstbuf < srcbuf) {
        for (size_t i = 0; i < n; i++)
            dstbuf[i]   = srcbuf[i];
    } else {
        for (size_t i = n; i != 0; i--)
            dstbuf[i-1] = srcbuf[i-1];
    }

    return dest;
}

void copyStringWithLength(char* destination, const char* source, int length) {
    int i = 0;
	while (i < length - 1 && source[i] != '\0') {
		destination[i] = source[i];
		++i;
	}
	destination[i] = '\0';
}

void *my_memcpy(void *dest, const void *src, size_t length) {
    char *dest_ptr = (char *)dest;
    const char *src_ptr = (const char *)src;

    for (size_t i = 0; i < length; ++i) {
        dest_ptr[i] = src_ptr[i];
    }

    return dest;  // Return a pointer to the destination memory
}

void my_memset(void *ptr, int value, size_t num) {
    uint8_t *p = (uint8_t *)ptr;
    for (size_t i = 0; i < num; i++) {
        p[i] = (uint8_t)value;
    }
}

int my_memcmp(const void *ptr1, const void *ptr2, size_t n) {
    const unsigned char *p1 = ptr1;
    const unsigned char *p2 = ptr2;
    for (size_t i = 0; i < n; ++i) {
        if (p1[i] != p2[i]) {
            return (p1[i] > p2[i]) - (p1[i] < p2[i]);
        }
    }
    return 0;
}

int strcmp(char *str1, char *str2) {
	int i = 0;
	while(true){
		if (str1[i] < str2[i]) return -1;
		else if (str1[i] > str2[i]) return 1;
		else if (str1[i] == '\0' && str2[i] == '\0') break;
		else if (str1[i] == '\0' && str2[i] != '\0') return -1;
		else if (str1[i] != '\0' && str2[i] == '\0') return 1;
		++i;
	}

	return 0;
}