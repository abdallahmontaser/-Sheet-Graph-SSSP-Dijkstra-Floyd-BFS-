#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int dx[] = { 0, 0,1,-1, -1,-1,1, 1 };
int dy[] = { 1,-1,0, 0 ,-1, 1,1,-1 };
int N, M;
struct  node
{
	int cost, i, j;
	bool operator<(const node& e)const
	{
		if (cost != e.cost)
			return cost > e.cost;
		else if (i != e.i)
			return i < e.i;
		else
			return j < e.j;
	}
};
bool vaild(int x, int y)
{
	if (x < N && y < M && x >= 0 && y >= 0)
		return true;
	return false;
}
void solve()
{
	cin >> N >> M;
	vector<vi>ve(N, vi(M)), len(N, vi(M, -1));
	node tem;
	for (auto& it : ve)
		for (auto &it2 : it)
			cin >> it2;
	priority_queue<node>qe;
	qe.push({ ve[0][0],0,0 });
	while (!qe.empty())
	{
		tem.i = qe.top().i, tem.j = qe.top().j, tem.cost = qe.top().cost, qe.pop();
		if (tem.i == N - 1 && tem.j == M - 1)
		{
			cout << tem.cost << "\n";
			return;
		}
		if (~len[tem.i][tem.j])
			continue;
		len[tem.i][tem.j] = tem.cost;
		for (int x = 0; x < 4; x++)
			if (vaild(tem.i + dx[x], tem.j + dy[x]) && len[tem.i + dx[x]][tem.j + dy[x]] == -1)
				qe.push({ tem.cost + ve[tem.i + dx[x]][tem.j + dy[x]],tem.i + dx[x], tem.j + dy[x] });
	}
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
