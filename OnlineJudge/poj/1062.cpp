#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
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

const int N=105, oo=~0u>>2;
int m, n, up[N], now, vis[N], d[N], q[N], front, tail, ihead[N], cnt;
struct ED { int to, next, w; }e[N*N];
inline void add(const int &u, const int &v, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}
inline const bool check(const int &x) { return now<=up[x] && up[x]<=now+m; }
int spfa(const int &s, const int &t) {
	CC(d, 0x3f); CC(vis, 0);
	d[s]=0; vis[s]=1; front=tail=0; q[tail++]=s;
	int u, v;
	while(front!=tail) {
		u=q[front++]; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+e[i].w && check(e[i].to)) {
			d[v]=d[u]+e[i].w;
			if(!vis[v]) {
				vis[v]=1; q[tail++]=v; if(tail==N) tail=0;
			}
		}
	}
	return d[t];
}

int main() {
	read(m); read(n);
	int x, y, z, ans=oo;
	for1(i, 1, n) {
		read(x); read(y); read(z);
		add(0, i, x);
		up[i]=y;
		rep(j, z) { read(x); read(y); add(x, i, y); }
	}
	for(now=up[1]-m; now<=up[1]; ++now) ans=min(ans, spfa(0, 1));
	print(ans);
	return 0;
}

