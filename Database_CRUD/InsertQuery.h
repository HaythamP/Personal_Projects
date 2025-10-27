#ifndef INSERTQUERY_H
#define INSERTQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"


class InsertQuery:public Query{
    private:
    std::string* params;
    int numParams;
    public:
    InsertQuery(std::string query);
    InsertQuery(std::string* params,int numParams);
    virtual ~InsertQuery();
    QueryResponse* operator()(Database& db);
    bool operator!=(const Database& db) const;
    virtual operator std::string() const;

};

#endif 
/* INSERTQUERY_H */
