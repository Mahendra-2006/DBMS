#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include "Executors.h"
#include "Globals.h"
void Parser(Token Tokens[],int *Tokencount);
void parseDeleteStatement(Token Tokens[],int Tokencount);
void parseUpdateStatement(Token Tokens[],int Tokencount);
void parseSelectIdentifierWithConditionStatement(Token Tokens[],int Tokencount);
void parseSelectIdentifierStatement(Token Tokens[],int Tokencount);
void parseSelectAllStatement(Token Tokens[],int Tokencount);
void parseCreateDatabase(Token Tokens[],int Tokencount);
void parseUseDatabase(Token t);
void parseCreateTable(Token Tokens[],int Tokencount);
void parseInsertInto(Token Tokens[],int Tokencount);
#endif