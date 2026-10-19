#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<filesystem>
#include<iomanip>
#include "Lexer.h"
#include "Parser.h"
#include "ColumnIndex.h"
using namespace std;
namespace fs = std::filesystem;

void ExecuteDeleteStatement(string Table,string Column,string Condition){
    int Column_Index = ColumnIndex(Table,Column);
    string line;
    string ColumnValue;
    string value;
    string temp = Table + ".tmp";
    ofstream tempfile(temp);
    ifstream file(Table);
    while(getline(file,line)){
        int i=0;
        istringstream rows(line);
        while(rows >> value){
            if(value == "|") continue;
            else if(i == Column_Index){
                ColumnValue = value;
            }
            i++;
        }
        if(ColumnValue == Condition){
            continue;
        }
        else {
            tempfile << line << "\n";
        }
    }
    file.close();
    tempfile.close();
    string TableName = Table;
    string backup = Table + ".bak";
    fs::rename(Table,backup);
    fs::rename(temp,TableName);
    fs::remove(backup);
}
void ExecuteUpdateStatement(string Table , string FirstColumn , string SecondColumn , string Condition , string Setter){
    int FirstColumnIndex = ColumnIndex(Table,FirstColumn);
    int SecondColumnIndex = ColumnIndex(Table,SecondColumn);
    string line = " ";
    string value;
    string Column1 = " ";
    string Columns[100];
    int NumberOfColumns = 0;
    string Column2 = " "; 
    string newline;
    ifstream file(Table);
    string tempfile = Table + ".tmp";
    ofstream temp(tempfile);
    while(getline(file,line)){
        newline = " ";
        int i=0;
        int j=0;
        istringstream rows(line);
        while(rows >> value){
            if(value == "|") continue;
            else if(i == FirstColumnIndex){
                Column1 = value;
            }
            else if(i == SecondColumnIndex){
                Column2 = value;
            }
            i++;
        }
        if(Column2 == " "){
            if(Column1 == Condition){
                for(int i=0;i<line.length();i++){
                    char temp[100];
                    int j=0;
                    if(line[i] == '|') continue;
                    else if(isspace(line[i])) continue;
                    else if(isalpha(line[i])){
                        while(isalpha(line[i])){
                            temp[j++] = line[i++];
                        }
                    }
                    else if(isdigit(line[i])){
                        while(isdigit(line[i])){
                            temp[j++] = line[i++];
                        }
                    }
                    temp[j] = '\0';
                    Columns[NumberOfColumns++] = temp;
                }
            }
            if(Columns[SecondColumnIndex] == Condition){
                Columns[FirstColumnIndex] = Setter;
            }
            for(int t=0;t<NumberOfColumns;t++){
                newline += Columns[t] + "    |   " ;
            }
        }
        else{
            if(Column2 == Condition){
                for(int i=0;i<line.length();i++){
                    char temp[100];
                    int j=0;
                    if(line[i] == '|') continue;
                    else if(isspace(line[i])) continue;
                    else if(isalpha(line[i])){
                        while(isalpha(line[i])){
                            temp[j++] = line[i++];
                        }
                    }
                    else if(isdigit(line[i])){
                        while(isdigit(line[i])){
                            temp[j++] = line[i++];
                        }
                    }
                    temp[j] = '\0';
                    Columns[NumberOfColumns++] = temp;
                }
            }
            if(Columns[SecondColumnIndex] == Condition){
                Columns[FirstColumnIndex] = Setter;
            }
            for(int t=0;t<NumberOfColumns;t++){
                newline += Columns[t] + "    |   " ;
            }
        }
        j++;
    }
    file.clear();
    file.seekg(0,ios::beg);
    while(getline(file,line)){
        int FoundChange = 0;
        istringstream temprows(line);
        while(temprows >> value){
            if(value == Condition){
                FoundChange = 1;
                break;
            }
        }
        if(FoundChange == 1){
            temp << newline << "\n";
        }
        else {
            temp << line << "\n";
        }
    }       
    file.close();
    temp.close();
    string TableName = Table;
    string backup = Table + ".bak";
   try{
        fs::rename(Table,backup);
        fs::rename(tempfile,TableName); 
        fs::remove(backup);
   }
   catch(const fs::filesystem_error& err){
    cout << "Second file renaming File error : " << err.what() << "\n";
   }
}
void ExecuteSelectIdentifierWithConditionStatement(string Table,string FirstColumn,string SecondColumn,string Condition){
    int FirstColumnIndex = ColumnIndex(Table,FirstColumn);
    int SecondColumnIndex = ColumnIndex(Table,SecondColumn);
    ifstream file(Table);
    string value;
    string Column1;
    string Column2;
    string line;
    cout << "+---------+" << "\n";
    cout << "|";
    cout << FirstColumn << "\n";
    while(getline(file,line)){
        istringstream rows(line);
        int j=0;
        int i=0;
        while(rows >> value){
            if(value == "|") continue;
            else if(i == FirstColumnIndex){
                Column1 = value;
            }
            else if(i == SecondColumnIndex){
                Column2 = value;
            }
            i++;
        }

        if(Column2 == Condition){
                cout << "+---------+" << "\n";
                cout << "|";
                cout << left << setw(6) << Column1 << "\n";
        }
        j++;
    }
    cout << "+---------+" << "\n";
}
void ExecuteSelectIdentifierStatement(string Table , string Column){
    int SelectedIndex = ColumnIndex(Table , Column);
    ifstream file(Table);
    string line;
    string value;
    cout << "+---------+" << "\n";
    while(getline(file,line)){
        istringstream rows(line);
        int j=0;
        cout << "|";
        while(rows >> value){
            if(value == "|") continue;
            else if(j == SelectedIndex){
                cout << left << setw(6) << value << "\n";
                break;
            }
        j++;
        }
    cout << "+---------+" << "\n";
    }
    
}
void ExecuteSelectAllStatement(Token Tokens[],int Tokencount){
    cout << currentDatabasePath << "\n";
    string line;
    string id;
    string name;
    string salary;
    string Table = currentDatabasePath + "/" + Tokens[1].Value + ".txt";
    ifstream file(Table);
    string value;
        // Top border
        cout << "+------+----------------+---------------------+" << "\n";
    while (getline(file,line)){
        istringstream iss(line);
        cout << "|";
        while(iss >> id >> name >> salary){
                cout 
                    << left << setw(6) << id
                    << left << setw(9) << name
                    << right << setw(8) << salary;
                    
        }
        cout << "\n";
        cout << "+------+----------------+---------------------+" << "\n";
    }
}
void ExecuteInsertInto(Token Tokens[],int Tokencount){
    cout << currentDatabasePath <<"\n";
    string path = currentDatabasePath + "/" + Tokens[0].Value + ".txt";
    cout << path << "\n";
    if(fs::exists(path)){ 
        ofstream file(path,ios::app);
        for(int i=1;i<Tokencount;i++){
            if(Tokens[i].Type == NUMBER || Tokens[i].Type == IDENTIFIER){
                file <<  Tokens[i].Value ;
            file << "    |   ";
            }
        }
        file << "\n";
    }
    else {
        cout << "Table doesn't exists";
    }
}
void ExecuteCreateTable(Token TableName,Token Columns[],int TotalColumns){
    cout << currentDatabasePath << "\n";
    string Table = currentDatabasePath + "/" + TableName.Value + ".txt";
    ofstream file(Table);
    for(int i=0;i<TotalColumns;i++){
        if(Columns[i].Type == IDENTIFIER){
                file << Columns[i].Value ;
        file << "   |   ";
        }
    }
    file << "\n";
}
void ExecuteUseDatabase(Token t){
    currentDatabasePath = root + "/" + t.Value;
    cout << "In " + t.Value;
}
void ExecuteCreateDataBase(Token Token,int Tokencount){
    string Database = root + "/" + Token.Value;
    fs::create_directory(root);
    currentDatabasePath = Database;
    fs::create_directory(Database);
}