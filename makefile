make:
	@echo
	@echo > data/a
	rm data/*
	@echo
	gcc application/*.c lib/.c lib.c/filme/*.c lib.c/ab/*.c -o ~/a
	@echo
	~/a
	@echo
	rm ~/a
	@echo

wget:
	wget http://www2.ic.uff.br/~rosseti/EDA/2018-2/filmes.txt

testePersistencia:
	gcc testes/testePersistencia.c lib/lib.c lib/filme/filme.c lib/ab/gestorIDs.c lib/ab/persistencia.c lib/ab/persistenciaAux.c -o ~/a
	@echo
	~/a
	@echo
	rm ~/a

testeGestorID:
	gcc lib/ab/gestorIDs.c testes/testeIDsManagement.c lib/lib.c -o ~/a;
	~/a
	@echo
	rm ~/a
