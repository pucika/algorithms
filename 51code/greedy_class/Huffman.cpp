#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> ele;
	int m;
	int physical_pow = 0;
	while(N--)
	{
		cin >> m;
		ele.push(m);
	}
	while(ele.size() != 1){
		int top1 = ele.top();
		ele.pop();
		int top2 = ele.top();
		ele.pop();
		int subele = top1 + top2;
		physical_pow += subele;
		ele.push(subele);
	}
	cout << physical_pow << endl;
	return 0;
}