//stdlibs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//debug
#define oi printf("oi\n");
#define oin(n) printf("oi %d\n", n);

//bool
typedef char bool;
#define true 1
#define false 0

int t;

int getInt(char* s);
char* getString(char* s, int tamMax);

int fileSize(FILE* f);
bool dirExiste(char* nome);
FILE* abrir(char* nome);

// trata erros; Deve ser implementada
void erro(int e);

/*
#ifndef basico
	#define basico
	#include "filme.h"
	#undef basico
#
*/
