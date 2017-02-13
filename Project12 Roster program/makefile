readline.o: readline.c readline.h
	gcc -c readline.c
player.o: player.c player.h
	gcc -c player.c
roster.o: roster.c
	gcc -c roster.c
roster: readline.o player.o roster.o
	gcc -o roster readline.o player.o roster.o
