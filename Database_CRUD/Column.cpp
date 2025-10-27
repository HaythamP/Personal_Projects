#include "Column.h"
#include "BooleanColumn.h"
#include "CharacterColumn.h"
#include "IntegerColumn.h"
#include "RealValueColumn.h"
#include "TextColumn.h"
#include "TemplateFunctions.h"


Column::Column(std::string columnName,int columnSize){
    if(columnSize<0){
        this->columnSize=0;
    }else{
        this->columnSize=columnSize;
    }
    this->columnName=columnName;
    
}

Column* Column::createColumnFromSchema(std::string schema){
    std::string name,type;
    std::stringstream ss(schema);

    std::getline(ss,name,':');
    std::getline(ss,type);
    

    for(int i=0;i<(int)type.length();i++){
        if(type[i]>='A'&&type[i]<='Z'){
            type[i]=type[i]-'A'+'a';
        }
    }

        Column* temp=NULL;
    if(type=="bool"){
        temp=new BooleanColumn(name,0);
    }else if(type=="char"){
        temp=new CharacterColumn(name,0);
    }else if(type=="int"){
        temp=new IntegerColumn(name,0);
    }else if(type=="real"){
        temp=new RealValueColumn(name,0);
    }else{
        temp=new TextColumn(name,0);

    }
    return temp;
}
Column::operator int() const{
return columnSize;
}
Column::operator std::string() const{
    return columnName;
}
bool Column::operator==(const Column& other) const{
    if(this->columnName!=other.columnName || this->columnSize!=other.columnSize)
    return false;

    for(int i=0;i<columnSize;i++){
        const Element* e1=(*this)[i];
        const Element* e2=other[i];

        if(!e1||!e2||std::string(*e1)!=std::string(*e2)){
            return false;
        }
    }

return true;

}

bool Column::operator!=(const Column& other) const{
    return !(*this==other);
}
//7
Column::~Column(){}


