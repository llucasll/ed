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
