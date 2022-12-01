CC		 = gcc
EXEC	 = Maze
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = map.o terminal.o GenerateMap.o main.o commands.o #visibility.o

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

# ifdef DARK           #meant to be used for visibility but unable to achieve
# CFLAGS += -D DARK
# DARK : clean $(EXEC)
# endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c map.h terminal.h
	$(CC) $(CFLAGS) main.c -c

map.o : map.c map.h
	$(CC) $(CFLAGS) map.c -c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

GenerateMap.o : GenerateMap.c GenerateMap.h
	$(CC) $(CFLAGS) GenerateMap.c -c

commands.o : commands.c commands.h
	$(CC) $(CFLAGS) commands.c -c

# visibility.o : visibility.c visibility.h
# 	$(CC) $(CFLAGS) visibility.c -c

clean:
	rm -f $(EXEC) $(OBJ)
