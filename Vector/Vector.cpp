#include "Vector.h"

template <class T>
void Vector<T>::Reserve(size_t n)
{
	if (n > _endofstorage)
	{
		T* tmp = new T[n + 1];
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
	Erase(_finish);
}
template <class T>
void Vector<T>::Insert(iterator pos, const T& data)
{
	assert(pos <= _finish);

	size_t offset = pos - _start;
	//先判断空间是否足够
	if (_finish == _endofstorage)
	{
		//更新之前保存原来的位置，避免出现再次插入找到的位置不是原来的位置
		size_t size = Size();
		size_t NewCapacity = _endofstorage == 0 ? 2 : _endofstorage * 2;

		//如果发生增容，更新 pos 位置
		Reserve(NewCapacity);
		pos = _start + size;
	}
	iterator end = _finish;
	while (end >= pos)
	{
		*end = *(end + 1);
		--end;
	}
	*pos = data;
	++_finish;
}
//template <class T>
//Vector<T>::iterator Vector<T>::Erase(iterator pos)
//{
//
//}
