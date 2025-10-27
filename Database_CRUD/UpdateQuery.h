#ifndef UPDATEQUERY_H
#define UPDATEQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"


class UpdateQuery:public Query{
    private:
    std::string column;
    std::string value;
    std::string oldvalue;
    public:
    UpdateQuery(std::string query);
    virtual ~UpdateQuery();
    QueryResponse* operator()(Database& db);
    bool operator!=(const Database& db) const;
    virtual operator std::string() const;
};

#endif /* UPDATEQUERY_H */
