#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int N;
vector<vector<pair<int, int>>>adj;
struct  node
{
	int cost, cur;
	bool operator<(const node& e)const
	{
		if (cost != e.cost)
			return cost > e.cost;
		else
			return cur > e.cur;
	}
};
int dikstra(int from, int to)
{
	vi len(N, -1);
	int cur_node, cur_cost;
	priority_queue<node>qe;
	qe.push({ 0,from });
	while (!qe.empty())
	{
		cur_node = qe.top().cur, cur_cost = qe.top().cost, qe.pop();
		if (cur_node == to)
			return cur_cost;
		if (~len[cur_node])
			continue;
		len[cur_node] = cur_cost;
		for (auto child : adj[cur_node])
			if (len[child.first] == -1)
				qe.push({ cur_cost + child.second,child.first });
	}
}
void solve()
{
	int X, W, v,idx = 0; cin >> N;
	string S, T;
	map<string, int>save;
	adj = vector<vector<pair<int, int>>>(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> S >> X, save[S] = idx++;
		for (int j = 0; j < X; j++)
			cin >> v >> W, v--, adj[save[S]].push_back({ v,W });
	}
	cin >> X;
	while (X--)
		cin >> S >> T, cout << dikstra(save[S], save[T]) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
