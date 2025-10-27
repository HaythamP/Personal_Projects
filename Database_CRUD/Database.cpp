#include "Database.h"
#include "Column.h"
#include "Column.h"
#include <sstream>
#include <fstream>
//function 1
Database::Database(){
this->numColumns=-1;
this->databaseName="Database";
this->columns=NULL;
}
//function 2
Database& Database::operator<<(std::string line){
        if (columns==NULL||numColumns<=0)
        return *this;

        std::stringstream ss(line);
        std::string val;
        int i=0;

        while(i<numColumns && std::getline(ss,val,',')){
            if(columns[i]!=NULL){
                (*columns[i])+=val;
            }
            ++i;
        }
return *this;

}
//function 3
 Database::~Database(){
    if(columns!=NULL){
        for (int i = 0; i < numColumns; i++)
        {
            delete columns[i];
            columns[i]=NULL;
        }
        delete[] columns;
        columns=NULL;
        
    }
    numColumns=0;
 }
//function 4
Database::Database(const Database& other){

    this->numColumns=other.numColumns;
    this->databaseName=other.databaseName;

    if(numColumns>0&&other.columns!=NULL){
        this->columns=new Column*[numColumns];
        for (int i = 0; i < numColumns; i++)
        {
            if(other.columns[i]!=NULL){
                columns[i]=other.columns[i]->clone();
            }else{
                columns[i]=NULL;
            }
        }
        
    }else{
        columns=NULL;
    }

    }
//function 5
Database* Database::buildFromSchema(std::string schema, std::string name) {
    Database* db = new Database();
    db->databaseName = name;

    if (schema == "") {
        db->numColumns = 0;
        db->columns = NULL;
        return db;
    }
    int numCols=1;
    int i=0;
    while (schema[i] !='\0') {
        if (schema[i]==',') numCols++;
        i++;
    }

    db->numColumns = numCols;
    db->columns = new Column*[numCols];

    
    i = 0;
    int colIndex = 0;
    while (schema[i] != '\0' && colIndex < numCols) {
        std::string p = "";
        while (schema[i] != ',' && schema[i] != '\0') {
            p += schema[i];
            i++;
        }
        if (schema[i] == ',') i++;
        db->columns[colIndex] = Column::createColumnFromSchema(p);
        colIndex++;
    }

    return db;
}
//function 6
Database* Database::buildFromFile(std::string schema,std::string fileName, char deliminator,std::string name){
    Database* db=buildFromSchema(schema,name);

    if(db->numColumns==0) return db;
    std::ifstream in(fileName.c_str());
    if(!in) return db;
     std::string line;
    while(getline(in,line)){
        int i=0;
        int colIndex=0;
        std::string p="";
        while(line[i]!='\0'&&colIndex<db->numColumns){
            p="";
            while(line[i]!=deliminator&&line[i]!='\0'){
                p+=line[i];
                i++;
            }
            if(line[i]==deliminator) i++;
            db->columns[colIndex]->operator+=(p);
            colIndex++;
        }
    }

    in.close();
    return db;


     }
//function 7
QueryResponse* Database::processQuery(Query* query){
if(query==NULL)return NULL;

if(*query!=*this)return NULL;

return (*query)(*this);
    }
//function 8
Database& Database::operator=(const Database& other){
    if(this==&other)return *this;

     if (columns != NULL) {
        for (int i = 0; i < numColumns; i++) {
            delete columns[i];
        }
        delete[] columns;
    }
    databaseName=other.databaseName;
    numColumns=other.numColumns;
    if (numColumns>0) {
        columns =new Column*[numColumns];
        for (int i=0; i < numColumns; i++) {
            columns[i]=other.columns[i]->clone(); 
        }
    }else{
        columns=NULL;
    }
    return *this;
    }
//function 9
Database& Database::operator+=(const Column* col){
    if(col==NULL)return *this;

    for (int i = 0; i < numColumns; i++)
    {
        if(*columns[i]==*col){
            return *this;
        }
    }

    Column** newCol=new Column*[numColumns+1];

    for (int i = 0; i < numColumns; i++)
    {
        newCol[i]=columns[i];
    }
    newCol[numColumns]=col->clone();

    if(columns!=NULL){
        delete[] columns;
    }
    columns=newCol;
    numColumns++;
    return *this;
    
    }
//function 10
Database Database::operator+(const Column* col) const{
Database c(*this);
c+=col;
return c;
    }
//function 11
Database& Database::operator-=(const Column* col){
    if(col == NULL) return *this;
    int index = -1;
    for(int i=0; i<numColumns; i++) {
        if(columns[i]!=NULL && *columns[i]==*col) {
            index = i;
            break;
        }
    }

    if(index==-1)return *this;

    delete columns[index];

    for(int j=index; j<numColumns-1; j++) {
        columns[j] = columns[j+1];
    }
    columns[numColumns-1] = NULL;
    numColumns--;

    if(numColumns > 0) {
        Column** temp = new Column*[numColumns];
        for(int k=0; k<numColumns; k++) {
        temp[k]=columns[k];
        }
        delete[] columns;
        columns=temp;
    } else {
        delete[] columns;
        columns=NULL;
    }
    return *this;

    }
//function 12
Database Database::operator-(const Column* col) const{
    Database c(*this);
    c-=col;
    return c;
    }
//function 13
Database& Database::operator+=(std::string line){
    int i=0;
    while(line[i]!='\0'){
        std::string p="";
        while(line[i]!=',' && line[i]!='\0'){
            p+=line[i];
            i++;
        }
        if(line[i]==',') i++;
        int j=0;
        std::string colName="";
        std::string value="";
        while(p[j]!=':' && p[j]!='\0'){
            colName+=p[j];
            j++;
        }
        if(p[j]==':') j++;
        while(p[j]!='\0'){
            value+=p[j];
            j++;
        }

        for(int k=0;k<numColumns;k++){
            if(columns[k]->operator std::string()==colName){
                columns[k]->operator()(value); 
                break; 
            }
        }
    }
    return *this;
    }
//function 14
Database Database::operator+(std::string line)const{
    Database c=*this;
    c+=line;
    return c;
    }

//function 15
const Column* Database::operator[](int column) const{
    if(column<0 ||column>=numColumns||columns==NULL)return NULL;

    return columns[column];
    }
//function 16
const Column* Database::operator[](std::string column)  const{
if(columns == NULL || numColumns <= 0) return NULL;

for (int i = 0; i < numColumns; i++)
{
    if(std::string(*columns[i])==column){
        return columns[i];
    }
}
return NULL;
   }

//function 17
Column* Database::operator[](int column){
if(columns==NULL || column<0 ||column>=numColumns) return NULL;

    return columns[column];
}

    

//function 18
Column* Database::operator[](std::string column){
    if(columns == NULL || numColumns <= 0) return NULL;

    for (int i = 0; i < numColumns; i++)
    {
    if(std::string(*columns[i])==column){
        return columns[i];
    }
    }
    return NULL;
}
//function 19
const bool Database::operator[](const Column& column) const{
    if (columns==NULL || numColumns<=0) return false;

    for (int i = 0; i < numColumns; i++)
    {
        if(std::string(*columns[i])==std::string(column)){
            return true;
        }
    }
    return false;
    
    }
 
//function    20
bool Database::operator!() const{
    if(numColumns<0||columns==NULL){
        return true;
    }

    for (int i = 0; i < numColumns; i++)
    {
        if(columns[i]==NULL){
            return true;
        }
    }
   
    int size=-1;
    for (int i = 0; i < numColumns; i++)
    {
        Column* col=columns[i];

        if(!(*col)==false){
            return true;
        }

        if(i==0){
            size=col->operator int();
        }else if(col->operator int()!=size){
            return true;
        }
    }
    
return false;
    }

//function 21
bool Database::operator==(const Database& other) const{
    if (columns == NULL && other.columns == NULL)
        return true;

    if ((columns==NULL &&other.columns!=NULL) ||(columns!=NULL &&other.columns==NULL))
        return false;

    if(numColumns!=other.numColumns){
        return false;
    }

    for (int i = 0; i < numColumns; i++)
    {
        if(columns[i]==NULL||other.columns[i]==NULL){
            return false;
        }

        if (!(*columns[i] == *other.columns[i]))
            return false;
    }
    return true;

    }

    

//function 22
bool Database::operator!=(const Query& q) const{
    return q!=*this;
    }
//function 23
std::ostream& operator<<(std::ostream& out, const Database& db){
    if(!db){
        out<<"Invalid Database";
        return out;
    }

    for (int i = 0; i < db.numColumns; i++)
    {
        out<<std::string(*db.columns[i])<<",";
    }
    out<<std::endl;

    int numR=db.columns[0]->operator int();
    for (int row= 0; row <numR; row++)
    {
        for(int col=0;col<db.numColumns;col++){
            out<<db.columns[col]->operator[](row)<<",";
        }
        out<<std::endl;
    }
    return out;
     }
//function 24
std::ofstream& operator<<(std::ofstream& ofs, const Database& db){
    if(!db){
        ofs<<"Invalid Database";
        return ofs;
    }
        ofs<<"|";

        for (int i = 0; i < db.numColumns; i++)
        {
            ofs<<std::string(*db.columns[i])<<"|";
        }
        ofs<<std::endl;

        ofs<<"|";
        for (int i = 0; i < db.numColumns; i++)
        {
            ofs<<"-|";
        }
        ofs<<std::endl;

        int numR=db.columns[0]->operator int();
        for (int r = 0; r <numR; r++)
        {
            ofs<<"|";
            for (int col = 0; col <db.numColumns; col++)
            {
                ofs<<db.columns[col]->operator[](r)<<"|";
            }
            ofs<<std::endl;
            
        }
        return ofs;
     }

//function 25
std::ifstream& operator>>(std::ifstream& ifs, Database& db){
    std::string line;
    while(std::getline(ifs,line)){
        db+=line;
    }
    return ifs;
     }
