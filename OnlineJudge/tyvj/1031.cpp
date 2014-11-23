#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)

const int maxn = 3000, maxm = 14000, oo = ~0u>>1;
int ihead[maxn], inext[maxm], iv[maxm], iw[maxm], vis[maxn], s, t, d[maxn], n, m;

queue<int> q;
void spfa() {
	memset(vis, 0, sizeof(vis));
	int i, u, v;
	FOR(i, 1, n) d[i] = oo;
	d[s] = 0; vis[s] = 1;
	q.push(s);
	while(!q.empty()) {
		u = q.front(); q.pop();
		for(i = ihead[u]; i; i = inext[i]) {
			v = iv[i];
			if(d[u] + iw[i] < d[v]) {
				d[v] = d[u] + iw[i];
				if(!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = 0;
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	int i, u, v, w;
	FOR(i, 1, m) {
		scanf("%d%d%d", &u, &v, &w);
		inext[i] = ihead[u]; inext[i+m] = ihead[v];
		ihead[u] = i; ihead[v] = i+m;
		iv[i] = v; iv[i+m] = u;
		iw[i] = iw[i+m] = w;
	}
	spfa();
	printf("%d\n", d[t]);
	return 0;
}
