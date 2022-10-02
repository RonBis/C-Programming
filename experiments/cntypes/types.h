#include <stdbool.h>

#ifndef __TYPES_H
#define __TYPES_H

#define null(type) struct nullable_##type { type val; bool null; }

typedef null(int) _int;
typedef null(float) _float;
typedef null(double) _double;
typedef null(char) _char;

#define toNullable(type, data) data == NULL ? (_##type){ .val = -1, .null = true } : (_##type){ .val = data, .null = false };

#endif
