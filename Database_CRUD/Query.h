#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Column.h"
#include "Element.h"

class Database;

class Query{
    protected:
    Column* getColumn(Database& db,std::string column) const;
    Column**& getColumns(Database&) const;
    int getNumberOfColumns(const Database&) const;
    std::string getDatabase(const Database&) const;
    public:
    virtual ~Query();
    virtual QueryResponse* operator()(Database& db)=0;
    virtual bool operator!=(const Database& db) const=0;
    virtual operator std::string()const =0;
    friend std::ostream& operator<<(std::ostream& out, const Query& q);
    
};





#include "Database.h"

#endif /* QUERY_H */
