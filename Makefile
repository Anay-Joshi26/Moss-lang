PROJECT = moss
HEADERS = tokens.h main.h
OBJ = main.o lexer.o

C11 = cc
CFLAGS = -Wall -Werror -std=c11

$(PROJECT): $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ)

%.o: %.c $(HEADERS)
	$(C11) $(CFLAGS) -c $<

clean:
	rm -f $(PROJECT) $(OBJ)
