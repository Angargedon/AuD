cc = gcc -Wall
prg = main.exe
obj = main.o datetime.o tools.o calendar.o menu.o

$(prg): $(obj)
	@$(cc) -o $@ $^

main.o: main.c menu.h calendar.h
	@$(cc) -c $<

tools.o: tools.c
	@$(cc) -c $<

datetime.o: datetime.c
	@$(cc) -c $<

calendar.o: calendar.c tools.h
	@$(cc) -c $<

menu.o: menu.c tools.h
	@$(cc) -c $<

run:
	@./$(prg)

all: $(prg) run