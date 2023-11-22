cc = gcc -Wall
prg = ueb01.exe
obj = ueb01.o datetime.o tools.o

$(prg): $(obj)
	@$(cc) -o $@ $^

ueb01.o: ueb01.c datetime.h tools.h
	@$(cc) -c $<

tools.o: tools.c
	@$(cc) -c $<

datetime.o: datetime.c
	@$(cc) -c $<

run:
	@./$(prg)

all: $(prg) run