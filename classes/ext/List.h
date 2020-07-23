#ifndef __CONNON_LIST_H__
#define __CONNON_LIST_H__

#include "ext/Math.h"

#define LIST_DELETEALL(list, T)		(list).removeAll([](T* item) { if (item != nullptr) delete item; })


template <class T>
class List
{
public:
	static const int DEFAULT_SIZE = 8;
	static const int DEFAULT_STEP = 8;

	List() {
		_data = new T[DEFAULT_SIZE];
		memset(_data, 0, sizeof(T) * DEFAULT_SIZE);
		_size = DEFAULT_SIZE;
		_count = 0;
	}

	List(int size) {
		if (size <= 0)
			size = DEFAULT_SIZE;
		_data = new T[size];
		memset(_data, 0, sizeof(T) * size);
		_size = size;
		_count = 0;
	};

	~List() {
		delete [] _data;
	};

	void setSize(int size) {
		if (size > _size) {
			T* buf = new T[size];
			if (_count > 0)
				memcpy(buf, _data, sizeof(T) * _count);
			memset(buf + _count, 0, sizeof(T) * (size - _count));
			delete [] _data;
			_data = buf;
			_size = size;
		}
	}

	int getCount() const { return _count; }
	int getSize() const { return _size; }
	bool isEmpty() const { return _count == 0; }

	void add(const T& data) {
		if (_count >= _size)
			setSize(_size + DEFAULT_STEP);
		_data[_count++] = data;
	};
	void add(List<T>& other) {
		if (other._count > 0) {
			setSize(_count + other._count);
			memcpy(_data + _count, other._data, sizeof(T) * other._count);
			_count += other._count;
		}
	};

	void insert(T data, int index) {
		if (_count >= _size)
			setSize(_size + DEFAULT_STEP);
		if (index < 0)
			index = 0;
		else if (index > _count)
			index = _count;
		for (int i = _count; i > index; i--)
			_data[i] = _data[i - 1];
		_data[index] = data;
		_count++;
	}

	T& getAt(int index) {
		if (index >= 0 && index < _count)
			return _data[index];
		return NULL;
	};

	void setAt(int index, T data)
	{
		if (index >= 0 && index < _count)
			_data[index] = data;
	}

	T& getLast() {
		return _data[_count - 1];
	}

	void removeLast() {
		if (_count > 0)
			_count--;
	}

	void removeAt(int index) {
		if (index >= 0 && index < _count)
		{
			for (int i = index; i < _count; i++)
				_data[i] = _data[i + 1];
			_count--;
		}
	}

	void remove(T& t) {
		int index = indexOf(t);
		if (index != -1)
			removeAt(index);
	}

	void remove(List<T>& other) {
		for (int i = 0; i < other._count; i++)
			remove(other[i]);
	}

	void remove(std::function<bool(T&)> condition) {
		for (int i = _count - 1; i >= 0; i--)
			if (condition(_data[i]))
				removeAt(i);
	}

	void removeAll(std::function<void(T&)> callback)
	{
		if (callback != nullptr)
			doAction(callback);
		_count = 0;
	}

	T& operator[](int index)
    {
        return _data[index];
    }
    
    const T& operator[](int index) const
    {
        return _data[index];
    }

	void clear() {
		_count = 0;
	}

	void swap(int i, int j)
	{
		if (i == j) return;
		T temp = _data[i];
		_data[i] = _data[j];
		_data[j] = temp;
	}

	void swapRandomly(int number)
	{
		if (_count > 1)
			for (int i = 0; i < number; i++)
				swap(Math::random(_count), Math::random(_count));
	}

	int indexOf(T& t) const
	{
		for (int i = 0; i < _count; i++)
			if (_data[i] == t)
				return i;
		return -1;
	}

	bool contains(T& t) const
	{
		return indexOf(t) != -1;
	}

	int count(std::function<bool(T&)> condition) const {
		int count = 0;
		for (int i = 0; i < _count; i++)
		{
			if (condition(_data[i]))
				count++;
		}
		return count;
	}

	//RETURN: index or -1
	int find(std::function<bool(T&)> condition, T* result)
	{
		return find(0, _count - 1, condition, result);
	}

	int find(int startIndex, std::function<bool(T&)> condition, T* result)
	{
		return find(startIndex, _count - 1, condition, result);
	}

	int find(int startIndex, int endIndex, std::function<bool(T&)> condition, T* result)
	{
		for (int i = startIndex; i <= endIndex; i++)
		{
			if (condition(_data[i]))
			{
				if (result != nullptr)
					*result = _data[i];
				return i;
			}
		}
		return -1;
	}

	//RETURN: count
	int findAll(std::function<bool(T&)> condition, List<T>& result)
	{
		return findAll(0, _count - 1, condition, result);
	}

	int findAll(int startIndex, std::function<bool(T&)> condition, List<T>& result)
	{
		return findAll(startIndex, _count - 1, condition, result);
	}

	int findAll(int startIndex, int endIndex, std::function<bool(T&)> condition, List<T>& result)
	{
		int count = 0;
		for (int i = startIndex; i <= endIndex; i++)
		{
			if (condition(_data[i]))
			{
				result.add(_data[i]);
				count++;
			}
		}
		return count;
	}

	void doAction(std::function<void(T&)> operation)
	{
		for (int i = 0; i < _count; i++)
			operation(_data[i]);
	}

	void doAction(std::function<bool(T&)> condition, std::function<void(T&)> operation)
	{
		for (int i = 0; i < _count; i++)
			if (condition(_data[i]))
				operation(_data[i]);
	}

	void sort(std::function<bool(T&, T&)> compare/*swap condition for i, j*/)
	{
		for (int i = 0; i < _count - 1; i++)
		{
			for (int j = i + 1; j < _count; j++)
			{
				if (compare(_data[i], _data[j]))
					swap(i, j);
			}
		}
	}

	void copyTo(List<T>& other) const
	{
		other.clear();
		other.setSize(this->_count);
		other._count = this->_count;
		memcpy(other._data, this->_data, sizeof(T) * _count);
	}

	List<T>* clone()
	{
		List<T>* other = new List<T>(_count);
		this->copyTo(*other);
		return other;
	}

	void free()
	{
		delete [] _data;
		_data = nullptr;
	}
	void realloc() {
		_data = new T[DEFAULT_SIZE];
		memset(_data, 0, sizeof(T)* DEFAULT_SIZE);
		_size = DEFAULT_SIZE;
		_count = 0;
	}

private:
	T* _data;
	int _size;
	int _count;
};

#endif //__CONNON_LIST_H__