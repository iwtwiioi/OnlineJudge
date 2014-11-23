#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=250, M=600;
int ihead[N], n, m, cnt, x, s, flag, vis[N], d[N];
struct ED { int to, next, w; }e[M];
void add(int u, int v, int w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}
void dfs(int u) {
	vis[u]=1;
	int v;
	for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]<d[u]+e[i].w+x) {
		if(vis[v]) { flag=1; return; }
		d[v]=d[u]+e[i].w+x;
		dfs(v);
		if(flag) return;
	}
	vis[u]=0;
}
void spfa() {
	d[s]=x;
	dfs(s);
	if(flag) { puts("-1"); return; }
}
int main() {
	int t;
	read(x); read(m); read(n); read(t); read(s);
	for1(i, 1, m) {
		int u=getint(), v=getint();
		add(u, v, 0);
	}
	for1(i, 1, t) {
		int u=getint(), v=getint(), w=getint();
		add(u, v, -w);
	}
	spfa();
	if(!flag) {
		int ans=0;
		for1(i, 1, n) ans=max(ans, d[i]);
		print(ans);
	}
	return 0;
}