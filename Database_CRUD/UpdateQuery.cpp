#include "UpdateQuery.h"
#include "Database.h"
#include "Column.h"
#include "Element.h"
#include <string>
#include <sstream>

UpdateQuery::UpdateQuery(std::string query){
    int i = 0;
    column = "";
    while(query[i]!=':' && query[i]!='\0') {
        column+=query[i];
        i++;
    }
    i++; 

    
    oldvalue="";
    while(query[i]!=';' && query[i]!='\0') {
        oldvalue+=query[i];
        i++;
    }
    i++; 

    
    value="";
    while(query[i]!='\0') {
        value+=query[i];
        i++;
    }

}
UpdateQuery::~UpdateQuery(){}
QueryResponse* UpdateQuery::operator()(Database& db){
    if (*this != db){ 
    return NULL;}

    Column* col = getColumn(db, column);
    if (!col) {
        return new QueryResponse("No row was updated");
    }
    int row = col->operator()(oldvalue);
    if (row == -1) {
        return new QueryResponse("No row was updated");

    }

    col->operator()(oldvalue, value);

    return new QueryResponse("Updated a row");
    }
bool UpdateQuery::operator!=(const Database& db) const{
    Column* col = getColumn(const_cast<Database&>(db),column);
    return !col;

    }
UpdateQuery::operator std::string() const{
    std::string result="UPDATE DATABASE SET ";
    result+=column+" = "+value;
    result+=" WHERE "+column+" = "+oldvalue;
    return result;
    }
