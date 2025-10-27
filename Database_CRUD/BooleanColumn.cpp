#include "BooleanColumn.h"
#include "BooleanElement.h"
#include <string>

BooleanColumn::BooleanColumn(std::string columnName,int columnSize):Column(columnName,columnSize){
    array=new BooleanElement*[columnSize];

    for(int i=0;i<this->columnSize;i++){
        array[i]=NULL;
    }
}
    BooleanColumn::~BooleanColumn(){
        if(array!=NULL){
            for (int i = 0; i < this->columnSize; i++)
            {
                if(array[i]!=NULL){
                    delete array[i];
                    array[i]=NULL;
                }
            }
            delete[] array;
            array=NULL;
            
        }
    }
    BooleanColumn* BooleanColumn::clone() const{
        
        BooleanColumn* temp=new BooleanColumn(this->columnName,this->columnSize);

        for (int i = 0; i < columnSize; i++)
        {
           if(this->array[i]!=NULL){
            temp->array[i]=new BooleanElement(std::string(*this->array[i]));

           }else{
            temp->array[i]=NULL;
           }
        }
        return temp;
        

    }
    BooleanColumn& BooleanColumn::operator+=(std::string data){
     BooleanElement* newE=new BooleanElement(data);
    BooleanElement** temp=new BooleanElement*[columnSize+1];

    for (int i = 0; i < columnSize; i++)
    {
        temp[i]=array[i];
    }
    temp[columnSize]=newE;
    delete[] array;
    array=temp;
    columnSize++;
    
    return *this;

    }
   BooleanColumn& BooleanColumn::operator-=(std::string data)
{
    for(int i=0;i<columnSize;i++){
        if(*array[i]==data){
            *this-=i;
            break;
        }
    }
    return *this;
}

BooleanColumn& BooleanColumn::operator-=(int index)
{
    if(index<0||index>=columnSize)return *this;


    delete array[index];

    BooleanElement** temp=new BooleanElement*[columnSize-1];
    for (int i = 0, j = 0; i < columnSize; i++) {
        if (i != index) {
            temp[j++] = array[i];
        }
    }
    delete[] array;
    array=temp;
    columnSize--;

    return *this;
}

int BooleanColumn::operator()(std::string data) const
{
    for (int i = 0; i < columnSize; i++)
    {
        if(*array[i]==data){
            return i;
        }
    }
    
    return -1;
}

BooleanColumn& BooleanColumn::operator()(std::string value, std::string newValue)
{
    for (int i = 0; i < columnSize; i++)
    {
        if(*array[i]==value){
            (*array[i])(newValue);
            break;
        }
    }
    return *this;
}

BooleanElement const* BooleanColumn::operator[](int pos) const
{
    if (pos < 0 || pos >= columnSize){
        return NULL;
    }

    return array[pos];
}

BooleanElement const* BooleanColumn::operator[](std::string value) const
{
    for (int i = 0; i < columnSize; i++){
        if (array[i] && (*array[i] == value))
            return array[i];
    }
    return NULL;
}

bool BooleanColumn::operator!() const
{
    if(array==NULL)return false;

    if(columnSize<0)return false;

    for (int i = 0; i < columnSize; i++)
    {
        if(array[i]==NULL)return false;
    }
    
    return true;
}
    