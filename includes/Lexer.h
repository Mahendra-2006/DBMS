#ifndef LEXER_H
#define LEXER_H
#include<string>
#include "Globals.h"
using namespace std;
typedef enum{
    DELETE,
    SET,
    UPDATE,
    EQUAL,
    WHERE,
    FROM,
    SELECT,
    ALL,
    USE,
    DATABASE,
    INSERT,
    INTO,
    CREATE,
    TABLE,
    IDENTIFIER,
    NUMBER,
    COMA,
    LPARAN,
    RPARAN
}TokenType;
typedef struct Token{
    TokenType Type;
    string Value;
}Token;
void Lexer(string query,Token Tokens[],int *TokenCount);
#endif