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
	else
	{
		if (n > Capacity())
		{
			Reserve(n);
		}
		iterator begin = _finish;
		while (begin < _start + n)
		{
			*begin = val;
			++begin;
		}
		_finish = _start + n;
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
	//���жϿռ��Ƿ��㹻
	if (_finish == _endofstorage)
	{
		//����֮ǰ����ԭ����λ�ã���������ٴβ����ҵ���λ�ò���ԭ����λ��
		size_t NewCapacity = Capacity() == 0 ? 2 : Capacity() * 2;

		//����������ݣ����� pos λ��
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
	//���������ʧЧ
	//++pos;
}

//����ɾ��posλ�õ���һ������
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
	//�﷨�Ǳ���
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