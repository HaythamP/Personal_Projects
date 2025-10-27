#ifndef QUERYRESPONSE_H
#define QUERYRESPONSE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class QueryResponse{
    private:
    std::string message;
    public:
    QueryResponse(std::string);
    friend std::ostream& operator<<(std::ostream&, const QueryResponse&);
};




#endif /* QUERYRESPONSE_H */
