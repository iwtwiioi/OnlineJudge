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

const int N=1005, M=100005, oo=~0u>>2;
int ihead[N], cnt=1, n, m, p[N], x[N], d[N], vis[N], q[N+N], front, tail;
struct dat { int next, from, to, cap, w; }e[M];
void add(int u, int v, int c, int w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].from=u; e[cnt].cap=c; e[cnt].w=w;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].from=v; e[cnt].cap=0; e[cnt].w=-w;
}
bool spfa(int s, int t) {
	for1(i, s, t) d[i]=oo, vis[i]=0;
	front=tail=0; q[tail++]=s; d[s]=0; vis[s]=1;
	while(front!=tail) {
		int u=q[front++], v; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) if(e[i].cap && d[v=e[i].to]>d[u]+e[i].w) {
			d[v]=d[u]+e[i].w; p[v]=i;
			if(!vis[v]) {
				vis[v]=1;
				q[tail++]=v; if(tail==N) tail=0;
			}
		}
	}
	return d[t]!=oo;
}
int mincost(int s, int t) {
	int ret=0;
	while(spfa(s, t)) {
		int u, f=oo;
		for(u=t; u!=s; u=e[p[u]].from) f=min(f, e[p[u]].cap);
		for(u=t; u!=s; u=e[p[u]].from) e[p[u]].cap-=f, e[p[u]^1].cap+=f;
		ret+=d[t]*f;
	}
	return ret;
}
int main() {
	read(n); read(m);
	for1(i, 1, n) read(x[i]);
	int s=0, t=n+2;
	for1(i, 2, n+1) add(i, i-1, oo, 0);
	for1(i, 1, m) {
		int l=getint(), r=getint(), c=getint();
		add(l, r+1, oo, c);
	}
	for1(i, 1, n+1) {
		int c=x[i]-x[i-1];
		if(c>0) add(s, i, c, 0);
		if(c<0) add(i, t, -c, 0);
	}
	printf("%d\n", mincost(s, t));
	return 0;
}