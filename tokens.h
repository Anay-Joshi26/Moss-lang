// tokens.h

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN,
    TOKEN_EQUAL,
    TOKEN_KEYWORD,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_EOL,
    TOKEN_EOF
} TokenType;


typedef struct {
    TokenType type;
    char* value;
} Token;

extern char* keywords[];

