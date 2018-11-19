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
				//tmp[i].swap(_start[i]);    //����ֻ����string ͬ��������
				//swap(tmp[i],_str[i])    //���ܽ���stringҲ�ܽ���int���͵�����
			}
			delete[] _start;
		}

		_start = tmp;
		_finish = _start + size;
		_endofstorage = _start + n;
	}
	//���� ��string �Ľ���


}
template <class T>
void Vector<T>::Resize(size_t n, const T& val)
{
	//�������С�ռ�
	if (n <= Size())
	{
		_finish = _start + n;
		return;
	}
	//����ռ䲻��������
	if (n > Capacity())
	{
		Reserve(n);
	}
	//�����ӵĿռ�ֵ����val
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
	//���жϿռ��Ƿ��㹻
	if (_finish == _endofstorage)
	{
		//����֮ǰ����ԭ����λ�ã���������ٴβ����ҵ���λ�ò���ԭ����λ��
		size_t size = Size();
		size_t NewCapacity = _endofstorage == 0 ? 2 : _endofstorage * 2;

		//����������ݣ����� pos λ��
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
