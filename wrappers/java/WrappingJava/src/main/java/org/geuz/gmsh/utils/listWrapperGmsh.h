#pragma once
#include <list>
 
template<class T>
class ListWrapperGmsh
{
public:
    std::list<T>* _list;
    ListWrapperGmsh(std::list<T>* original)
    {
        this->_list = original;
    }
 
    ~ListWrapperGmsh()
    {
    }
 
    int size()
    {
        return this->_list->size();
    }
 
    bool contains(T item)
    {
	typename std::list<T>::iterator iter;
        for(iter = this->_list->begin();
                iter != this->_list->end(); iter++) {
            if (*iter == item) {
                return true;
            }
        }
        return false;
    }
 
    bool add(T item)
    {
        this->_list->push_back(item);
        return true;
    }
 
    void clear()
    {
        this->_list->clear();
    }
 
    bool remove(T item)
    {
        int size = this->_list->size();
        this->_list->remove(item);
        return size != this->_list->size();
    }
};
 
template<class T>
class ListIteratorGmsh
{
private:
    std::list<T>* _list;
    typename std::list<T>::const_iterator _iter;
public:
    ListIteratorGmsh(std::list<T>* original)
    {
        this->_list = original;
        this->_iter = this->_list->begin();
    }
 
    bool hasNext()
    {
        return this->_iter != this->_list->end();
    }
 
    T next()
    {
        T ret = (T) *this->_iter;
        this->_iter++;
        return ret;
    }
};
