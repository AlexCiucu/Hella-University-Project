#ifndef STD_TYPES_H
#define STD_TYPES_H

/* @Std_Types.h@@ */


/* Boolean */

typedef unsigned char         boolean;       /*        TRUE .. FALSE           */


/* Integral */

typedef signed char           sint8;         /*        -128 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32768 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed int            sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned int          uint32;        /*           0 .. 4294967295      */
typedef signed long long      sint64;  /* -9223372036854775808 .. 9223372036854775807  */

typedef uint8                 Std_ReturnType;

/* Boolean values */

#ifndef TRUE
#define TRUE   ((boolean) 1)

#endif
#ifndef FALSE
#define FALSE  ((boolean) 0)

#endif

/* Base Standard types */

#define STD_HIGH      0x01                    /* Physical state 5V or 3.3V */

#define STD_LOW       0x00                    /* Physical state 0V */

#define STD_ACTIVE    0x01                    /* Logical state active */

#define STD_INACTIVE  0x02                    /* Logical state active */

#define STD_IDLE      0x00                    /* Logical state idle */

#define STD_ON        0x01                    /* ON state */

#define STD_OFF       0x00                    /* OFF state */

#define E_OK          ((uint8)0x00)          /* Return code for no failure/error */

#define E_NOT_OK      ((uint8)0x01)          /* Return code for failure/error */

#define NULL_PTR      (void *)0               /* Null pointer */

#endif
