#include "RemoveQuery.h"
#include "Database.h"
#include "Column.h"
#include "Element.h"
#include <string>
#include <sstream>
RemoveQuery::RemoveQuery(std::string query){
    std::stringstream ss(query);
    std::getline(ss, column, ':'); 
    std::getline(ss, value); 
}
 RemoveQuery::~RemoveQuery(){
    }
QueryResponse* RemoveQuery::operator()(Database& db){
        if(*this!=db)return NULL;

        Column* col=getColumn(db,column);
        if(!col)return NULL;

        int index=(*col)(value);
        if(index==-1){
            return new QueryResponse("No rows were removed");
        }


        Column** columns=getColumns(db);
        int numCols=getNumberOfColumns(db);

        for (int i = 0; i < numCols; i++)
        {
            (*columns[i])-=index;
        }
        return new QueryResponse("Row successfully removed");
        
    }
bool RemoveQuery::operator!=(const Database& db) const{
        if(getColumn(const_cast<Database&>(db),column)==NULL){
            return true;
        }
        return false;
    }
RemoveQuery::operator std::string() const{
    std::string out="DELETE FROM DATABASE WHERE: ";
    out+=column+" = "+value;
    return out;
    }