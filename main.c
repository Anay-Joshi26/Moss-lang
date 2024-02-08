#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define	CHECK_ALLOC(p) if(p == NULL) {perror(__func__); exit(EXIT_FAILURE);}
#include "tokens.h"


char* keywords[2] = {"int", "double"};


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
        default:
            return "UNKNOWN_TOKEN_TYPE";
    }
}

Token* create_token(TokenType type, const char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    CHECK_ALLOC(token);
    token->type = type;
    if (value != NULL) {
        token->value = strdup(value);
    } else {
        token->value = NULL;
    }
    return token;
}

void free_token(Token* token) {
    free(token->value);
    free(token);
}


// use Regex to check if the identifier is valid (ie contains only letters, numbers and underscores)
void is_valid_identifier(char* value) {
    
}



void print_token(Token* token) {
    char* type_str = token_type_to_string(token->type);
    
    if (token->value != NULL) {
        printf("Token(type: %s, value: %s)\n", type_str, token->value);
    } else {
        printf("Token(type: %s)\n", type_str);
    }
}

char* extract_number(char* input, int* i) {
    int start = *i;
    while (isdigit(input[*i])) {
        (*i)++;
    }
    int length = *i - start;
    char* value = (char*)malloc((length + 1) * sizeof(char));
    strncpy(value, input + start, length); value[length] = '\0';
    return value;
}

bool check_if_keyword(char* value) {
    for (int i = 0; i < 2; i++) {
        if (strcmp(value, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}


Token** tokenize(char* input) {

    int input_length = strlen(input);

    Token** tokens = (Token**)malloc((input_length + 1) * sizeof(Token*)); 
    int token_count = 0;
    int i = 0;

    while (i < input_length) {
        if (isspace(input[i])) {
            i++;
        } 
        else if (isdigit(input[i])) { // if its a number
            char* value = extract_number(input, &i);
            tokens[token_count++] = create_token(TOKEN_INT, value);
        } else {
            switch (input[i]) {
                case '+':
                    tokens[token_count++] = create_token(TOKEN_PLUS, NULL); i++;
                    break;
                case '-':
                    tokens[token_count++] = create_token(TOKEN_MINUS, NULL); i++;
                    break;
                case '*':
                    tokens[token_count++] = create_token(TOKEN_MULTIPLY, NULL); i++;
                    break;
                case '/':
                    tokens[token_count++] = create_token(TOKEN_DIVIDE, NULL); i++;
                    break;
                case '=':
                    if (input[i + 1] == '=') {
                        tokens[token_count++] = create_token(TOKEN_EQUAL, NULL);
                        i += 2;
                    } else {
                        tokens[token_count++] = create_token(TOKEN_ASSIGN, NULL); i++;
                    }
                    break;
                break;
                case '(':
                    tokens[token_count++] = create_token(TOKEN_LPAREN, NULL); i++;
                    break;
                case ')':
                    tokens[token_count++] = create_token(TOKEN_RPAREN, NULL); i++;
                    break;
                case '{':
                    tokens[token_count++] = create_token(TOKEN_LBRACE, NULL); i++;
                    break;
                case '}':
                    tokens[token_count++] = create_token(TOKEN_RBRACE, NULL); i++;
                    break;
                case ';':
                    tokens[token_count++] = create_token(TOKEN_EOL, NULL); i++;
                    break;
                default:
                    int start = i;
                    while (isalnum(input[i])) {
                        i++;
                    }
                    int length = i - start;
                    char* value = (char*)malloc((length + 1) * sizeof(char));
                    strncpy(value, input + start, length); value[length] = '\0';

                    if (strcmp(value, "if") == 0) {
                        tokens[token_count++] = create_token(TOKEN_IF, NULL);
                    } 
                    else if (strcmp(value, "else") == 0) {
                        tokens[token_count++] = create_token(TOKEN_ELSE, NULL);
                    } 
                    else if (strcmp(value, "while") == 0) {
                        tokens[token_count++] = create_token(TOKEN_WHILE, NULL);
                    }
                    else if (check_if_keyword(value)) {
                        tokens[token_count++] = create_token(TOKEN_KEYWORD, NULL);
                    }
                    else {
                        tokens[token_count++] = create_token(TOKEN_IDENTIFIER, value); // this is a variable
                    }

                    break;
            }
        }
    }

    // to signal the end of the array as we arent keeping track of the size (otherwise we'd need another variable to keep track of the size of the array)
    // this would use more memory so lets not do that
    tokens[token_count] = NULL;

    return tokens;
}

void free_tokens(Token** tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
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
