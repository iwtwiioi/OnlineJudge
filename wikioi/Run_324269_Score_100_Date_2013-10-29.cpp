#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 8, MAXV = 105;
bool vis[5050];
bool vvis[MAXN][MAXV][5050];
int l[MAXN], r[MAXN], w[MAXN];
int ans = 0;
int V, n;

void dfs(int d, int v1, int w1)
{
	if(d > n || v1 > V || vvis[d][v1][w1]) return;
	if(v1 == V && !vis[w1]){ans++; vis[w1] = 1;}
	int i, j;
	vvis[d][v1][w1] = 1;
	for(i = d; i <= n; i++)
	{
		for(j = l[i]; j <= r[i]; j++)
		{
			dfs(i, v1+j, w1+w[i]);
		}
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
