#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=1002;
int lca[N], d[N], fa[N], p[N], ihead[N], vis[N], cnt, n, U[N], V[N];
vector<pair<int, int> > q[N];
struct ED { int to, next, w; } e[N<<1];
void add(int u, int v, int w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].w=w;
}
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
void tarjan(const int &x) {
	p[x]=x;
	for(int i=ihead[x]; i; i=e[i].next) if(e[i].to!=fa[x]) {
		fa[e[i].to]=x; tarjan(e[i].to); p[e[i].to]=x;
	}
	vis[x]=1;
	int t=q[x].size();
	rep(i, t) if(vis[q[x][i].first]) lca[q[x][i].second]=ifind(q[x][i].first);
}
void dfs(const int &x, const int &sum) {
	d[x]=sum;
	for(int i=ihead[x]; i; i=e[i].next) if(e[i].to!=fa[x]) dfs(e[i].to, sum+e[i].w);
}
int main() {
	read(n); int cs=getint();
	int u, v, w;
	rep(i, n-1) {
		read(u); read(v); read(w);
		add(u, v, w);
	}
	for1(i, 1, cs) {
		read(u); read(v);
		U[i]=u; V[i]=v;
		q[u].push_back(pair<int, int> (v, i));
		q[v].push_back(pair<int, int> (u, i));
	}
	tarjan(n>>1); dfs(n>>1, 0);
	for1(i, 1, cs) {
		u=U[i], v=V[i];
		int lc=lca[i];
		printf("%d\n", d[u]+d[v]-(d[lc]<<1));
	}
	return 0;
}

