#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int h[440000], cnt, a[12];
bool vis[12];
void dfs(int x, int sum, int k) {
	if(x==n+1) { h[++cnt]=sum; return; }
	for(int i=1; i<=n; ++i) if(!vis[i]) {
		vis[i]=1;
		dfs(x+1, sum+a[i]*k, k*10);
		vis[i]=0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
	dfs(1, 0, 1); int x, y, j;
	sort(h+1, h+1+cnt);
	for(int i=1; i<=m; ++i) {
		scanf("%d%d", &x, &y);
		for(j=1; j<=cnt; ++j) if(((h[j]+x)%y)==0) { printf("%d\n", h[j]); break; }
		if(j>cnt) puts("None");
	}
	return 0;
}