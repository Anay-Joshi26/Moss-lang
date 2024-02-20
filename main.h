#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define	CHECK_ALLOC(p) if(p == NULL) {perror(__func__); exit(EXIT_FAILURE);}
#include "tokens.h"
#include "parser.h"

extern Token** tokenize(char* input);
extern char* token_type_to_string(TokenType type);
//extern void parser(Token** tokens);