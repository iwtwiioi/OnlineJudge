#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mkpii make_pair<int, int>
#define pdi pair<double, int>
#define mkpdi make_pair<double, int>
#define pli pair<ll, int>
#define mkpli make_pair<ll, int>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
#define rdm(x,i) for(int i=ihead[x]; i; i=e[i].next)

const int N=100005, M=1000005;
int TT, FF[N], LL[N], vis[N], s[N], top, scc, p[N], w[N], MD, ans1, ans2, in[N], front, tail;
struct Gr {
	int ihead[N], n, cnt;
	struct dat { int next, to; }e[M];
	void add(int u, int v) { e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; ++in[v]; }
	void dfs(int x) {
		FF[x]=LL[x]=++TT; vis[x]=1; s[++top]=x;
		rdm(x, i) {
			int y=e[i].to;
			if(!FF[y]) {
				dfs(y);
				LL[x]=min(LL[x], LL[y]);
			}
			else if(vis[y]) LL[x]=min(LL[x], FF[y]);
		}
		if(FF[x]==LL[x]) {
			++scc;
			int y;
			do {
				y=s[top--];
				vis[y]=0;
				p[y]=scc;
				w[scc]++;
			} while(x!=y);
		}
	}
	void tarjan() {
		for1(i, 1, n) if(!FF[i]) dfs(i);
	}
	void bfs() {
		int *d=FF, *f=LL, *q=s;
		for1(i, 1, n) d[i]=f[i]=vis[i]=0;
		front=tail=0;
		for1(i, 1, n) if(!in[i]) q[tail++]=i, d[i]=w[i], f[i]=1;
		while(front!=tail) {
			int u=q[front++]; if(front==N) front=0;
			rdm(u, i) {
				int v=e[i].to;
				if(!(--in[v])) { q[tail++]=v; if(tail==N) tail=0; }
				if(vis[v]) continue;
				if(d[v]==d[u]+w[v]) {
					f[v]=(f[v]+f[u])%MD;
				}
				else if(d[v]<d[u]+w[v]) {
					d[v]=d[u]+w[v];
					f[v]=f[u];
				}
				vis[v]=1;
			}
			rdm(u, i) vis[e[i].to]=0;
		}
		ans1=-1;
		for1(i, 1, n) ans1=max(ans1, d[i]);
		for1(i, 1, n) if(ans1==d[i]) ans2=(ans2+f[i])%MD;
	}
}G, g;
void build() {
	for1(i, 1, g.n) in[i]=0;
	G.n=scc;
	for1(x, 1, g.n) for(int i=g.ihead[x]; i; i=g.e[i].next) if(p[x]!=p[g.e[i].to]) G.add(p[x], p[g.e[i].to]);
}

int main() {
	read(g.n);
	int m=getint(); read(MD);
	for1(i, 1, m) { int u=getint(), v=getint(); g.add(u, v); }
	g.tarjan();
	build();
	G.bfs();
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}