#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
#include "Lexer.h"
#include "Globals.h"
using namespace std;
void Lexer(string query,Token Tokens[],int *TokenCount){
    int Tokencount = 0;
    for(int i=0;i<query.length();i++){
        if(isspace(query[i])){
            continue;
        }
        else if(isalpha(query[i])){
            Token t;
            int j=0;
            char identifier[50];
            while(isalpha(query[i])){
                identifier[j++] = query[i++];
            }
            identifier[j] = '\0';
            if(strcmp(identifier,"CREATE") == 0){
                t.Type = CREATE;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"INSERT") == 0){
                t.Type = INSERT;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"UPDATE") == 0){
                t.Type = UPDATE;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"SET") == 0){
                t.Type = SET;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"DELETE") == 0){
                t.Type = DELETE;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"WHERE") == 0){
                t.Type = WHERE;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"SELECT") == 0){
                t.Type = SELECT;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"FROM") == 0){
                t.Type = FROM;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"INTO") == 0){
                t.Type = INTO;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"USE") == 0){
                t.Type = USE;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"TABLE") == 0){
                t.Type = TABLE;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else if(strcmp(identifier,"DATABASE") == 0){
                t.Type = DATABASE;
                t.Value = identifier;
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
            else{
                t.Type = IDENTIFIER;
                t.Value = identifier; 
                Tokens[Tokencount++] = t;
                i--;
                continue;
            }
        }
            else if(query[i] == '('){
                Token t;
                t.Type = LPARAN;
                t.Value = "(";
                Tokens[Tokencount++] = t;
                continue;
            }
            else if(query[i] == '='){
                Token t;
                t.Type = EQUAL;
                t.Value = "=";
                Tokens[Tokencount++] = t;
                continue;
            }
            else if(query[i] == ','){
                Token t;
                t.Type = COMA;
                t.Value = ",";
                Tokens[Tokencount++] = t;
                continue;
            }
            else if(query[i] == ')'){
                Token t;
                t.Type = RPARAN;
                t.Value = ")";
                Tokens[Tokencount++] = t;
                continue;
            } 
            else if(query[i] == '*'){
                Token t;
                t.Type = ALL;
                t.Value = "*";
                Tokens[Tokencount++] = t;
                continue;
            }
            else if(isdigit(query[i])){
                Token t;
                int j=0;
                char number[50];
                while(isdigit(query[i])){
                    number[j++] = query[i++];
                }
                number[j] = '\0';
                t.Type = NUMBER;
                t.Value = number;
                Tokens[Tokencount++] = t;
                i--;
                continue;
        }
    }
    *TokenCount = Tokencount;
}