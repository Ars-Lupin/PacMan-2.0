CC=gcc
CFLAGS= -g
DEPS=tMapa.h tTunel.h tPacMan.h tPosicao.h tMovimento.h tFantasma.h tJogo.h
OBJ=main.o tMapa.o tTunel.o tPacMan.o tPosicao.o tMovimento.o tFantasma.o tJogo.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

principal: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

clear:
	rm -rf *.o principal

run:
	./principal
