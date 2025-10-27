#include "CharacterColumn.h"
#include "CharacterElement.h"
#include <string>

CharacterColumn::CharacterColumn(std::string columnName,int columnSize):Column(columnName,columnSize){
    array=new CharacterElement*[columnSize];

    for(int i=0;i<this->columnSize;i++){
        array[i]=NULL;
    }
}
    CharacterColumn::~CharacterColumn(){
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
    CharacterColumn* CharacterColumn::clone() const{
        
        CharacterColumn* temp=new CharacterColumn(this->columnName,this->columnSize);

        for (int i = 0; i < columnSize; i++)
        {
           if(this->array[i]!=NULL){
            temp->array[i]=new CharacterElement(std::string(*this->array[i]));

           }else{
            temp->array[i]=NULL;
           }
        }
        return temp;
        

    }
    CharacterColumn& CharacterColumn::operator+=(std::string data){
     CharacterElement* newE=new CharacterElement(data);
    CharacterElement** temp=new CharacterElement*[columnSize+1];

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
   CharacterColumn& CharacterColumn::operator-=(std::string data)
{
    for(int i=0;i<columnSize;i++){
        if(*array[i]==data){
            *this-=i;
            break;
        }
    }
    return *this;
}

CharacterColumn& CharacterColumn::operator-=(int index)
{
    if(index<0||index>=columnSize)return *this;


    delete array[index];

    CharacterElement** temp=new CharacterElement*[columnSize-1];
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

int CharacterColumn::operator()(std::string data) const
{
    for (int i = 0; i < columnSize; i++)
    {
        if(*array[i]==data){
            return i;
        }
    }
    
    return -1;
}

CharacterColumn& CharacterColumn::operator()(std::string value, std::string newValue)
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

CharacterElement const* CharacterColumn::operator[](int pos) const
{
    if (pos < 0 || pos >= columnSize){
        return NULL;
    }

    return array[pos];
}

CharacterElement const* CharacterColumn::operator[](std::string value) const
{
    for (int i = 0; i < columnSize; i++){
        if (array[i] && (*array[i] == value))
            return array[i];
    }
    return NULL;
}

bool CharacterColumn::operator!() const
{
    if(array==NULL)return false;

    if(columnSize<0)return false;

    for (int i = 0; i < columnSize; i++)
    {
        if(array[i]==NULL)return false;
    }
    
    return true;
}
    