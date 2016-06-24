#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const Edge *a, const Edge *b)
{
	return a->weight < b->weight;
}

struct Edge{
	Edge(int start, int end, int weight)
		:start(start), end(end), weight(weight)
	{}
	int start;
	int end;
	int weight;
};

class UF{

	public:
		UF(int n)
		{
			array = new int[n];
			sz = new int[n];
			fill(sz, sz + n, 1);
			for (int i = 0; i != n; i++){
				array[i] = i;
			}
		}
		~UF()
		{
			delete[] array;
			delete[] sz;
		}
		bool connected(int a, int b)
		{
			return find(a) == find(b);
		}
		void unio(int a, int b)
		{
			if (connected(a, b))
				return;
			int aroot = find(a);
			int broot = find(b);
			if (sz[aroot] < sz[broot]){
				array[aroot] = broot;
				sz[broot] += sz[aroot]; 
			} else {
				array[broot] = aroot;
				sz[aroot] += sz[broot];
			}
		}
	private:
		int find(int a){
			while(a != array[a])
				a = array[a];
			return a;
		}
	private:
		int *array;
		int *sz;

};

int main()
{
	vector<Edge*> ev;
	int N, M;
	cin >> N >> M;
	int start, end, weight;
	UF uf(N);
	while(M--){
		cin >> start >> end >> weight;
		ev.push_back(new Edge(start - 1, end - 1, weight));
	}
	sort(ev.begin(), ev.end(), comp);
	int sum_weight = 0;
	int choosed_edges = 0;
	auto ite = ev.begin();
	while(choosed_edges != N - 1){ 
		if (ite == ev.end())
			break;
		if (!uf.connected((*ite)->start, (*ite)->end)) {
			uf.unio((*ite)->start, (*ite)->end);
			++choosed_edges;
			sum_weight += (*ite)->weight;
		}
		++ite;
	}
	if (ite == ev.end())
		cout << "is unconnected graph" << endl;
	cout << sum_weight << endl;
}