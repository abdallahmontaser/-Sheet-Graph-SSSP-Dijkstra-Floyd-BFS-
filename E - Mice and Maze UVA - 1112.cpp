#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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
	int N, Time, Exit, M, v, u, TL, cur_node, cur_cost, ans = 0;
	cin >> N >> Exit >> Time >> M;
	vector<vector<pair<int, int>>>adj(N);
	vi  len(N, -1);
	for (int i = 0; i < M; i++)
		cin >> u >> v >> TL, u--, v--, adj[v].push_back({ u,TL });
	priority_queue<node>qe;
	qe.push({ 0,Exit - 1 });
	while (!qe.empty())
	{
		cur_node = qe.top().cur, cur_cost = qe.top().cost, qe.pop();
		if (len[cur_node] != -1)
			continue;
		len[cur_node] = cur_cost;
		for (auto child : adj[cur_node])
			if (len[child.first] == -1)
				qe.push({ cur_cost + child.second,child.first });
	}
	for (int i = 0; i < N; i++)
		if (len[i] != -1)
			ans += (len[i] <= Time);
	cout << ans << "\n";
}
int main()
{
	int T ; cin >> T;
	while (T--)
	{
		solve();
		if (T)
			cout << "\n";
	}
}
