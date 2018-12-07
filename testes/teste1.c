#include "../lib/ab/persistencia.h"

int main(void){
	No no;
	FILE* f = fopen("data/0.node", "r");
	if(!f) oi;
	fread(&no, sizeof(No), 1, f);
	printf("%d, %d, %d\n", no.id, no.ehFolha);
}
