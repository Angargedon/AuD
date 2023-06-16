cc = gcc -Wall
prg = main.exe
obj = main.o datetime.o tools.o menu.o invoice.o

$(prg):	$(obj)
	@$(cc) -o $@ $^

main.o: main.c tools.h datastructure.h
	@$(cc) -c $<

datetime.o: datetime.c datastructure.h
	@$(cc) -c $<

tools.o: tools.c
	@$(cc) -c $<

menu.o: menu.c tools.h datastructure.h
	@$(cc) -c $<

invoice.o: invoice.c tools.h datastructure.h
	@$(cc) -c $<

run:
	@./$(prg)

all: $(prg) run