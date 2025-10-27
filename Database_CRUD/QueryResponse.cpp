#include "QueryResponse.h"
#include "Query.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

QueryResponse::QueryResponse(std::string msg){
    message=msg;
}


std::ostream& operator<<(std::ostream& out,const QueryResponse& q){
    out<<q.message;
    return out;
}
