#include <iostream>
#include "Insertion.h"

using namespace std;

int main()
{
	int a[] = {5, 4, 3, 2, 1};
	Insertion<int>::sort(a,5);
	for (int i = 0; i != 5; i++)
		cout << a[i] << " ";
	cout << endl;
}