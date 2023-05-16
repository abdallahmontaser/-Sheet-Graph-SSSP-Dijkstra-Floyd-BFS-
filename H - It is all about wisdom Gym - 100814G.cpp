#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

void Candidate_Elde7k() {
	//freopen("jumping.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
struct node {
	ll mn, cost, cur;
	bool operator<(const node& e)const {
		if (cost != e.cost)
			return cost > e.cost;
		else if (mn != e.mn)
			return mn > e.mn;
		else
			return cur > e.cur;
	}
};
struct abdooo {
	ll to, cost, pay;
};
int n, m, k;
vector<vector<abdooo>>adj;
bool dijkstra(ll x) {
	vector<pair<int, int>> len(n + 1, { -1 ,-1 });
	priority_queue<node>qe;
	qe.push({ INT_MIN,0,1 });
	while (!qe.empty()) {
		node cur = qe.top();
		qe.pop();
		if (~len[cur.cur].first) continue;
		len[cur.cur] = { cur.cost,cur.mn };
		if (cur.cur == n) return true;
		for (auto& child : adj[cur.cur]) {
			if (len[child.to].first == -1) {
				if (cur.cost + child.cost < k && max(cur.mn, child.pay) <= x) {
					qe.push({ max(cur.mn,child.pay),cur.cost + child.cost,child.to });
				}
			}
		}
	}
	return false;
}

int main() {
	Candidate_Elde7k();
	int T; cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		adj = vector<vector<abdooo>>(n + 2);
		for (int i = 0; i < m; i++) {
			int u, v, w, x; cin >> u >> v >> w >> x;
			adj[u].push_back({ v,w,x });
			adj[v].push_back({ u,w,x });
		}
		ll l = 1, r = 1e9, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (dijkstra(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
