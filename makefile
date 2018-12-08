testeAB:
	@echo
	@echo > data/a
	rm data/*
	@echo
	gcc testes/testeAB.c lib/lib.c lib/filme/filme.c lib/ab/gestorIDs.c lib/ab/persistencia.c lib/ab/persistenciaAux.c lib/ab/ab.c -o ~/a
	@echo
	~/a # < testes/input1TesteAB.txt
	@echo
	rm ~/a

testeFuncionalidades:
	@echo
	gcc application/*.c lib/*.c lib.c/filme/*.c -o ~/a
	@echo
	~/a
	@echo
	rm ~/a
	@echo

make:
	@echo
	@echo > data/a
	rm data/*
	@echo
	gcc application/*.c lib/lib.c lib/filme/*.c lib/ab/*.c -o ~/a
	@echo
	~/a
	@echo
	rm ~/a
	@echo

compilarTudo:
	gcc -c *.c */*.c */*/*.c || make clean
	make clean
	
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
	
clean:
	rm *.o *.out

clear:
	rm *.o *.out
