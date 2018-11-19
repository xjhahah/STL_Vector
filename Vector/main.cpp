#include "Vector.h"


void TestVector()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
int mian()
{
	TestVector();
	return 0;
}