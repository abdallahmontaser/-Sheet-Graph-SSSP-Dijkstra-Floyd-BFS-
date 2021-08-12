#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int cnt = 1;
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
void solve()
{
	int N, M, from, to, v, u, time, cur_node, cur_cost;
	cin >> N >> M >> from >> to;
	vector<vector<pair<int,int>>>adj(N);
	vi vis(N, 0), len(N, 0);
	for (int i = 0; i < M; i++)
		cin >> u >> v >> time, adj[u].push_back({ v,time }), adj[v].push_back({ u,time });
	priority_queue<node>qe;
	qe.push({ 0,from });
	while (!qe.empty())
	{
		cur_node = qe.top().cur, cur_cost = qe.top().cost, qe.pop();
		if (cur_node == to)
		{
			cout << "Case #" << cnt++ << ": " << cur_cost << "\n";
			return;
		}
		if (vis[cur_node])
			continue;
		vis[cur_node] = 1;
		for (auto child : adj[cur_node])
			if (!vis[child.first])
				qe.push({ cur_cost + child.second,child.first });
	}
	cout << "Case #" << cnt++ << ": unreachable\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
