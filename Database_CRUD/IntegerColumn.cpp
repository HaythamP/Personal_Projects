#include "IntegerColumn.h"
#include "IntegerElement.h"
#include <string>

IntegerColumn::IntegerColumn(std::string columnName,int columnSize):Column(columnName,columnSize){
    array=new IntegerElement*[columnSize];

    for(int i=0;i<this->columnSize;i++){
        array[i]=NULL;
    }
}
    IntegerColumn::~IntegerColumn(){
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
    IntegerColumn* IntegerColumn::clone() const{
        
        IntegerColumn* temp=new IntegerColumn(this->columnName,this->columnSize);

        for (int i = 0; i < columnSize; i++)
        {
           if(this->array[i]!=NULL){
            temp->array[i]=new IntegerElement(std::string(*this->array[i]));

           }else{
            temp->array[i]=NULL;
           }
        }
        return temp;
        

    }
    IntegerColumn& IntegerColumn::operator+=(std::string data){
     IntegerElement* newE=new IntegerElement(data);
    IntegerElement** temp=new IntegerElement*[columnSize+1];

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
   IntegerColumn& IntegerColumn::operator-=(std::string data)
{
    for(int i=0;i<columnSize;i++){
        if(*array[i]==data){
            *this-=i;
            break;
        }
    }
    return *this;
}

IntegerColumn& IntegerColumn::operator-=(int index)
{
    if(index<0||index>=columnSize)return *this;


    delete array[index];

    IntegerElement** temp=new IntegerElement*[columnSize-1];
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

int IntegerColumn::operator()(std::string data) const
{
    for (int i = 0; i < columnSize; i++)
    {
        if(*array[i]==data){
            return i;
        }
    }
    
    return -1;
}

IntegerColumn& IntegerColumn::operator()(std::string value, std::string newValue)
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

IntegerElement const* IntegerColumn::operator[](int pos) const
{
    if (pos < 0 || pos >= columnSize){
        return NULL;
    }

    return array[pos];
}

IntegerElement const* IntegerColumn::operator[](std::string value) const
{
    for (int i = 0; i < columnSize; i++){
        if (array[i] && (*array[i] == value))
            return array[i];
    }
    return NULL;
}

bool IntegerColumn::operator!() const
{
    if(array==NULL)return false;

    if(columnSize<0)return false;

    for (int i = 0; i < columnSize; i++)
    {
        if(array[i]==NULL)return false;
    }
    
    return true;
}
    