#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 8, MAXV = 105;
bool vis[MAXV];
int l[MAXN], r[MAXN], w[MAXN];
int ans = 0;
int V, n;

void dfs(int d, int v1, int w1)
{
	if(d > n || v1 > V) return;
	if(v1 == V && !vis[w1]){ans++; vis[w1] = 1;}
	int i, j;
	for(i = l[d]; i <= r[d]; i++)
	{
		dfs(d, v1+i, w1+w[d]);
		for(j = d; j <= n; j++)
			dfs(d+1, v1, w1);
	}
}

int main()
{
	cin >> V >> n;
	int i;
	for(i = 1; i <= n; i++) cin >> w[i] >> l[i] >> r[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
