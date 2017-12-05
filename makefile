runit: Main.o Producer.o Consumer.o
	gcc -o runit Main.o Consumer.o Producer.o
Main.o: Main.c
	gcc -c Main.c
Producer.o: Producer.c
	gcc -c Producer.c
Consumer.o: Consumer.c #if this file is altered
	gcc -c Consumer.c #then recompile it!