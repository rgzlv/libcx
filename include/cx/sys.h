#ifndef CX_SYS_H
#define CX_SYS_H

#if defined(__linux__)
#define CX_SYS_OS_LINUX
#elif defined(__OpenBSD__)
#define CX_SYS_OS_OPENBSD
#elif defined(__FreeBSD__)
#define CX_SYS_OS_FREEBSD
#elif defined(__NetBSD__)
#define CX_SYS_OS_NETBSD
#endif

#if defined(CX_SYS_OS_OPENBSD) || defined(CX_SYS_OS_FREEBSD) || defined(CX_SYS_OS_NETBSD)
#define CX_SYS_OSCAT_BSD
#endif

#if defined(__GNUC__)
#define CX_SYS_LIBC_GLIBC
#endif

#if defined(__x86_64__)
#define CX_SYS_CPU_X86_64
#elif defined(__aarch64__)
#define CX_SYS_CPU_ARM64
#endif

#if !defined(__BYTE_ORDER__)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define CX_SYS_ENDIAN_LITTLE
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define CX_SYS_ENDIAN_BIG
#endif

#endif
