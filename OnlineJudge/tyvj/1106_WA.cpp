#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=505050, maxm=2300000, oo=1000000000;
int ihead[maxn], inext[maxm], to[maxm], iw[maxn], vis[maxn], d[maxn], cnt;

queue<int> q;
void spfa(int s, int n) {
	memset(vis, 0, sizeof(vis));
	int i, u, v;
	FOR(i, 0, n) d[i]=oo;
	d[s]=0; vis[s]=1;
	q.push(s);
	while(!q.empty()) {
		u=q.front(); q.pop();
		for(i=ihead[u]; i; i=inext[i]) {
			v=to[i];
			if(d[u] + iw[v] < d[v]) {
				d[v]=d[u] + iw[v];
				if(!vis[v]) {
					q.push(v);
					vis[v]=1;
				}
			}
		}
		vis[u]=0;
	}
}

void add(int u, int v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
}

int main() {
	int n;
	scanf("%d", &n);
	int i, j, u=0;
	add(0, 1);
	FOR(i, 1, n) FOR(j, 1, i) {
		scanf("%d", &iw[++u]);
		if(i!=1) {
			if(j==1) add(u, u+i-1); else add(u, u-1);
			if(j==i) add(u, u-i+1); else add(u, u+1);
		}
		add(u, u+i); add(u, u+i+1);
	}
	spfa(0, u+n+1);
	u=0;
	FOR(i, 1, n) {
		FOR(j, 1, i) printf("%d\t", iw[++u]);
		printf("\n");
	}
	u=0;
	FOR(i, 1, n) {
		FOR(j, 1, i) printf("%d\t", d[++u]);
		printf("\n");
	}
	printf("%d\n", d[u-n+1]);
	return 0;
}

