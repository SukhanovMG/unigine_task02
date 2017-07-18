#include <iostream>

#include "myvector.h"

using namespace std;

int main()
{
	myvector<int> v;
	for (int i = 1; i < 5; i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}