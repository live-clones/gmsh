#pragma once
#include <set>

template<class T, class U>
class SetWrapperGmsh
{
private:
	std::set<T, U>* _set;
public:
    
//         std::set<T>::iterator iterType;
	SetWrapperGmsh(std::set<T, U>* original)
	{
		this->_set = original;
	}

	~SetWrapperGmsh()
	{
	}

	int size()
	{
		return this->_set->size();
	}

	bool contains(T item)
	{
//                std::set<T>::iterator iter= this->_set->find(item);
		return this->_set->find(item) != this->_set->end();
	}

	bool add(T item)
	{
		return this->_set->insert(item).second;
	}

	void clear()
	{
		this->_set->clear();
	}

	bool remove(T item)
	{
		if (this->_set->find(item) != this->_set->end()) {
			this->_set->erase(this->_set->find(item));
			return true;
		} else {
			return false;
		}
	}
};

template<class T, class U>
class SetIteratorGmsh
{
private:
	std::set<T, U>* _set;
	typename std::set<T, U>::iterator _iter;
public:
	SetIteratorGmsh(std::set<T, U>* original)
	{
		this->_set = original;
		this->_iter = this->_set->begin();
	}

	bool hasNext()
	{
		return this->_iter != this->_set->end();
	}

	T next()
	{
		T ret = (T) *this->_iter;
		this->_iter++;
		return ret;
	}
};
