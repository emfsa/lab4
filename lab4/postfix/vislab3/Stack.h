#include <iostream>

template<typename T>

class Stack
{
	T* _data;
	size_t _size;
	size_t _top;
	size_t _count = 0;
	void Resize()
	{
		size_t size = _size * 2;
		T* data = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = _data[i];

		}
		delete[] _data;
		_size = size;
		_data = data;
	}

public:
	Stack(size_t size) : _size(size)
	{
		_data = new T[_size];
	}

	void Pop()
	{
		if (!_count)
		{
			_count--;
		}
	}
	void Push(T elem)
	{
		if (_count + 1 == _size)
		{
			Resize();
		}
		_data[_count] = elem;
		_count++;
	}



	~Stack()
	{
		delete[] _data;
	}
};
