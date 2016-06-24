#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int main()
{
    int n = 0, m = 0;
    double sum_weight = 0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> map(n, vector<pair<int, int>>());
    vector<int> visited(n, 0);
    int from, to, weight;
    while(m--){
        cin >> from >> to >> weight;
        map.at(from - 1).push_back(make_pair(to - 1, weight));
        map.at(to - 1).push_back(make_pair(from - 1, weight));
    }
    set<int> vs = {0};
    visited.at(0) = 1;
    int min_weight = INT_MAX;
    int candv;
    while(vs.size() != n)
    {
    	min_weight = INT_MAX;
        for (auto ivs = vs.begin(); ivs != vs.end(); ivs++){
        	for (auto ieg = map[*ivs].begin(); ieg != map[*ivs].end(); ieg++){
        		if (visited.at(ieg->first) == 0
        			&& ieg->second <= min_weight){
        			min_weight = ieg->second;
        			candv = ieg->first;
        		}
        	}
        }
        vs.insert(candv);
        visited.at(candv) = 1;
        sum_weight += min_weight;
    }
    cout << sum_weight << endl;
    return 0;
}
