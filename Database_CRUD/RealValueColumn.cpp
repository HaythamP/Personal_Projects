#include "RealValueColumn.h"
#include "RealElement.h"
#include <string>

RealValueColumn::RealValueColumn(std::string columnName,int columnSize):Column(columnName,columnSize){
    array=new RealElement*[columnSize];

    for(int i=0;i<this->columnSize;i++){
        array[i]=NULL;
    }
}
    RealValueColumn::~RealValueColumn(){
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
    RealValueColumn* RealValueColumn::clone() const{
        
        RealValueColumn* temp=new RealValueColumn(this->columnName,this->columnSize);

        for (int i = 0; i < columnSize; i++)
        {
           if(this->array[i]!=NULL){
            temp->array[i]=new RealElement(std::string(*this->array[i]));

           }else{
            temp->array[i]=NULL;
           }
        }
        return temp;
        

    }
    RealValueColumn& RealValueColumn::operator+=(std::string data){
     RealElement* newE=new RealElement(data);
    RealElement** temp=new RealElement*[columnSize+1];

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
   RealValueColumn& RealValueColumn::operator-=(std::string data)
{
    for(int i=0;i<columnSize;i++){
        if(*array[i]==data){
            *this-=i;
            break;
        }
    }
    return *this;
}

RealValueColumn& RealValueColumn::operator-=(int index)
{
    if(index<0||index>=columnSize)return *this;


    delete array[index];

    RealElement** temp=new RealElement*[columnSize-1];
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

int RealValueColumn::operator()(std::string data) const
{
    for (int i = 0; i < columnSize; i++)
    {
        if(*array[i]==data){
            return i;
        }
    }
    
    return -1;
}

RealValueColumn& RealValueColumn::operator()(std::string value, std::string newValue)
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

RealElement const* RealValueColumn::operator[](int pos) const
{
    if (pos < 0 || pos >= columnSize){
        return NULL;
    }

    return array[pos];
}

RealElement const* RealValueColumn::operator[](std::string value) const
{
    for (int i = 0; i < columnSize; i++){
        if (array[i] && (*array[i] == value))
            return array[i];
    }
    return NULL;
}

bool RealValueColumn::operator!() const
{
    if(array==NULL)return false;

    if(columnSize<0)return false;

    for (int i = 0; i < columnSize; i++)
    {
        if(array[i]==NULL)return false;
    }
    
    return true;
}
    