//stdlibs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//debug
#define oi printf("oi\n");
#define oin(n) printf("oi %d", n);

//bool
typedef char bool;
#define true 1
#define false 0

#ifndef basico
	#define basico
	#include "filme.h"
	#undef basico
#endif
