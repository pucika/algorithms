#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using Act = pair<int, int>;

bool comp(Act &a, Act &b)
{
	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;
	int start, end;
	vector<Act> act;
	while(n--){
		cin >> start >> end;
		act.push_back(make_pair(start, end));
	}
	sort(act.begin(), act.end(), comp);
	auto last = act.begin();
	int num_ac = 1;
	for(auto ite = next(act.begin()); ite != act.end(); ite++){
		if (ite->first >= last->second){
			++num_ac;
			last = ite;
		}
	}
	cout << num_ac << endl;
}
