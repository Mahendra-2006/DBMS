#include<iostream>
#include <filesystem>
using namespace std;
#include "Lexer.h"
#include "Parser.h"
#include "Globals.h"
int main(){
    namespace fs = std::filesystem;
    Token Tokens[100];
    int Tokencount = 0;
    string query;
    while(true){
        cout << "\nMDBMS> ";
        getline(cin ,query);
        if(query == "EXIT"){
            break;
        }
        Lexer(query,Tokens,&Tokencount);
        Parser(Tokens,&Tokencount);
    }
    return 0;
}