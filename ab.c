#include "ab.h"

void add(Filme f){
    No* divisao(No* no1, int i, No* no2){
        No* no3 = criaNo();
        no3->tam = t-1;
        no3->ehFolha = no2->ehFolha;
        int j;
        for(j=0; j<t-1; j++) no3->filmes[j] = no2->filmes[j+t];
        if(!no2->ehFolha){
            No* filhos_no2 = getFilhos(no2);
            No* filhos_no3 = getFilhos(no3);
            for(j=0; j<t; j++){
                filhos_no3[j] = filhos_no2[j+t];
                filhos_no2[j+t] = NULL;
            }
            updateFilhos(filhos_no2, no2);
            updateFilhos(filhos_no3, no3);
        }
        no2->tam = t-1;
        No* filhos_no1 = getFilhos(no1);
        for(j=no1->tam; j>=i; j--) filhos_no1[j+1] = filhos_no1[j];
        filhos_no1[i] = no3;
        updateFilhos(filhos_no1, no1);
        for(j=no1->tam; j>=i; j--) no1->filmes[j+1]=no1->filmes[j];
        no1->filmes[i-1] = no2->filmes[t-1];
        no1->tam++;
        return no1;
    }
    No* insere_incompleto(No* no, Filme f){
        int i = no->tam-1;
        if(no->ehFolha){
            while((i>=0) && (ehMenor(f, no->filmes[i]))){
                no->filmes[i+1] = no->filmes[i];
                i--;
            }
            no->filmes[i+1] = f;
            no->tam++;
            return no;
        }
        while((i>=0) && (ehMenor(f, no->filmes[i]))) i--;
        i++;
        if(getFilho(no, i)->tam == ((2*t)-1)) {// getFilho recebe ponteiro, passei variável
            no = divisao(no, i+1, getFilho(no, i));
            if(ehMenor(no->filmes[i], f)) i++;
        }
        No* filhos = getFilhos(no);
        filhos[i] = insere_incompleto(getFilho(no, i), f);
        updateFilhos(filhos, no);
        return no;
    }

    No no = getRaiz();
    if(search(no, f)) return no;
    if(!no){
        no = criaNo();
        no->filmes[0] = f;
        no->tam = 1;
        return no;
    }
    if(no->tam == (2*t)-1){
        No* no_s = criaNo();
        no_s->tam = 0;
        no_s->ehFolha = false;
        No* filhos = getFilhos(no_s);
        filhos[0] = no;
        updateFilhos(filhos, no_s);
        no_s = divisao(no_s,1,no);
        no_s = insere_incompleto(no_s,f);
        return no_s;
    }
    no = insere_incompleto(no,f);
    return no;
}

void rm(char* titulo, int ano);

Filme search(No no, char* titulo, int ano){
	if(!no) return NULL;
	Filme ref;
	strcpy(ref.titulo, titulo);
	ref.ano = ano;
    int i=0;
	for(i=0 ; i < no.tam ; i++)
        if(!ehMenor(no.filmes[i], ref)) break;
    if(i < no.tam && comparaFilmes(&no.filmes[i], &ref)) return no.filmes[i]; // TODO verificar
    if(no.ehFolha) return NULL;
    return search(getFilho(no, i), titulo, ano);
}

void update(char* titulo, int ano, char* diretor, char* genero, int duracao){
    No no = getRaiz();
    if(!no) return NULL;
    void altera(){
        strcpy(no.filmes[i]->diretor,diretor);
        strcpy(no.filmes[i]->genero,genero);
        no.filmes[i]->duracao = duracao;
        save(no);
        return;
    }
    Filme ref;
    strcpy(ref.titulo,titulo);
    ref.ano = ano;
    while(1){
        for(int i=0;i<no.tam;i++){
            if(checaFilme(no.filmes[i], titulo, ano)){
                altera();
                return;
            }
            if(ehMenor(ref,no.filmes[i])){
                if(no.ehFolha) return;
                no = getFilho(no, i);
                break;
            }
        }
    }
}

/*
const int t = 2;

typedef struct ArvB{
  int nchaves, folha, *chave;
  struct ArvB **filho;
}TAB;

TAB *Cria(int t);
TAB *Libera(TAB *a);
void Imprime(TAB *a, int andar);
TAB *Busca(TAB* x, int ch);
TAB *Divisao(TAB *x, int i, TAB* y, int t);
TAB *Insere_Nao_Completo(TAB *x, int k, int t);
TAB *Insere(TAB *T, int k, int t);
TAB* remover(TAB* arv, int ch, int t);
TAB* retira(TAB* arv, int k, int t);
int testar(int argc, char *argv[]);
*/
