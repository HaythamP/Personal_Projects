#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Column.h"
#include "Query.h"
#include "QueryResponse.h"

class Database
{
private:
    int numColumns;
    std::string databaseName;
    Column** columns;
    Database();
    Database& operator<<(std::string);

public:
    friend class Query;

    ~Database();
    Database(const Database& other);
    static Database* buildFromSchema(std::string schema, std::string name = "Database");
    static Database* buildFromFile(std::string schema, std::string fileName, char delimiter = ',', std::string name = "Database");
    QueryResponse* processQuery(Query* query);
    Database& operator=(const Database& other);
    Database& operator+=(const Column*);
    Database operator+(const Column*) const;
    Database& operator-=(const Column*);
    Database operator-(const Column*) const;
    Database& operator+=(std::string line);
    Database operator+(std::string line) const;
    const Column* operator[](int column) const;
    const Column* operator[](std::string column) const;
    Column* operator[](int column);
    Column* operator[](std::string column);
    const bool operator[](const Column& column) const;
    bool operator!() const;
    bool operator==(const Database&) const;
    bool operator!=(const Query&) const;
    friend std::ostream& operator<<(std::ostream&, const Database&);
    friend std::ofstream& operator<<(std::ofstream&, const Database&);
    friend std::ifstream& operator>>(std::ifstream&, Database&);
};

#endif /* DATABASE_H */
