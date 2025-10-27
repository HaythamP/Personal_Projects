#include "Query.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Column.h"
#include "Element.h"


Column* Query::getColumn(Database& db,std::string column) const{
        Column** columns=getColumns(db);
        int n=getNumberOfColumns(db);

        for (int i = 0; i < n; i++)
        {
           if(columns[i]&&std::string(*columns[i])==column){
            return columns[i];
           }
        }
        return NULL;
        
}
    Column**& Query::getColumns(Database& db) const{
        return db.columns;
    }
    int Query::getNumberOfColumns(const Database& db)const{
        return db.numColumns;
    }
    std::string Query::getDatabase(const Database& db)const{
        return db.databaseName;
    }
    
    Query::~Query(){}
    std::ostream& operator<<(std::ostream& out, const Query& q){
        out<<std::string(q)<<std::endl;
        return out;
    }