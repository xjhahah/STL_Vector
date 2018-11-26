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
		size_t NewCapacity = Capacity() == 0 ? 2 : Capacity() * 2;

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

//����ɾ��posλ�õ���һ������
Vector<int>::iterator Vector<int>::Erase(iterator pos)
{
	iterator begin = pos + 1;
	while (begin != end())
	{
		*(begin - 1) = *begin;
		++begin;
	}
	--_finish;
	return pos;
}

/*
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

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//v.Reserve(10);
	//cout << "Size(): " << v.Size() << endl;
	//cout << "Capacity(): " << v.Capacity() << endl;

	//v.PopBack();

	//cout << "Size(): " << v.Size() << endl;
	//cout << "Capacity(): " << v.Capacity() << endl;

	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	Vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.Insert(pos, 6);
	Vector<int>::iterator It = v.begin();
	while (It != v.end())
	{
		cout << *It<<" ";
		++It;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 2);
	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.Erase(it);
		}
		else
		{
			++it;
		}
	}
	cout << endl;
}
*/