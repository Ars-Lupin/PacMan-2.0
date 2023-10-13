CC=gcc
CFLAGS=-lm
DEPS=tMapa.h tTunel.h tPacMan.h tPosicao.h tMovimento.h
OBJ=main.o tMapa.o tTunel.o tPacMan.o tPosicao.o tMovimento.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

principal: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

clean:
	rm -rf *.o principal

run:
	./principal
