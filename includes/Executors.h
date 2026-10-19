#ifndef EXECUTORS_H
#define EXECUTORS_H
#include<string>
#include "Globals.h"
using namespace std;
void ExecuteCreateDataBase(Token Token,int Tokencount);
void ExecuteUseDatabase(Token t);
void ExecuteCreateTable(Token TableName,Token Columns[],int TotalColumns);
void ExecuteInsertInto(Token Tokens[],int Tokencount);
void ExecuteSelectAllStatement(Token Tokens[],int Tokencount);
void ExecuteSelectIdentifierStatement(string Table , string Column);
void ExecuteSelectIdentifierWithConditionStatement(string Table,string FirstColumn,string SecondColumn,string Condition);
void ExecuteUpdateStatement(string Table , string FirstColumn , string SecondColumn , string Condition , string Setter);
void ExecuteDeleteStatement(string Table,string Column,string Condition);
#endif