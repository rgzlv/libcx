#ifndef CX_STR_H
#define CX_STR_H

#include <stddef.h>
#include <stdbool.h>

char *cx_strcat(const char *s1, const char *s2);
char *cx_strtoupper(const char *s);
char *cx_strtoupper_i(char *s);
char *cx_strtolower(const char *s);
char *cx_strtolower_i(char *s);
char *cx_strpfx(const char *s, size_t len);
char *cx_strsfx(const char *s, size_t len);
char *cx_strrstr(const char *s1, const char *s2);
bool cx_strmatch(const char *s, const char *match);
bool cx_strhaspfx(const char *s, const char *prefix);
bool cx_strhassfx(const char *s, const char *suffix);
bool cx_streq(const char *s1, const char *s2);
bool cx_strneq(const char *s1, const char *s2, size_t n);

#endif
