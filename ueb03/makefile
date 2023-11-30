cc = gcc -Wall -pedantic
prg = main.exe
obj = main.o datetime.o tools.o calendar.o menu.o

$(prg): $(obj)
	@$(cc) -O0 -g3 -o $@ $^

main.o: main.c menu.h calendar.h
	@$(cc) -O0 -g3 -c $<

tools.o: tools.c
	@$(cc) -O0 -g3 -c $<

datetime.o: datetime.c
	@$(cc) -O0 -g3 -c $<

calendar.o: calendar.c tools.h
	@$(cc) -O0 -g3 -c $<

menu.o: menu.c tools.h
	@$(cc) -O0 -g3 -c $<

run:
	@./$(prg)

all: $(prg) run