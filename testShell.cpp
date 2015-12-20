#include <iostream>
#include "shell.hpp"

using namespace std;

int main()
{
	int a[] = {5, 4, 3, 2, 1};
	Shell<int>::sort(a,5);
	for (int i = 0; i != 5; i++)
		cout << a[i] << " ";
	cout << endl;
}