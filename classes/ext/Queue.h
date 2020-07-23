#ifndef __COMMON_QUEUE_H__
#define __COMMON_QUEUE_H__

template <class T>
class Queue
{
public:
	static const int DEFAULT_SIZE = 64;
	static const int DEFAULT_STEP = 16;

	Queue() {
		_data = new T[DEFAULT_SIZE];
		memset(_data, 0, sizeof(T)* DEFAULT_SIZE);
		_size = DEFAULT_SIZE;
		_count = 0;
		_head = _tail = 0;
	}

	Queue(int size) {
		if (size <= 0)
			size = DEFAULT_SIZE;
		_data = new T[size];
		memset(_data, 0, sizeof(T)* size);
		_size = size;
		_count = 0;
		_head = _tail = 0;
	};

	~Queue() {
		delete[] _data;
	};

	void setSize(int size) {
		if (size > _size) {
			T* buf = new T[size];

			//move existing data
			if (_count == _size || _head < _tail)
			{
				int n = _size - _tail;
				memcpy(buf, _data + _tail, sizeof(T)* n);
				memcpy(buf + n, _data, sizeof(T)* _head);
			}
			else
			{
				memcpy(buf, _data + _tail, sizeof(T)* _count);
			}
			_tail = 0;
			_head = _count;

			memset(buf + _count, 0, sizeof(T)* (size - _count));
			delete[] _data;
			_data = buf;
			_size = size;
		}
	}

	int getCount() const { return _count; }
	int getSize() const { return _size; }
	bool isEmpty() const { return _count == 0; }

	void enqueue(T item)
	{
		if (_count == _size)
			setSize(_size + DEFAULT_STEP);
		_data[_head] = item;
		_head = (_head + 1) % _size;
		_count++;
	}

	T dequeue()
	{
		if (_count > 0)
		{
			T& item = _data[_tail];
			_tail = (_tail + 1) % _size;
			_count--;
			return item;
		}
		return NULL;
	}

	void clear() {
		_count = 0;
		_head = _tail = 0;
	}

private:
	T* _data;
	int _size;
	int _count;
	int _head;
	int _tail;
};

#endif //__COMMON_QUEUE_H__