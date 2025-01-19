#ifndef CX_ERR_H
#define CX_ERR_H

extern char *cx_progname;

void cx_err(const char *fmt, ...);
void cx_errx(const char *fmt, ...);

#endif
