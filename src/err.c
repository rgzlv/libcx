#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#include <cx/err.h>

char *cx_progname;

void cx_err(const char *fmt, ...) {
	if (cx_progname) fprintf(stderr, "%s: ", cx_progname);
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	if (errno) fprintf(stderr, ": %s", strerror(errno));
	fputc('\n', stderr);
	exit(EXIT_FAILURE);
}

void cx_errx(const char *fmt, ...) {
	if (cx_progname) fprintf(stderr, "%s: ", cx_progname);
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fputc('\n', stderr);
	exit(EXIT_FAILURE);
}
