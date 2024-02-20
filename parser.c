#include "main.h"

void advance(int* i) {
    (*i)++;
}

Expr* parse_primary_expr(Token** tokens, int i) {

    Token* token = tokens[i];

    switch (token->type) {
        case TOKEN_INT:
            NumericLiteral* num = (NumericLiteral*)malloc(sizeof(NumericLiteral));
            num->value = atof(token->value); num->kind = NumericLiteralNodeType;
            return (Expr*)num;
        case TOKEN_IDENTIFIER:
            Identifier* id = (Identifier*)malloc(sizeof(Identifier));
            id->symbol = strdup(token->value); id->kind = IdentifierNodeType; 
            return (Expr*)id;
        default:
            fprintf(stderr, "Error: Unexpected token type: %d\n", token_type_to_string(token->type));
            exit(EXIT_FAILURE);
    }

}

Expr parse_expr(Token** tokens, int* i) {
    
}

Program produceAST(Token** tokens) {

    int i = 0;

    while (tokens[i]->type != TOKEN_EOF) {

        

        advance(&i);
    }

}







