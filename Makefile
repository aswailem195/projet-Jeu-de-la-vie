program:affichage.o tester.o jeu_de_vie.o
	gcc $^ -g -o  $@ $(shell sdl2-config --cflags --libs)


%.o:%.c
	gcc $^ -c -g -o $@ $(shell sdl2-config --cflags --libs)


clean:
	rm *.o
