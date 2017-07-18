#include <iostream>

#include "myvector.h"

using namespace std;

int main()
{
	myvector<int> v;
	for (int i = 0; i < numeric_limits<int>::max(); i++)
	{
		v.push_back(i);
		cout << "size: " << v.size() << "; capacity: " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}