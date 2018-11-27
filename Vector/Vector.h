#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		, _endofstorage(nullptr)
	{}
	Vector(const Vector<T>& v)
		:_start(nullptr)
		,_finish(nullptr)
		,_endofstorage(nullptr)
	{
		Reserve(v.Size());
		for (size_t i = 0; i < size; ++i)
		{
			//内置类型会调用memcpy,自定义类型会调用swap()
			//memcpy(_start, v._start, sizeof(T)*v.Size());

			swap(_start[i],v[i]);
		}
		_finish = _start + v.Size();
	}
	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}
	//const迭代器
	const_iterator cbegin()const
	{
		return _start;
	}

	const_iterator cend()const
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
	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofstorage, v._endofstorage);
	}
	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}
	void Reserve(size_t n);
	void Resize(size_t n, const T& val = T());
	void PushBack(const T& data);
	void PopBack();
	void Insert(iterator& pos, const T& data);
	iterator Erase(iterator pos);
	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
	}
private:
	T* _start;   //数组
	T* _finish;
	T* _endofstorage;
};
void TestVector();