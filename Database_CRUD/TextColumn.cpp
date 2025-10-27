#include "TextColumn.h"
#include "TextElement.h"
#include <string>

TextColumn::TextColumn(std::string columnName,int columnSize):Column(columnName,columnSize){
    array=new TextElement*[columnSize];

    for(int i=0;i<this->columnSize;i++){
        array[i]=NULL;
    }
}
    TextColumn::~TextColumn(){
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
    TextColumn* TextColumn::clone() const{
        
        TextColumn* temp=new TextColumn(this->columnName,this->columnSize);

        for (int i = 0; i < columnSize; i++)
        {
           if(this->array[i]!=NULL){
            temp->array[i]=new TextElement(std::string(*this->array[i]));

           }else{
            temp->array[i]=NULL;
           }
        }
        return temp;
        

    }
    TextColumn& TextColumn::operator+=(std::string data){
     TextElement* newE=new TextElement(data);
    TextElement** temp=new TextElement*[columnSize+1];

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
   TextColumn& TextColumn::operator-=(std::string data)
{
    for(int i=0;i<columnSize;i++){
        if(*array[i]==data){
            *this-=i;
            break;
        }
    }
    return *this;
}

TextColumn& TextColumn::operator-=(int index)
{
    if(index<0||index>=columnSize)return *this;


    delete array[index];

    TextElement** temp=new TextElement*[columnSize-1];
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

int TextColumn::operator()(std::string data) const
{
    for (int i = 0; i < columnSize; i++)
    {
        if(*array[i]==data){
            return i;
        }
    }
    
    return -1;
}

TextColumn& TextColumn::operator()(std::string value, std::string newValue)
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

TextElement const* TextColumn::operator[](int pos) const
{
    if (pos < 0 || pos >= columnSize){
        return NULL;
    }

    return array[pos];
}

TextElement const* TextColumn::operator[](std::string value) const
{
    for (int i = 0; i < columnSize; i++){
        if (array[i] && (*array[i] == value))
            return array[i];
    }
    return NULL;
}

bool TextColumn::operator!() const
{
    if(array==NULL)return false;

    if(columnSize<0)return false;

    for (int i = 0; i < columnSize; i++)
    {
        if(array[i]==NULL)return false;
    }
    
    return true;
}
    