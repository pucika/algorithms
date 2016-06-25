#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <bitset>
#include <limits>

using namespace std;

int main()
{
	int n, m, start, end;
	cin >> n >> m >> start >> end;
	vector<vector<tuple<int, int, int>>> map(n, vector<tuple<int, int, int>>());
	vector<int> dis(n, 0);
	vector<int> route(n, 0);
	int score;
	vector<int> vscore;
	while(n--){
		cin >> score;
		vscore.push_back(score);
	}
	int x, y, z;
	while(m--){
		cin >> x >> y >> z;
		map.at(x).push_back(make_tuple(z, y, x));
		map.at(y).push_back(make_tuple(z, x, y));
	}
	bitset<600> visited;
	visited.set(start);
	priority_queue< tuple<int, int, int>, 
		vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> candi;
	for(auto it = map.at(start).begin(); it != map.at(start).end(); it++){
		candi.push(*it);
	} 
	int total_score = vscore.at(start);
	while(!visited.test(end))
	{
		auto top = candi.top();
		candi.pop();
		if (!visited.test(get<1>(top))){
			visited.set(get<1>(top));
			if (dis.at(get<1>(top) > )
				route.at(get<1>(top)) = get<2>(top);
			dis.at(get<1>(top)) = get<0>(top);
			for(auto it = map.at(get<1>(top)).begin(); it != map.at(get<1>(top)).end(); it++){
				candi.push(make_tuple(dis.at(get<1>(top)) + get<0>(*it), get<1>(*it), get<2>(*it)));
			}
		}
	}
	for(int room = end; room != start; ){
		total_score += vscore.at(room);
		room = route.at(room);
	}
	cout << dis.at(end) << " " << total_score << endl;
}