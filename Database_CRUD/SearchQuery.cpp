#include "SearchQuery.h"
#include "Database.h"
#include "Column.h"
#include "Element.h"
#include <string>
#include <sstream>

SearchQuery::SearchQuery(std::string query){
int pos=-1;
int i=0;

while(query[i]!='\0'){
    if(query[i]==':'){
        pos=i;
        break;
    }
    i++;
}

    if(pos!=-1){
        column=query.substr(0,pos);
        value=query.substr(pos+1);
    }

}
    SearchQuery::~SearchQuery(){}
    QueryResponse* SearchQuery::operator()(Database& db){
        if (*this != db) {
        return NULL; 
    }

    Column* col = getColumn(db, column);
    if (!col) return NULL;
    int row=(*col)(value);
    if(row!=-1){
        return new QueryResponse("No records found");
    }
    std::string out="";

    int numCol=getNumberOfColumns(db);
    Column** cols=getColumns(db);

    for (int i = 0; i < numCol; i++)
    {
        const Element* e=(*cols[i])[row];
        if(e){
                out+=std::string(*e);
        }
        if(i!=numCol-1){
            out+=",";
        }

    }
    return new QueryResponse(out);
    

    }
    bool SearchQuery::operator!=(const Database& db) const{
        Column* col = getColumn(const_cast<Database&>(db),column);
        return (col == NULL);
    }
    SearchQuery::operator std::string() const{
    std::string result = "SELECT FROM DATABASE WHERE ";
    result += column;
    result += " = ";
    result += value;
    return result;
    }