#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include <cx/str.h>

char *cx_strcat(const char *s1, const char *s2) {
	if (!s1 || !s2) return NULL;
	size_t len1 = strlen(s1), len2 = strlen(s2);
	char *s = malloc(len1 + len2 + 1);
	if (!s) return NULL;
	memcpy(s, s1, len1);
	memcpy(s + len1, s2, len2);
	s[len1 + len2] = 0;
	return s;
}

char *cx__strto(char *dst, char *src, int (*to_fn)(int)) {
	if (!dst || !src || !to_fn) return NULL;
	for (char *s = src, *d = dst; *s; d++, s++) *d = to_fn(*s);
	return dst;
}

char *cx_strtoupper(const char *s) {
	if (!s) return NULL;
	size_t len = strlen(s);
	char *dst = malloc(len + 1);
	if (!dst) return NULL;
	dst[len] = 0;
	return cx__strto(dst, (char *)s, toupper);
}

char *cx_strtoupper_i(char *s) {
	if (!s) return NULL;
	size_t len = strlen(s);
	return cx__strto(s, (char *)s, toupper);
}

char *cx_strtolower(const char *s) {
	if (!s) return NULL;
	size_t len = strlen(s);
	char *dst = malloc(len + 1);
	if (!dst) return NULL;
	dst[len] = 0;
	return cx__strto(dst, (char *)s, tolower);
}

char *cx_strtolower_i(char *s) {
	if (!s) return NULL;
	size_t len = strlen(s);
	return cx__strto(s, (char *)s, tolower);
}

char *cx_strpfx(const char *s, size_t len) {
	if (!s || !len) return NULL;
	char *prefix = malloc(len + 1);
	if (!prefix) return NULL;
	prefix[len] = 0;
	return strncpy(prefix, s, len);
}

char *cx_strsfx(const char *s, size_t len) {
	if (!s || !len || !*s) return NULL;
	const char *c = s;
	while (*++c);
	c -= len;
	if (c < s) c = s;
	char *suffix = malloc(len + 1);
	if (!suffix) return NULL;
	suffix[len] = 0;
	return memcpy(suffix, c, len);
}

char *cx_strrstr(const char *s1, const char *s2) {
	char *s = strrchr(s1, *s2);
	if (!s) return NULL;
	if (!strcmp(s, s2)) return s;
//	for (const char *p = s1 + strlen(s1) - 1; p >= s1; p--)
//		if (!strcmp(p, s2)) return (char *)p;
	return NULL;
}

bool cx_strmatch(const char *s, const char *match) {
	if (!s || !match) return false;
	for (const char *c = s; *c; c++)
		for (const char *m = match; *c && *m && *c == *m; c++, m++)
			if (!*(m + 1)) return true;
	return false;
}

bool cx_strhaspfx(const char *s, const char *prefix) {
	if (!s || !prefix) return false;
	for (const char *c = s; *c && *prefix; c++, prefix++)
		if (*c != *prefix) return false;
	return true;
}

bool cx_strhassfx(const char *s, const char *suffix) {
	if (!s || !suffix) return false;
	char *last = strrchr(s, *suffix);
	if (!last) return false;
	if (!strcmp(last, suffix)) return true;
	return false;
}
