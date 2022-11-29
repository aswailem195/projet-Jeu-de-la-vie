program:affichage.o update.o jeu_de_vie.o voisines.o
	gcc $^ -g -o  $@ $(shell sdl2-config --cflags --libs)


%.o:%.c
	gcc $^ -c -g -o $@ $(shell sdl2-config --cflags --libs)


clean:
	rm *.o
