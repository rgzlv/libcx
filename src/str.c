#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

bool cx_strsfx(const char *s, const char *suffix) {
	if (!s || !suffix || !*suffix) return false;
	char *last = strrchr(s, *suffix);
	if (!last) return false;
	if (!strcmp(last, suffix)) return true;
	return false;
}
