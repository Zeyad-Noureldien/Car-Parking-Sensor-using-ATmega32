#ifndef STANDARD_TYPES_H_
#define STANDARD_TYPES_H_

typedef unsigned char boolean;

#ifndef FALSE
#define FALSE      (0u)
#endif

#ifndef TRUE
#define TRUE       (1u)
#endif

#define LOGIC_LOW  (0u)
#define LOGIC_HIGH (1u)

#define NULL_PTR ((void *)0)

typedef unsigned char      uint8;        /* 256, from 0 to 255 */
typedef signed char        sint8;        /* 256, from -128 to 127 */
typedef unsigned short     uint16;       /* 65536, from 0 to 65535 */
typedef signed short       sint16;       /* 65536, from -32768 to 32767 */
typedef unsigned long      uint32;       /* 4294967296, from 0 to 4294967295 */
typedef signed long        sint32;       /* 4294967296, from -2147483648 to 4294967295 */
typedef unsigned long long uint64;       /* 18446744073709551616, from 0 to 18446744073709551615 */
typedef signed long long   sint64;       /* 18446744073709551616, from -92233720368 to 92233720367 */
typedef float              float32;
typedef double             float64;

#endif
