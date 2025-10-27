#include "TemplateFunctions.h"

namespace TemplateFunctions
{
    template <class T>
    void createAndPopulate(int size, T **&array)
    {
        array = new T*[size];
        for(int i=0;i<size;i++)
            array[i]=NULL;
    }

    template <class T>
    void expand(int &size, T **&array, T *&new_value)
    {
        T **temp = new T*[size+1];
        for(int i=0;i<size;i++)
            temp[i]=array[i];
        temp[size]=new_value;
        delete[] array;
        array=temp;
        size++;
    }

    template <class T>
    void reduce(int &size, T **&array, std::string value)
    {
        int index=-1;
        for(int i=0;i<size;i++)
        {
            if(array[i] && *array[i]==value)
            {
                index=i;
                break;
            }
        }
        if(index!=-1)
            reduce<T>(size,array,index);
    }

    template <class T>
    void reduce(int &size, T **&array, int index)
    {
        if(index<0 || index>=size)
            return;
        delete array[index];
        for(int i=index;i<size-1;i++)
            array[i]=array[i+1];
        array[size-1]=NULL;
        size--;
        T **temp = new T*[size];
        for(int i=0;i<size;i++)
            temp[i]=array[i];
        delete[] array;
        array=temp;
    }

    template <class T>
    T *get(const int size, T ** array, std::string value)
    {
        for(int i=0;i<size;i++)
        {
            if(array[i] && *array[i]==value)
                return array[i];
        }
        return NULL;
    }

    template <class T>
    int getIndex(const int size, T ** array, std::string value)
    {
        for(int i=0;i<size;i++)
        {
            if(array[i] && *array[i]==value)
                return i;
        }
        return -1;
    }

    template <class T>
    bool isFull(const int size, T ** array)
    {
        for(int i=0;i<size;i++)
        {
            if(array[i]==NULL)
                return false;
        }
        return true;
    }

    template <class T>
    T **clone(const int size, T ** array)
    {
        T **copy = new T*[size];
        for(int i=0;i<size;i++)
        {
            copy[i]=array[i]; // shallow copy of pointers
        }
        return copy;
    }

    template <class T>
    void update(int size, T **&array, std::string oldValue, std::string newValue)
    {
        for(int i=0;i<size;i++)
        {
            if(array[i] && *array[i]==oldValue)
            {
                (*array[i])(newValue);
                break;
            }
        }
    }

    template <class T,bool obj>
    void destroyArray(int &size, T **&a)
    {
        for(int i=0;i<size;i++)
        {
            delete a[i];
            a[i]=NULL;
        }
        delete[] a;
        a=NULL;
        size=0;
    }
}
