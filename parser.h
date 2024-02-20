#include <stdio.h>

// AST Node Types
typedef enum {
    ProgramNodeType,
    NumericLiteralNodeType,
    IdentifierNodeType,
    BinaryExprNodeType,
} NodeType;

// Statements do not result in a value at runtime.
// They contain one or more expressions internally
typedef struct {
    NodeType kind;
} Stmt;

// Defines a block which contains many statements.
// Only one program will be contained in a file.
typedef struct {
    NodeType kind;
    Stmt* body;
    size_t body_size;
} Program;

// Expressions will result in a value at runtime unlike Statements
typedef Stmt Expr;

// A operation with two sides separated by an operator.
// Both sides can be ANY Complex Expression.
// Supported Operators -> + | - | / | * | %
typedef struct {
    NodeType kind;
    Expr* left;
    Expr* right;
    char* operator;
} BinaryExpr;

// LITERAL / PRIMARY EXPRESSION TYPES

// Represents a user-defined variable or symbol in source.
typedef struct {
    NodeType kind;
    char* symbol;
} Identifier;

// Represents a numeric constant inside the source code.
typedef struct {
    NodeType kind;
    double value;
} NumericLiteral;
