#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

using Act = pair<int, int>;

int main()
{
	int n = 0;
	cin >> n;
	vector<Act> act;
	vector<int> room;
	int start, end;
	while(n--){
		cin >> start >> end;
		act.push_back(make_pair(start, end));
	}
	sort(act.begin(), act.end(), less<pair<int, int>>());
	for(auto it = act.begin(); it != act.end(); it++){
		auto it1 = room.begin();
		for(; it1 != room.end(); it1++){
			if (*it1 <= it->first)
				break;
		}
		if (it1 == room.end()){
			room.push_back(it->second);
		} else {
			*it1 = it->second;
		}
	}
	cout << room.size() << endl;
}
