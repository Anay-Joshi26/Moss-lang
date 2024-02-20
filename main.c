#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define	CHECK_ALLOC(p) if(p == NULL) {perror(__func__); exit(EXIT_FAILURE);}
#include "main.h"

char* token_type_to_string(TokenType type) {
    switch (type) {
        case TOKEN_INT:
            return "TOKEN_INT";
        case TOKEN_PLUS:
            return "TOKEN_PLUS";
        case TOKEN_MINUS:
            return "TOKEN_MINUS";
        case TOKEN_MULTIPLY:
            return "TOKEN_MULTIPLY";
        case TOKEN_DIVIDE:
            return "TOKEN_DIVIDE";
        case TOKEN_IDENTIFIER:
            return "TOKEN_IDENTIFIER";
        case TOKEN_ASSIGN:
            return "TOKEN_ASSIGN";
        case TOKEN_EQUAL:
            return "TOKEN_EQUAL";
        case TOKEN_KEYWORD:
            return "TOKEN_KEYWORD";
        case TOKEN_IF:
            return "TOKEN_IF";
        case TOKEN_ELSE:
            return "TOKEN_ELSE";
        case TOKEN_WHILE:
            return "TOKEN_WHILE";
        case TOKEN_LPAREN:
            return "TOKEN_LPAREN";
        case TOKEN_RPAREN:
            return "TOKEN_RPAREN";
        case TOKEN_LBRACE:
            return "TOKEN_LBRACE";
        case TOKEN_RBRACE:
            return "TOKEN_RBRACE";
        case TOKEN_EOL:
            return "TOKEN_EOL";
        case TOKEN_EOF:
            return "TOKEN_EOF";
        default:
            return "UNKNOWN_TOKEN_TYPE";
    }
}

void free_token(Token* token) {
    free(token->value);
    free(token);
}

void print_token(Token* token) {
    char* type_str = token_type_to_string(token->type);
    
    if (token->value != NULL) {
        printf("Token(type: %s, value: %s)\n", type_str, token->value);
    } else {
        printf("Token(type: %s)\n", type_str);
    }
}

void free_tokens(Token** tokens) {
    for (int i = 0; tokens[i]->type != TOKEN_EOF; i++) {
        free_token(tokens[i]);
    }
    free(tokens);
}


int main() {

    printf("Use this as a simple console to type in code and see the tokenized output\n");

    char input[200];

    fgets(input, sizeof(input), stdin);

    Token** tokens = tokenize(input);

    // Print the tokens
    for (int i = 0; tokens[i] != NULL; i++) {
        print_token(tokens[i]);
    }

    // Free the memory occupied by the tokens
    free_tokens(tokens);

    return 0;
}
