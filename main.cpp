#include <iostream>

#include "myvector.h"

using namespace std;

template<typename T>
void print_vector(const myvector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "; capacity: " << v.capacity() << endl;
}

int main()
{
	myvector<int> v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(i);
		cout << "size: " << v.size() << "; capacity: " << v.capacity() << endl;
	}
	print_vector(v);
	v.add() = 666;
	v.add(33);
	print_vector(v);
	print_vector(v);
	v.erase(2);
	print_vector(v);
	v.erase(v.begin() + 5);
	print_vector(v);
}