#include "InsertQuery.h"
#include <sstream>
#include <iostream>

 InsertQuery::InsertQuery(std::string query){
    int count=1;
    int i=0;
    while(query[i]!='\0'){
        if(query[i]==','){
            count++;
        }
        i++;
    }
    numParams=count;
    
    params=new std::string[numParams];
    std::stringstream ss(query);

    std::string temp;
    int j=0;
    while(std::getline(ss,temp,',')){
        params[j++]=temp;
    }

    
 }
    InsertQuery::InsertQuery(std::string* params,int numParams){
         if (params == NULL || numParams <= 0) {
        this->numParams = 0;
        this->params = new std::string[0];  
        return;
    }

        this->numParams=numParams;
        this->params=new std::string[this->numParams];
        for (int i = 0;  i < this->numParams;  i++)
        {
            this->params[i]=params[i];
        }
    
    }
    InsertQuery::~InsertQuery(){
        if(params!=NULL){
            delete[] params;
            params=NULL;
        }
        
    }
    QueryResponse* InsertQuery::operator()(Database& db){
           if (*this!=db) {
            return NULL;  
    }

    for (int i = 0; i < numParams; i++) {
        std::string param = params[i];
        std::string columnName = "";
        std::string value = "";
        int j = 0;
        while (param[j]!=':'&& param[j]!='\0') {
            columnName+=param[j];
            j++;
        }
        if (param[j]==':') {
            j++; 
        }

        while (param[j]!='\0') {
            value+=param[j];
            j++;
        }

        Column* col=getColumn(db,columnName);
        if (col==NULL) {
            return NULL;
        }
        *col+=value;
    }
    return new QueryResponse("Row successfully inserted");        
    }
    bool InsertQuery::operator!=(const Database& db) const{
        if(numParams!=getNumberOfColumns(db))return true;

        for (int i = 0; i < numParams; i++)
        {
            std::string param=params[i];
            std::string colName="";
            int j=0;

            while(param[j]!=':'&&param[j]!='\0'){
                colName+=param[j];
                j++;
            }
            if(getColumn(const_cast<Database&>(db),colName)==NULL){
                return true;
            }
        }
        return false;
        

    }
    InsertQuery::operator std::string() const{
        std::string out="INSERT INTO DATABASE (";
        for (int i = 0; i < numParams; i++)
        {
            out+=params[i];
            if(i!=numParams-1){
                out+=",";
            }
        }

        out+=")";
            return out;
    }