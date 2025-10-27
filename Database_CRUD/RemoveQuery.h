#ifndef REMOVEQUERY_H
#define REMOVEQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"


class RemoveQuery:public Query{
    private:
    std::string column;
    std::string value;

    public:
    RemoveQuery(std::string query);
    virtual ~RemoveQuery();
    QueryResponse* operator()(Database& db);
    bool operator!=(const Database& db) const;
    virtual operator std::string() const;

};
#endif /* REMOVEQUERY_H */
