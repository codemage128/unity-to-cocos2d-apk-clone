#ifndef __COMMON_STACK_H__
#define __COMMON_STACK_H__

template <class T>
class Stack
{
public:
	static const int DEFAULT_SIZE = 64;
	static const int DEFAULT_STEP = 16;

	Stack() {
		_data = new T[DEFAULT_SIZE];
		_size = DEFAULT_SIZE;
		_count = 0;
	}

	Stack(int size) {
		if (size <= DEFAULT_SIZE)
			size = DEFAULT_SIZE;
		_data = new T(size);
		_size = size;
		_count = 0;
	};

	~Stack() {
		delete _data;
	};

	void setSize(int size) {
		if (size > _size) {
			T* buf = new T[size];
			if (_count > 0)
				memcpy(buf, _data, sizeof(T) * _count);
			delete _data;
			_data = buf;
			_size = size;
		}
	}

	int getCount() { return _count; }
	int getSize() { return _size; }

	void push(T data) {
		if (_count >= _size)
			setSize(_size + DEFAULT_STEP);
		_data[_count++] = data;
	};

	T pop() {
		if (_count > 0)
			return _data[--_count];
		return nullptr;
	};

	void clear() {
		_count = 0;
	}

private:
	T* _data;
	int _size;
	int _count;
};

#endif //__COMMON_STACK_H__