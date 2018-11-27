#include "Vector.h"

template <class T>
void Vector<T>::Reserve(size_t n)
{
	if (n > Capacity())
	{
		T* tmp = new T[n];
		size_t size = Size();
		if (_start)
		{
			for (size_t i = 0; i < size; ++i)
			{
				tmp[i] = _start[i]; 
				//tmp[i].swap(_start[i]);    //但是只能是string 同类型数据
				//swap(tmp[i],_str[i])    //既能交换string也能交换int类型的数据
			}
			delete[] _start;
		}

		_start = tmp;
		_finish = _start + size;
		_endofstorage = _start + n;
	}
	//法二 用string 的交换


}
template <class T>
void Vector<T>::Resize(size_t n, const T& val)
{
	//如果是缩小空间
	if (n <= Size())
	{
		_finish = _start + n;
		return;
	}
	//如果空间不够，增容
	if (n > Capacity())
	{
		Reserve(n);
	}
	//将增加的空间值赋成val
	iterator it = _finish;
	iterator _finish = _start + n;
	if (it != _finish)
	{
		*it = val;
		++it;
	}
}
template <class T>
void Vector<T>::PushBack(const T& data)
{
	Insert(_finish, data);
}
template <class T>
void Vector<T>::PopBack()
{
	Erase(_finish-1);
}
template <class T>
void Vector<T>::Insert(iterator& pos, const T& data)
{
	assert(pos <= _finish);


	size_t offset = pos - _start;
	//先判断空间是否足够
	if (_finish == _endofstorage)
	{
		//更新之前保存原来的位置，避免出现再次插入找到的位置不是原来的位置
		size_t NewCapacity = Capacity() == 0 ? 2 : Capacity() * 2;

		//如果发生增容，更新 pos 位置
		Reserve(NewCapacity);
		pos = _start + offset;
	}
	iterator end = _finish;
	while (end >= pos)
	{
		*end = *(end - 1);
		--end;
	}
	*pos = data;
	++_finish;
	//解决迭代器失效
	//++pos;
}

//返回删除pos位置的下一个数据
Vector<int>::iterator Vector<int>::Erase(iterator pos)
{
	assert(pos < _finish);
	iterator begin = pos + 1;
	while (begin != end())
	{
		*(begin - 1) = *begin;
		++begin;
	}
	--_finish;
	return pos;
}

void TestVector()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);

	cout << "Size(): " << v.Size() << endl;
	cout << "Capacity(): " << v.Capacity() << endl;
	//语法糖遍历
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.PopBack();
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//TestErase
	auto eit = v.begin();
	while (eit != v.end())
	{
		if (*eit % 2 == 0)
		{
			eit = v.Erase(eit);
		}
		else
		{
			++eit;
		}
	}
	for (const auto& e2 : v)
	{
		cout << e2 << " ";
	}
	cout << endl;
}