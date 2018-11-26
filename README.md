# ed
An academic project

## TODO

- [ ] [catalogo.c](https://github.com/llucasll/ed/blob/master/catalogo.c) - 0/1 (0%)
  - [ ] `int main();`

- [ ] [funcionalidades.c](https://github.com/llucasll/ed/blob/master/funcionalidades.c) - 2/5 (40%)
  - [ ] `void inicializa(int t, char *catalogo);`
  - [x] `bool isDirectedBy(Filme f, char *diretor);`
  - [ ] `ListaFilmes directedsBy(char *diretor, AB *a);`
  - [x] `bool isFromGenre(Filme f, char *genero);`
  - [ ] `void removeGenre(AB *a, char *genero);`

- [ ] [abPersistencia.c](https://github.com/llucasll/ed/blob/master/libFilme/abPersistencia.c) - 1/9 (11,11%)
  - [ ] `void getFileName(int id, char* no, char* filhos);`
  - [ ] `No getNoByID(int id);`
  - [ ] `No getRaiz(void);`
  - [ ] `No getFilho(No n, char pos);`
  - [ ] `No getPai(No n);`
  - [ ] `void save(No n);`
  - [ ] `No getNoByID(int id);`
  - [ ] `int* getFilhos(No* no);`
  - [x] `void updateFilhos(int* filhos, No pai)`

- [ ] [ab.c](https://github.com/llucasll/ed/blob/master/ab.c) - 1/4 (25%)
  - [ ] `void add(Filme f);`
  - [ ] `void rm(char* titulo, int ano);`
  - [x] `Filme search(char* titulo, int ano);`
  - [ ] `void update(char* titulo, int ano, char* diretor, char* genero, int duracao);`

- [x] [filme.c](https://github.com/llucasll/ed/blob/master/libFilme/filme.c) - 6/6 (100%)
  - [x] `bool checaFilme(Filme* f, char* titulo, int ano);`
  - [x] `bool comparaFilmes(Filme *a, Filme *b);`
  - [x] `bool ehMenor(Filme* a, Filme* b);`
  - [x] `void imprimeFilme(Filme* f);`
  - [x] `void nextString(FILE *f, char *saida, char *separador);`
  - [x] `Filme getFilme(FILE *f);`

- [x] [gestorIDs.c](https://github.com/llucasll/ed/blob/master/libFilme/gestorIDs.c) - 3/3 (100%)
  - [x] `FILE* abrir(char* nome);`
  - [x] `void liberarID(unsigned int id);`
  - [x] `unsigned int getID(void);`

- [x] [listaFilmes.c](https://github.com/llucasll/ed/blob/master/libFilme/listaFilmes.c) - 8/8 (100%)
  - [x] `ListaFilmes * cria();`
  - [x] `Filme * busca(ListaFilmes *l, char *titulo, int ano);`
  - [x] `Filme * busca(ListaFilmes *l, Filme *f);`
  - [x] `ListaFilmes * insere(ListaFilmes *l, Filme *f);`
  - [x] `ListaFilmes * retira(ListaFilmes *l, char *titulo, int ano);`
  - [x] `ListaFilmes * retira(ListaFilmes *l, Filme *f);`
  - [x] `void imprime(ListaFilmes *l);`
  - [x] `void libera(ListaFilmes *l);`

#### Completude:
Módulos: 3/7 (42,86%)  
Funções: 21/36 (58,33%)
