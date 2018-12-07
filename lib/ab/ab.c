#include "persistencia.h"
#include "persistenciaAux.h"

No maiorFolha(No* raiz){
	No maiorNo(No* raiz){
		if(raiz.ehFolha)
			return raiz;
		else{
			free(raiz.filmes);
			return maiorNo(getFilho(raiz, raiz.tam));
		}
	}

	return raiz.ehFolha? raiz : maiorNo(getFilho(raiz, raiz.tam));
}

No menorFolha(No* raiz){
	No menorNo(No* raiz){
		if(raiz.ehFolha)
			return raiz;
		else{
			free(raiz.filmes);
			return menorNo(getFilho(raiz, 0));
		}
	}
	
	return raiz.ehFolha? raiz : menorNo(getFilho(raiz, 0));
}

// Informa se o filme existia no No
bool removerFilme(No n, char* titulo, int ano){
	if(n.tam <= t-1){
		printf("Erro! Não é possível remover o filme %s do Nó %d pois ele já está com apenas %d Filmes!\n", f.titulo, n.id, t-1);
		return false;
	}
	
	for(int i=0; i<n.tam; i++)
		if(checaFilme(n.filmes[i], titulo, ano)){// eh o mesmo filme
			for(int j=i+1; j<n.tam; j++)
				n.filmes[i] = n.filmes[j];
			n.tam--;
			return true;
		}
	return false;
}

int addFilme(No n, Filme f){
	if(n.tam >= 2*t-1){
		printf("Erro! Não é possível add o filme %s no Nó %d pois ele já está cheio!\n", f.titulo, n.id);
		return -1;
	}
	
	int i;
	for(i=0; i<n.tam; i++)
		if(ehMenor(f, n.filmes[i])){// eh o mesmo filme
			if(!n.ehFolha)
				No* filhos = getFilhos(n);
			for(int j=n.tam-1; j>=i; j--){
				n.filmes[j+1] = n.filmes[j];
				if(!n.ehFolha)
					filhos[j+2] = filhos[j+1];
			}
			if(!n.ehFolha){
				filhos[i+1] = vazio;
				filhos[i+1].id = -1;
				updateFilhos(n, filhos);
			}
			n.filmes[i] = f;
			n.tam++;
			break;
		}
	
	// Se for maior do que todos os outros
	n.filmes[n.tam] = f;
	n.tam++;
	
	return i;
}

// Ainda é preciso chamar a save() para o pai e para o filho, para concluir a operação.
void divisao(No pai, No filho, int pos){ // pos = posição do filho dentro do pai
	
	// Subir Filme do meio para o pai
	addFilme(pai, filho.filmes[filho.tam/2]);
	
	// Preparar para criar o novo nó
	No* irmaos = getFilhos(pai);
	
	// Criar novo nó
	#define novo irmaos[pos+1]
	novo = criaNo();
	for(int i=filho.tam/2+1; i<filho.tam; i++)
		novo.filmes[i-filho.tam/2+1] = filho.filmes[i];
	novo.tam = filho.tam-(filho.tam/2+1);
	novo.ehFolha = filho.ehFolha;
	save(novo);
	
	// Atualizar descendências
	if(!ehFilho.folha){
		No* primFilhos = getFilhos(filho); // Vetor com os filhos que vao manter a referencia
		No* ultFilhos = getFilhos(filho); // Vetor com os filhos que vao passar para o nó criado
		
		for(int i=filho.tam/2+1; i<=filho.tam; i++)
			ultFilhos[i-filho.tam/2+1] = primFilhos[i];
		
		// Já defini o tam lá em cima
		//novo.tam = filho.tam -filho.tam/2 -1;
		//save(novo)
		updateFilhos(novo, ultFilhos);
		
		filho.tam = filho.tam/2 -1;
		//save(filho);
		updateFilhos(filho, primFilhos);
	}
	#undef novo
	
	// Atualizar o pai com o novo filho
	updateFilhos(pai, irmaos);
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
