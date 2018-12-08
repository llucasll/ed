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
int getIntFromFile(char* file); //retorna o primeiro (ou único) inteiro de um arquivo
void putIntToFile(char* file, int i); //escreve um inteiro nos primeiros bytes de um arquivo
void apagarArquivo(char* file);

// trata erros; Deve ser implementada
void erro(int e);

/*
#ifndef basico
	#define basico
	#include "filme.h"
	#undef basico
#
*/
