é"CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = sdl2-light.h
SRC = main.c sdl2-light.c sdl2-ttf-light.c manage_data.c manage_texture.c manage_events.c
OBJ = $(SRC:%.c=%.o)
TESTE = test.c

PROG = spacecorridor

%.o: %.c $(INC)
	gcc -g  $(CFLAGS) -c $<

spacecorridor: $(OBJ)
	gcc  -g $(CFLAGS) $(OBJ) $(LDFLAGS)  -o $@ 

teste: teste.c
	gcc  -g $(TESTE) $(OBJ) $(LDFLAGS)  -o $@ 


doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html

