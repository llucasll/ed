void inicializa(int i, char *catalogo); //g

typedef struct{
	//chave primária composta
	char titulo[82];
	int ano;
	
	//outros campos
	char diretor[52];
	char genero[32];
	int duracao;
} Filme;

Filme getFilme(FILE *f); //g
void nextString(FILE *f, char *saida, char *separador); //l
//while(!feof(f))

//void inserção e remoção - l
//Filme busca - g
//alteração - p

//Lista encadeada de filmes - p

bool isDirectedBy(Filme f, char *diretor); //l
ListaFilmes directedsBy(char *diretor, TARVB *a); //l

bool isFromGenre(Filme f, char *genero); //detecta substring - l
void removeGenre(TARVB *a, char *genero); //l

bool menor(Filme a, Filme b); //Se a < b, ordenando primeiramente por ano - g

//TARVB* load(void);
void save(TARVB *a);
