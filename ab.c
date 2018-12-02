#include "ab.h"

Filme filmeInvalido = {"", 0, "", "", 0};

No add(Filme f, int t){
    No divisao(No no1, int i, No no2){
        No no3 = criaNo();
        no3.tam = t-1;
        no3.ehFolha = no2.ehFolha;
        int j;
        for(j=0; j<t-1; j++) no3.filmes[j] = no2.filmes[j+t];
        if(!no2.ehFolha){
            No* filhos_no2 = getFilhos(no2);
            No* filhos_no3 = getFilhos(no3);
            for(j=0; j<t; j++){
                filhos_no3[j] = filhos_no2[j+t];
                free(filhos_no2[j+t].filmes);
                filhos_no2[j+t].filmes = (Filme*) NULL;
            }
            updateFilhos(filhos_no2, no2);
            updateFilhos(filhos_no3, no3);
        }
        no2.tam = t-1;
        No* filhos_no1 = getFilhos(no1);
        for(j=no1.tam; j>=i; j--) filhos_no1[j+1] = filhos_no1[j];
        filhos_no1[i] = no3;
        updateFilhos(filhos_no1, no1);
        for(j=no1.tam; j>=i; j--) no1.filmes[j+1]=no1.filmes[j];
        no1.filmes[i-1] = no2.filmes[t-1];
        no1.tam++;
        save(no1);
        return no1;
    }
    No insere_incompleto(No no, Filme f){
        int i = no.tam-1;
        if(no.ehFolha){
            while((i>=0) && (ehMenor(f, no.filmes[i]))){
                no.filmes[i+1] = no.filmes[i];
                i--;
            }
            no.filmes[i+1] = f;
            no.tam++;
            save(no);
            return no;
        }
        while((i>=0) && (ehMenor(f, no.filmes[i]))) i--;
        i++;
        if(getFilho(no, i).tam == ((2*t)-1)) {
            no = divisao(no, i+1, getFilho(no, i));
            if(ehMenor(no.filmes[i], f)) i++;
        }
        No* filhos = getFilhos(no);
        filhos[i] = insere_incompleto(getFilho(no, i), f);
        updateFilhos(filhos, no);
        save(no);
        return no;
    }
    No no = getRaiz();
    printf("%s (%d) \n-> no.tam %d\n\n", f.titulo, f.ano, no.tam); // tamanho do nó não é devidamente atualizado
    if(search(no, f.titulo, f.ano).ano) return no;
    if(no.tam == 0){ // cai nesse caso em todas as vezes
        no = criaNo();
        no.filmes[0] = f;
        //imprimeFilme(f); // imprime vários filmes, sem pular nenhum.
        no.tam = 1;
        save(no);
        return no;
    }
    if(no.tam == (2*t)-1){
        No no_s = criaNo();
        no_s.tam = 0;
        no_s.ehFolha = false;
        No* filhos = getFilhos(no_s);
        filhos[0] = no;
        updateFilhos(filhos, no_s);
        no_s = divisao(no_s,1,no);
        no_s = insere_incompleto(no_s,f);
        save(no_s);
        return no_s;
    }
    no = insere_incompleto(no,f);
    save(no);
    return no;
}

No rm(No no, char* titulo, int ano, int t){
    if(!no.filmes) return no;
    printf("Removendo %s (%d)\n",titulo,ano);
    int i;
    Filme ref;
    strcpy(ref.titulo, titulo);
    ref.ano = ano;
    for(i=0;i<no.tam && ehMenor(no.filmes[i], ref); i++);
    if(i < no.tam && comparaFilmes(no.filmes[i], ref)){ //CASOS 1, 2A, 2B e 2C
        if(no.ehFolha){
            printf("\nCaso 1\n");
            int j;
            for(j=i; j < no.tam-1; j++)
                no.filmes[j] = no.filmes[j+1];
            no.tam--;
            save(no);
            return no;
        }
        No* no_filhos = getFilhos(no);
        if(!no.ehFolha && no_filhos[i].tam >= t){
            printf("\nCaso 2A\n");
            No no2 = no_filhos[i];
            while(!no2.ehFolha) no2 = getFilho(no2, no2.tam); // talvez eu tenha que dar save()
            Filme ftemp = no2.filmes[no2.tam-1];
            no_filhos[i] = rm(no_filhos[i], titulo, ano, t);
            updateFilhos(no_filhos, no);
            no.filmes[i] = ftemp;
            save(no);
            return no;
        }
        if(!no.ehFolha && no_filhos[i+1].tam >= t){
            printf("\nCaso 2B\n");
            No no2 = no_filhos[i+1];
            while(!no2.ehFolha) no2 = getFilho(no2, 0); // talvez eu tenha que dar save()
            Filme ftemp = no2.filmes[0];
            no2 = rm(no_filhos[i+1], titulo, ano, t);
            updateFilhos(no_filhos, no);
            no.filmes[i] = ftemp;
            save(no);
            return no;
        }
        if(!no.ehFolha && no_filhos[i+1].tam == t-1 && no_filhos[i].tam == t-1){
            printf("\nCaso 2C\n");
            No no2 = no_filhos[i];
            No no3 = no_filhos[i+1];
            no2.filmes[no2.tam] = ref;
            int j;
            for(j=0; j<t-1; j++)
                no2.filmes[t+j] = no3.filmes[j];
            No* no2_filhos = getFilhos(no2);
            No* no3_filhos = getFilhos(no3);
            for(j=0; j<=t; j++)
                no2_filhos[t+j] = no3_filhos[j];
            updateFilhos(no2_filhos, no2);
            updateFilhos(no3_filhos, no3);
            no2.tam = 2*t-1;
            for(j=i; j < no.tam-1; j++)
                no.filmes[j] = no.filmes[j+1];
            for(j=i+1; j<= no.tam; j++)
                no_filhos[j] = no_filhos[j+1];
            free(no_filhos[j].filmes);
            no_filhos[j].filmes = NULL;
            no.tam--;
            no_filhos[i] = rm(no_filhos[i], titulo, ano, t);
            updateFilhos(no_filhos, no);
            save(no);
            return no;
        }
    }
    No* no_filhos = getFilhos(no);
    No no2 = no_filhos[i];
    No no3;
    no3.filmes = NULL;
    if(no2.tam == t-1){ // Casos 3A e 3B
        if((i < no.tam) && (no_filhos[i+1].tam >= t)){
            printf("\nCaso 3A\n");
            no3 = no_filhos[i+1];
            no2.filmes[t-1] = no.filmes[i];
            no2.tam++;
            no.filmes[i] = no3.filmes[0];
            int j;
            for(j=0; j < no3.tam-1; j++)
                no3.filmes[j] = no3.filmes[j+1];
            No* no2_filhos = getFilhos(no2);
            No* no3_filhos = getFilhos(no3);
            no2_filhos[no2.tam] = no3_filhos[0];
            for(j=0; j < no3.tam; j++)
                no3_filhos[j] = no3_filhos[j+1];
            updateFilhos(no2_filhos, no2);
            updateFilhos(no3_filhos, no3);
            no3.tam--;
            save(no2);
            save(no3);
            no_filhos[i] = rm(no_filhos[i], titulo, ano, t);
            updateFilhos(no_filhos, no);
            save(no);
            return no;
        }
        if((i>0) && (!no3.filmes) && no_filhos[i-1].tam >= t){
            printf("\nCaso 3A\n");
            no3 = no_filhos[i-1];
            int j;
            for(j = no2.tam; j>0; j--)
                no2.filmes[j] = no2.filmes[j-1];
            No* no2_filhos = getFilhos(no2);
            for(j = no2.tam+1; j>0; j--)
                no2_filhos[j] = no2_filhos[j-1];
            no2.filmes[0] = no.filmes[i-1];
            no2.tam++;
            no.filmes[i-1] = no3.filmes[no3.tam-1];
            No* no3_filhos = getFilhos(no3);
            no2_filhos[0] = no3_filhos[no3.tam];
            updateFilhos(no2_filhos, no2);
            updateFilhos(no3_filhos, no3);
            no3.tam--;
            save(no2);
            save(no3);
            no_filhos[i] = rm(no2, titulo, ano, t);
            save(no);
            return no;
        }
        if(!no3.filmes){
            if(i < no.tam && no_filhos[i+1].tam == t-1){
                printf("\nCaso 3B\n");
                no3 = no_filhos[i+1];
                no2.filmes[t-1] = no.filmes[i];
                no2.tam++;
                int j;
                for(j=0; j<t-1; j++){
                    no2.filmes[t+j] = no3.filmes[j];
                    no2.tam++;
                }
                if(!no2.ehFolha){
                    No* no2_filhos = getFilhos(no2);
                    No* no3_filhos = getFilhos(no3);
                    for(j=0; j<t; j++)
                        no2_filhos[t+j] = no3_filhos[j];
                    updateFilhos(no2_filhos, no2);
                    updateFilhos(no3_filhos, no3);
                }
                for(j=i; j < no.tam-1; j++){
                    no.filmes[j] = no.filmes[j+1];
                    no_filhos[j+1] = no_filhos[j+2];
                }
                updateFilhos(no_filhos, no);
                no.tam--;
                save(no2);
                save(no3);
                no = rm(no, titulo, ano, t);
                save(no);
                return no;
            }
            if((i>0) && (no_filhos[i-1].tam == t-1)){
                printf("\nCaso 3B\n");
                no3 = no_filhos[i-1];
                if(i == no.tam)
                    no3.filmes[t-1] = no.filmes[i-1];
                else
                    no3.filmes[t-1] = no.filmes[i];
                no3.tam++;
                int j;
                for(j=0; j<t-1; j++){
                    no3.filmes[t+1] = no2.filmes[j];
                    no3.tam++;
                }
                if(!no3.ehFolha){
                    No* no2_filhos = getFilhos(no2);
                    No* no3_filhos = getFilhos(no3);
                    for(j=0; j<t; j++)
                        no3_filhos[t+j] = no2_filhos[j];
                    updateFilhos(no2_filhos, no2);
                    updateFilhos(no3_filhos, no3);
                }
                no.tam--;
                no_filhos[i-1] = no3;
                updateFilhos(no_filhos, no);
                save(no2);
                save(no3);
                no = rm(no, titulo, ano, t);
                save(no);
                return no;
            }
        }
    }
    no_filhos[i] = rm(no_filhos[i], titulo, ano, t);
    updateFilhos(no_filhos, no);
    save(no);
    return no;
}

Filme search(No no, char* titulo, int ano){
	if(!no.filmes) return filmeInvalido;
	Filme ref;
	strcpy(ref.titulo, titulo);
	ref.ano = ano;
    int i=0;
	for(i=0 ; i < no.tam ; i++)
        if(!ehMenor(no.filmes[i], ref)) break;
    if(i < no.tam && comparaFilmes(no.filmes[i], ref)) return no.filmes[i];
    if(no.ehFolha) return filmeInvalido;
    return search(getFilho(no, i), titulo, ano);
}

void update(char* titulo, int ano, char* diretor, char* genero, int duracao){
    No no = getRaiz();
    if(!no.filmes) return;
    int i;
    void altera(){
        strcpy(no.filmes[i].diretor,diretor);
        strcpy(no.filmes[i].genero,genero);
        no.filmes[i].duracao = duracao;
        save(no);
        return;
    }
    Filme ref;
    strcpy(ref.titulo,titulo);
    ref.ano = ano;
    while(1){
        for(i=0;i<no.tam;i++){
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
