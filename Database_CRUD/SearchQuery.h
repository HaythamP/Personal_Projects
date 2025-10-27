#ifndef SEARCHQUERY_H
#define SEARCHQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"


class SearchQuery:public Query{
    private:
    std::string column;
    std::string value;
    public:
    SearchQuery(std::string query);
    virtual ~SearchQuery();
    QueryResponse* operator()(Database& db);
    bool operator!=(const Database& db) const;
    virtual operator std::string() const;

};

#endif /* SEARCHQUERY_H */
