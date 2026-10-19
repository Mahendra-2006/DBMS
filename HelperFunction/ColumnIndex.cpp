#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int ColumnIndex(string Table , string Column){
    string line;
    string value;
    ifstream file(Table);
    getline(file,line);
    istringstream row(line);
    int i=0;
        while(row >> value){
            if(value == "|") continue;
            else if(value == Column){
                break;
            }
           i++;
        }
    return i;
}