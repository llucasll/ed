make:
	@echo
	gcc ab.c catalogo.c funcionalidades.c libFilme/*.c -o ~/a
	@echo
	~/a
	@echo
	rm ~/a
	@echo

wget:
	wget http://www2.ic.uff.br/~rosseti/EDA/2018-2/filmes.txt

testePersistencia:
	gcc libFilme/abPersistencia.c testes/testePersistencia.c libFilme/gestorIDs.c libFilme/lib.c -o ~/a;
	~/a
	@echo
	rm ~/a

testeGestorID:
	gcc libFilme/gestorIDs.c testes/testeIDsManagement.c libFilme/lib.c -o ~/a;
	~/a
	@echo
	rm ~/a
