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
		:_start(nullptr)
		,_finish(nullptr)
		,_endofstorage(nullptr)
	{
		Reserve(v.Size());
		for (size_t i = 0; i < size; ++i)
		{
			//�������ͻ����memcpy,�Զ������ͻ����swap()
			//memcpy(_start, v._start, sizeof(T)*v.Size());

			swap(tmp[i],_str[i])    
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
	void Insert(iterator pos, const T& data);
	iterator Erase(iterator pos);
	~Vector()
	{
		if (_start)
		{
			free(_start);
			_start = _finish = _endofstorage = nullptr;
		}
	}
private:
	T* _start;   //����
	T* _finish;
	T* _endofstorage;
};