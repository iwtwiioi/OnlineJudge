#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
#define for1(i,a,n) for(i=a;i<=n;++i)
#define for2(i,a,n) for(i=a;i<n;++i)
#define for3(i,a,n) for(i=n;i>=a;--i)
#define for4(i,a,n) for(i=n;i>a;--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) scanf("%d", &a)
#define print(a) printf("%d", a);

const int N=105, M=100000, oo=1000000000;
int ihead[N], inext[M], to[M], w[M], cnt=1;
int d[N], vis[N], flag[N][N], ff[N], f[N];
queue<int> q;

void add(int u, int v, int c) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v; w[cnt]=c;
}

int n, m, k, e;

int cost(int l, int r) {
	int i, j, u, v;
	for1(i, 1, m) d[i]=oo, vis[i]=0, ff[i]=1;
	for1(i, 1, m) for1(j, l, r)
		if(flag[i][j]) { ff[i]=0; break; }
	d[1]=0; vis[1]=1; q.push(1);
	while(!q.empty()) {
		u=q.front(); q.pop();
		for(i=ihead[u]; i; i=inext[i]) if(ff[to[i]] && d[to[i]]>d[u]+w[i]){
			v=to[i];
			d[v]=d[u]+w[i];
			if(!vis[v]) {
				vis[v]=1;
				q.push(v);
			}
		}
		vis[u]=0;
	}
	if(d[m]==oo) return oo;
	return d[m]*(r-l+1);
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &e);
	int i, j, t;
	int p, a, b;
	for1(i, 1, e) {
		scanf("%d%d%d", &a, &b, &p);
		add(a, b, p); add(b, a, p);
	}
	read(t);
	for1(i, 1, t) {
		scanf("%d%d%d", &p, &a, &b);
		for1(j, a, b)
			flag[p][j]=1;
	}
	for1(i, 1, n) {
		f[i]=cost(1, i);
		for2(j, 2, i)
			f[i]=min(f[i], f[j]+cost(j+1, i)+k);
	}
	print(f[n]);
	return 0;
}

