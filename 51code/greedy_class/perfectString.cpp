#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    map<char, int> cmap;
    string str;
    cin >> str;
    for (auto i = str.begin(); i != str.end(); i++)
    {
       cmap[tolower(*i)]++;
    }
    int base = 26;
    int result = 0;
    vector<int> countv;
    for (auto it = cmap.rbegin(); it != cmap.rend(); it++){
		countv.push_back(it->second);
    }
    sort(countv.begin(), countv.end(),greater<int>());
    for(auto it = countv.begin(); it != countv.end(); it++){
		result += *it * base--;
	}
    cout << result;
}
