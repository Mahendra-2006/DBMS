#include<iostream>
#include<string>
#include "Lexer.h"
#include "Executors.h"
#include "Globals.h"
using namespace std;
void parseInsertInto(Token Tokens[],int Tokencount){
    Token InsertIntoCommand[10];
    int j=0;
    for(int i=2;i<Tokencount;i++){
        InsertIntoCommand[j++] = Tokens[i]; 
    }
    ExecuteInsertInto(InsertIntoCommand,j--);
}   
void parseCreateTable(Token Tokens[],int Tokencount){
    Token TableName = Tokens[0];
    Token Columns[50];
    int j=0;
    for(int i=1;i<Tokencount;i++){
        Columns[j++] = Tokens[i];
    }
    ExecuteCreateTable(TableName,Columns,j--);
}
void parseUseDatabase(Token t){
    ExecuteUseDatabase(t);
}
void parseCreateDatabase(Token Tokens[],int Tokencount){
    Token DataBase = Tokens[0];
    ExecuteCreateDataBase(DataBase,Tokencount);
}
void parseSelectAllStatement(Token Tokens[],int Tokencount){
    Token SelectStatement[10];
    int j=0;
    if(Tokens[1].Type == ALL){
        for(int i=2;i<Tokencount;i++){
            SelectStatement[j++] = Tokens[i]; 
        }
        ExecuteSelectAllStatement(SelectStatement,j--);
    }
}
void parseSelectIdentifierStatement(Token Tokens[],int Tokencount){
    string Table = currentDatabasePath + "/" + Tokens[Tokencount-1].Value + ".txt";
    string column = Tokens[1].Value;
    ExecuteSelectIdentifierStatement(Table,column);
}
void parseSelectIdentifierWithConditionStatement(Token Tokens[],int Tokencount){
    string Table = currentDatabasePath + "/" + Tokens[3].Value + ".txt";
    string FirstColumn = Tokens[1].Value;
    string SecondColumn = Tokens[Tokencount-3].Value;
    string condition = Tokens[Tokencount-1].Value;
    ExecuteSelectIdentifierWithConditionStatement(Table,FirstColumn,SecondColumn,condition);
}
void parseUpdateStatement(Token Tokens[],int Tokencount){
    string Table = currentDatabasePath + "/" + Tokens[1].Value + ".txt";
    string FirstColumn = Tokens[3].Value;
    string SecondColumn = Tokens[Tokencount-3].Value;
    string condition = Tokens[Tokencount-1].Value;
    string SetName = Tokens[5].Value;
   ExecuteUpdateStatement(Table,FirstColumn,SecondColumn,condition,SetName);
}
void parseDeleteStatement(Token Tokens[],int Tokencount){
    string Table = currentDatabasePath + "/" + Tokens[2].Value + ".txt";
    string column = Tokens[4].Value;
    string condition = Tokens[6].Value;
    ExecuteDeleteStatement(Table,column,condition);
}
void Parser(Token Tokens[],int *Tokencount){
    for(int i=0;i<*Tokencount;i++){
        if(Tokens[i].Type == CREATE){
            Token TokenSlicing[50];
            int k=i+2;
            int j=0;
            while(j<*Tokencount){
                TokenSlicing[j++] = Tokens[k++];
            }
            if(Tokens[1].Type == TABLE){
                parseCreateTable(TokenSlicing,j);
            }
            else if(Tokens[1].Type == DATABASE){
                parseCreateDatabase(TokenSlicing,j);
            }    
        }
        else if(Tokens[i].Type == USE){
            Token Database = Tokens[1];
            parseUseDatabase(Database);
        }
        else if(Tokens[i].Type == INSERT){
            int j=0;
            int k=i;
            Token Insert[100];
            while(k<*Tokencount){
                Insert[j++] = Tokens[k++];
            }
            parseInsertInto(Insert,j--);
        }
        else if(Tokens[i].Type == SELECT){
            int j=0;
            int k=i;
            int foundwhere = 0;
            for(int i=0;i<*Tokencount;i++){
                if(Tokens[i].Type == WHERE){
                    foundwhere = 1;
                    break;
                }
            }
            Token SelectStatement[10];
            if(Tokens[i+1].Type == ALL){
                while(k<*Tokencount){
                    SelectStatement[j++] = Tokens[k++];
                }
                parseSelectAllStatement(SelectStatement,j--);
            }
            else if(Tokens[i+1].Type == IDENTIFIER && foundwhere !=1){
                while(k<*Tokencount){
                    SelectStatement[j++] = Tokens[k++];
                }
                parseSelectIdentifierStatement(SelectStatement,j--);
            }
            else{
                while(k<*Tokencount){
                    SelectStatement[j++] = Tokens[k++];
                }
                parseSelectIdentifierWithConditionStatement(Tokens,j--);
            }
        }
        else if(Tokens[i].Type == UPDATE){
            int j=0;
            int k=i;
            Token UpdateStatement[100];
            while(k<*Tokencount){
                UpdateStatement[j++] = Tokens[k++];
            }
            parseUpdateStatement(UpdateStatement,j--);
        }
        else if(Tokens[i].Type == DELETE){
            int j=0;
            int k=i;
            Token DeleteStatement[100];
            while(k<*Tokencount){
                DeleteStatement[j++] = Tokens[k++];
            }
            parseDeleteStatement(DeleteStatement,j--);
        }
    }
}