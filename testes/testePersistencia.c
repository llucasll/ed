#include "../lib/lib.h"
#include "../lib/ab/persistencia.h"

void erro(int e){
	switch(e){
		case 0:
			return;
		case 1:
			printf("\nErro de abertura de arquivo!\n\n");
			break;
		default:
			printf("\nErro %d desconhecido!\n\n", e);
			break;
	}
	exit(e);
}

Filme monta(char titulo[82], int ano, char diretor[52], char genero[32], int duracao){
	Filme m;
	
	strcpy(m.titulo, titulo);
	m.ano = ano;

	strcpy(m.diretor, diretor);
	strcpy(m.genero, genero);
	m.duracao = duracao;
	
	return m;
}

void monta2(Filme* m, char titulo[82], int ano, char diretor[52], char genero[32], int duracao){
	
	strcpy(m->titulo, titulo);
	m->ano = ano;

	strcpy(m->diretor, diretor);
	strcpy(m->genero, genero);
	m->duracao = duracao;
}
Filme monta3(int i){
	char s[2] = {i+'0', '\0'};
	return monta(s, i, s, s, i);
}

void imprimirFilme(Filme f){
	printf("%s (%d) - %s - %s - %d mins.\n", f.titulo,
			f.ano, f.diretor, f.genero, f.duracao);
}

No teste_getRaiz_save_(void){
	No raiz = getRaiz();
	//printf("%d, %d, %d, %d\n", raiz.id, raiz.ehFolha, raiz.tam, raiz.filmes);
	
	raiz.filmes[0] = monta("Harry Potter", 2002, "Qlqr um", "Documentário", 120);
	raiz.filmes[1] = monta("Dançando nas estrelas", 1945, "Drake Roman", "Romance", 4*60+50);
	//monta2(&raiz.filmes[0], "Harry Potter", 2002, "Qlqr um", "Documentário", 120);
	//monta2(&raiz.filmes[1],"Dançando nas estrelas", 1945, "Drake Roman", "Romance", 4*60+50);
	raiz.tam=2;
	
	imprimirFilme(raiz.filmes[0]);
	imprimirFilme(raiz.filmes[1]);
	//printf("%d, %d, %d, %d\n", raiz.id, raiz.ehFolha, raiz.tam, raiz.filmes);
	save(raiz);
	//printf("%d, %d, %d, %d\n", raiz.id, raiz.ehFolha, raiz.tam, raiz.filmes);
	raiz.id = raiz.ehFolha = raiz.tam = raiz.filmes = 999;
	//printf("%d, %d, %d, %d\n", raiz.id, raiz.ehFolha, raiz.tam, raiz.filmes);
	raiz = getRaiz();
	
	imprimirFilme(raiz.filmes[0]);
	imprimirFilme(raiz.filmes[1]);
	
	return raiz;
}

No teste_getFilhos_updateFilhos(No raiz){
	//No n1 = criaNo(), n2 = criaNo(), n3 = criaNo();
	No* nos = getFilhos(raiz);
	
	//oin(8)
	//alocaFilmes();
	//oi
	
	if(!nos[0].id) nos[0].id = getID();
	if(!nos[1].id) nos[1].id = getID();
	if(!nos[2].id) nos[2].id = getID();

	nos[0].filmes = alocaFilmes();
	nos[1].filmes = alocaFilmes();
	nos[2].filmes = alocaFilmes();
	
	nos[0].ehFolha = true;
	nos[1].ehFolha = true;
	nos[2].ehFolha = true;
	
	nos[0].filmes[0] = monta("Harry Potter", 2002, "Qlqr um", "Documentário", 120);
	nos[1].filmes[0] = monta("Harry Potter", 2002, "Qlqr um", "Documentário", 120);
	nos[2].filmes[0] = monta("Harry Potter", 2002, "Qlqr um", "Documentário", 120);
	
	nos[0].filmes[1] = nos[1].filmes[1] = nos[2].filmes[1] = monta("Dançando nas estrelas", 1945, "Drake Roman", "Romance", 4*60+50);
	nos[0].tam = nos[1].tam = nos[2].tam = 2;
	
	nos[2].filmes[1].ano = 80;
	
	save(nos[0]);
	save(nos[1]);
	save(nos[2]);
	updateFilhos(nos, raiz);
	
	return raiz;
}

void exemploDeUso(void){
	No raiz = getRaiz();
	raiz.filmes[0] = monta("Harry Potter", 2002, "Qlqr um", "Documentário", 120);
	raiz.tam=1;
	save(raiz);
	
	No* filhos = getFilhos(raiz);
	if(!filhos[0].filmes)
		filhos[0] = criaNo();
	if(!filhos[1].filmes)
		filhos[1] = criaNo();
	
	filhos[0].filmes[0] = monta3(1);
	
	filhos[0].tam = 1;
	filhos[1].filmes[0] = monta3(2);
	filhos[1].tam = 1;
	imprimirFilme(filhos[0].filmes[0]);
	
	//salvar os filhos antes, ou a updateFilhos salva?
	updateFilhos(filhos, raiz);
	
	imprimirFilme(getFilho(raiz, 0).filmes[0]);
	
	/* ERRADO (exemplo de uso da getFilho)
	printf("%s\n", getFilho(raiz, 0).filmes[0].titulo);
	printf("%s\n", getFilho(raiz, 1).filmes[0].titulo);
	*/
	
	// CERTO (exemplo de uso da getFilho)
	No n = getFilho(raiz, 0);
	printf("%s\n", n.filmes[0].titulo);
	free(n.filmes);
	n = getFilho(raiz, 1);
	printf("%s\n", n.filmes[0].titulo);
	free(n.filmes);
}

int main(void){
	t = 2;
	
	/*
	No raiz = teste_getFilhos_updateFilhos(teste_getRaiz_save_());
	
	// getFilho
	oin(getFilho(raiz, 2).filmes[1].ano);
	*/
	
	exemploDeUso();
	
	
	
	
	
	
	
	
	
	
	
}
