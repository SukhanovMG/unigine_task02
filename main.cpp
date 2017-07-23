#include <iostream>

#include "myvector2.h"

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
	v.reserve(32);
	// for (int i = 0; i < 33; i++)
	// {
	// 	v.push_back(i);
	// 	print_vector(v);
	// }
	// v.add() = 666;
	// print_vector(v);
	// v.add(33);
	// print_vector(v);
	// v.erase(2);
	// print_vector(v);
	// v.erase(v.begin() + 5);
	// print_vector(v);

	// myvector<int> v2 = v;
	// print_vector(v2);
	// myvector<int> v3;
	// v3 = v;
	// print_vector(v3);
}