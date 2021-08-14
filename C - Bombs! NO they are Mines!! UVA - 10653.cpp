#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int dx[] = { 0, 0,1,-1, -1,-1,1, 1 };
int dy[] = { 1,-1,0, 0 ,-1, 1,1,-1 };
int N, M, Q, X, Y, num;
vector<vi>ve, len;
bool vaild(int i, int j)
{
	if (i < N && j < M && i >= 0 && j >= 0 && ve[i][j] && len[i][j] == -1)
		return true;
	return false;
}
void solve()
{
	while (cin >> N >> M && (N && M))
	{
		ve = vector<vi>(N, vi(M, 1)), len = vector<vi>(N, vi(M, -1));
		pair<int, int>from, to, tem;
		cin >> Q;
		while (Q--)
		{
			cin >> X >> num;
			for (int i = 0; i < num; i++)
				cin >> Y, ve[X][Y] = 0;
		}
		cin >> from.first >> from.second >> to.first >> to.second;
		queue<pair<int,int>>qe;
		qe.push(from);
		len[from.first][from.second] = 0;
		while (!qe.empty())
		{
			tem = qe.front(), qe.pop();
			if (tem == to)
				break;
			for (int x = 0; x < 4; x++)
				if (vaild(tem.first + dx[x], tem.second + dy[x]))
					len[tem.first + dx[x]][tem.second + dy[x]] = len[tem.first][tem.second] + 1, qe.push({ tem.first + dx[x], tem.second + dy[x] });
		}
		cout << len[to.first][to.second] << "\n";
	}
}
int main()
{
	solve();
}
