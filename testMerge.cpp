#include <iostream>
#include "Merge.hpp"

using namespace std;

int main()
{
	int a[] = {1, 2, 2, 3, 0};
	Merge<int>::sort(a,5);
	Merge<int>::show(a,5);
}