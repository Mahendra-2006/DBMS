# Database Management System
This is a mini database management system built in C++ to demonstrate the basic components of a DBMS.

# Architecture
The project consists of three main components :
    - Lexer : Converts query text into tokens.
    - Parser : Processes tokens and identifies SQL statements.
    - Executor : Execute supported database operations.

# Features
- Lexer
- Parser
- Executor
- File-based storage
- Creates a database
- Creates a table
- Inserts into a table
- Select all records using `SELECT *`
- Select statement of a particular column
- Select statement with a condition
- Filtered records using `WHERE`
- Formatted query output
- Update records
- Delete records
- Column selection and conditional queries
- Maintains global variables like `root` and `currentDatabasePath`
- Planned joins,transactions, AND `ALTER TABLE` 

# Future Plans
-` ALTER TABLE `
- Joins
- Transactions

# Project Structure
    includes/
        Lexer.h
        Parser.h
        Executor.h
        ColumnIndex.h
    src/
        Lexer.cpp
        Parser.cpp
        Executor.cpp
        ColumnIndex.cpp
    HelperFunction/
        ColumnIndex.cpp

# Syntax
        CREATE DATABASE `database_name`

        USE `database_name`
        
        CREATE TABLE `table_name(column_definitions)`
        
        INSERT INTO `table_name(...)`
        
        UPDATE `table_name` SET `column_value = new_value` WHERE `condition`
        
        DELETE FROM `table_name` WHERE `condition`
        
        SELECT * FROM `table_name`
        
        SELECT `column_value` FROM `table_name`
    
        SELECT `column_value` FROM `table_name` WHERE `condition`

# How to run
    Compile the project :
        ```bash
            g++ -std=c++17 -Iincludes src/*.cpp HelperFunction/ColumnIndex.cpp -o DBMS.exe
        ```
    Run the DBMS :
    ```bash
        ./DBMS.exe
    ```

# Note
This project is intended for learning how a basic database management system works. Supported SQL syntax depends on the current implementation.