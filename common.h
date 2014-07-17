#ifndef _COMMON_H
#define _COMMON_H

#include <linux/version.h>
#include <sys/types.h>

typedef unsigned char u_byte_t;
typedef unsigned short int u_word_t;
typedef unsigned int u_dword_t;
typedef unsigned long long int u_qword_t;
typedef char byte_t;
typedef short int word_t;
typedef int dword_t;
typedef long long int qword_t;
#endif

#ifndef FALSE
#  define FALSE  0
#endif

#ifndef TRUE
#  define TRUE   1
#endif

typedef int __bool_t;			/* Boolean, true or false */

typedef qword_t __tod_t;

#define MIN(a,b)  ( (a) < (b) ? (a) : (b) )
#define MAX(a,b)  ( (a) > (b) ? (a) : (b) )
#define ABS(a)    ( (a) < 0 ? -(a) : (a) )

#ifndef CTRL
#  define CTRL(x)    ((x) & 0x1f)
#endif