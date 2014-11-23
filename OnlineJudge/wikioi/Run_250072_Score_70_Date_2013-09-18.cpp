#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100;
const int INF = 1000000000;
long long ans = 0;
int edge[MAXN][MAXN] = {{0,0}}, n;
int d[MAXN];
bool vis[MAXN] = {0};
int i, j, m;
struct cmp{bool operator()(const int &a, const int &b){return d[a] > d[b];}};
priority_queue<int, vector<int>, cmp> q;
int main()
{
	cin >> n;
	for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) cin >> edge[i][j];
	for(i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0;
	int u;
	q.push(1);
	while(!q.empty())
	{
		u = q.top(); q.pop();
		if(!vis[u]) ans += d[u];
		vis[u] = 1;
		for(i = 1; i <= n; i++)
			if(!vis[i] && edge[u][i] && d[i] > edge[u][i])
			{
				d[i] = edge[u][i];
				q.push(i);
			}
	}
	cout << ans;
	return 0;
}

