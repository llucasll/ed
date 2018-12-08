#include "persistencia.h"
#include "persistenciaAux.h"

No maiorFolha(No raiz){
	No maiorNo(No raiz){
		if(raiz.ehFolha)
			return raiz;
		else{
			free(raiz.filmes);
			return maiorNo(getFilho(raiz, raiz.tam));
		}
	}

	return raiz.ehFolha? raiz : maiorNo(getFilho(raiz, raiz.tam));
}

No menorFolha(No raiz){
	No menorNo(No raiz){
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
		printf("Erro! Não é possível remover o filme %s do Nó %d pois ele já está com apenas %d Filmes!\n", titulo, n.id, t-1);
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

int addFilme(No* ref, Filme f){
	No n = *ref;
	
	if(n.tam >= 2*t-1){
		printf("Erro! Não é possível add o filme %s no Nó %d pois ele já está cheio!\n", f.titulo, n.id);
		return -1;
	}
	
	int i;
	for(i=0; i<n.tam; i++)
		if(ehMenor(f, n.filmes[i])){// eh o mesmo filme
			No* filhos;
			if(!n.ehFolha)
				filhos = getFilhos(n);
			for(int j=n.tam-1; j>=i; j--){
				n.filmes[j+1] = n.filmes[j];
				if(!n.ehFolha)
					//oin(filhos[j+1].filmes[0].ano);
					filhos[j+2] = filhos[j+1];
			}
			if(!n.ehFolha){
				filhos[i+1] = vazio;
				filhos[i+1].id = -1;
				n.tam++;
				updateFilhos(filhos, n);
				n.tam--;
			}
			n.filmes[i] = f;
			n.tam++;
			break;
		}
	
	if(i>=n.tam){
		// Se for maior do que todos os outros
		n.filmes[n.tam] = f;
		n.tam++;
	}
	
	*ref = n;
	
	return i;
}

// Ainda é preciso chamar a save() para o pai e para o filho, para concluir a operação.
void divisao(No* paiRef, No* filhoRef, int pos){ // pos = posição do filho dentro do pai
	No pai = *paiRef;
	No filho = *filhoRef;
	
	bool excecao = false;
	if(pai.tam == 0)
		excecao = true;
	//if(pai.tam != 0)
		//printaArvore();
	
	// Subir Filme do meio para o pai
	//oin(pai.id);
	//imprimeFilme(filho.filmes[filho.tam/2]); scanf("%s");
	//inspectNo(getNoByID(pai.id));
	addFilme(&pai, filho.filmes[filho.tam/2]);
	//oin(pai.tam)
	save(pai);
	//inspectNo(getNoByID(pai.id));
	//oin(getNoByID(pai.id).tam);
	//pai = getNoByID(pai.id);
	//imprimeFilme(pai.filmes[0]);
	//printaArvore();
	
	if(excecao)
		pai.tam = 0;
	// Preparar para criar o novo nó
	No* irmaos = getFilhos(pai);
	if(pai.tam == 0) // caso em que estamos dividindo a própria raíz
		irmaos[0] = filho;
	if(excecao)
		pai.tam = 1;
	
	// Criar novo nó
	#define novo irmaos[pos+1]
	novo = criaNo();
	for(int i=filho.tam/2+1; i<filho.tam; i++)
		novo.filmes[i-(filho.tam/2+1)] = filho.filmes[i];
	novo.tam = filho.tam-(filho.tam/2+1);
	//printaNo(novo, 0);
	novo.ehFolha = filho.ehFolha;
	save(novo);
	//inspectNo(getNoByID(novo.id));
	
	// Atualizar descendências
	if(!filho.ehFolha){
		No* primFilhos = getFilhos(filho); // Vetor com os filhos que vao manter a referencia
		No* ultFilhos = getFilhos(filho); // Vetor com os filhos que vao passar para o nó criado
		
		for(int i=filho.tam/2+1; i<=filho.tam; i++)
			ultFilhos[i-(filho.tam/2+1)] = primFilhos[i];
		
		// Já defini o tam lá em cima
		//novo.tam = filho.tam -filho.tam/2 -1;
		//save(novo)
		updateFilhos(ultFilhos, novo);
		
		filho.tam -= filho.tam/2 +1;
		save(filho);
		updateFilhos(primFilhos, filho);
	}
	#undef novo
	else{
		filho.tam -= filho.tam/2 +1;
		save(filho);
		//inspectNo(getNoByID(filho.id));
	}
	
	//printaArvore();
	//inspectNo(getNoByID(pai.id));
	//inspectNo(getNoByID(novo.id));
	// Atualizar o pai com o novo filho
	updateFilhos(irmaos, pai);
	
	//printaArvore();
	// Atualizar na função que chamou
	*paiRef = getNoByID(pai.id);
	//oin(paiRef->tam);oi
	//oin(888)
	//inspectNo(*paiRef);
	*filhoRef = getNoByID(filho.id);
	//inspectNo(*filhoRef);
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

bool anterior(Filme a, char* titulo, int ano){ // Diz se o filme deve ficar antes dessa chave
	//oin(a.ano)
	//oin(ano)
	if(a.ano!=ano) return a.ano<ano;
	int t = strcmp(a.titulo, titulo);
	if(!t || t==1) return false;
	return true;
}

No filhoCandidato(No pai, char* titulo, int ano, int* pos){ // Retorna o filho onde a chave pode se encontrar
	for(int i=0; i<pai.tam; i++){//oin(i) oin(pai.tam)
		//oin(!anterior(pai.filmes[i], titulo, ano))
		if(!anterior(pai.filmes[i], titulo, ano)){
			if(pos)
				*pos = i;
			return getFilho(pai, i);
		}
	}
	*pos = pai.tam;
	return getFilho(pai, pai.tam);
}

void add(Filme f){
	void addInterno(No no){
		//No no = *ref;
		if(no.ehFolha){
			addFilme(&no, f);
			save(no);
		}
		else{
			int pos;
			//oin(no.id)
			//oin(no.tam)
			No candidato = filhoCandidato(no, f.titulo, f.ano, &pos);
			if(candidato.tam >= 2*t-1)
				divisao(&no, &candidato, pos);
			// Rever o candidato; com a subida de um filme, pode não ser mais o mesmo
			free(candidato.filmes);
			candidato = filhoCandidato(no, f.titulo, f.ano, &pos);
			
			//oin(no.id)
			//oin(no.tam)
			save(no);
			addInterno(candidato);
		}
		//*ref = no;
	}
	
	No raiz = getRaiz();
	/*
	oin(raiz.tam)
	FILE* x=fopen("data/1.node", "r");
	if(x){
		oin(fileSize(x))
		oin(sizeof(Filme))
		oin(fileSize(x)/sizeof(Filme))
		fclose(x);
	}
	*/
	if(raiz.tam >= 2*t-1){
		No novaRaiz = criaNo();
		
		novaRaiz.ehFolha = false;
		divisao(&novaRaiz, &raiz, 0);
		save(raiz);
		
		atualizaRaiz(novaRaiz);
		raiz = novaRaiz;
	}
	
	addInterno(raiz);
	//save(raiz);
}
void rm(char* titulo, int ano){

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
