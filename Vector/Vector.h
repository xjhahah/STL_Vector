#pragma once

#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
	typedef T* iterator;
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		, _endofstorage(nullptr)
	{}
	Vector(const Vector<T>& v)
		:_start(v._start)
		,_finish(v._finish)
		,_capacity(v._endofstorage)
	{}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	size_t Size()const
	{
		return _finish - _start;
	}

	size_t Capacity()const
	{
		return _endofstorage-_start;
	}

	T& operator[](size_t pos)
	{
		if (pos < Size())
			return _start[pos];
	}
	const T& operator[](size_t pos) const
	{
		if (pos < Size())
			return _start[pos];
	}
	~Vector()
	{
		if (_start)
		{
			free(_start);
			_finish = _capacity = nullptr;
		}
	}
private:
	T* _start;
	T* _finish;
	T* _endofstorage;
};
