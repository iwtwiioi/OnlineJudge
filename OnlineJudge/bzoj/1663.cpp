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
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=1005, oo=~0u>>2;
int ihead[N], cnt, n, q[N], front, tail, d[N], f[N], vis[N], tm[N], ans;
struct ED { int next, to, w; }e[N*N];
void add(int u, int v, int w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].w=w; e[cnt].to=v;
}
void spfa(int s) {
	for1(i, 1, n) d[i]=oo;
	f[s]=tm[s]==0; d[s]=0; vis[s]=1;
	q[tail++]=s;
	while(tail!=front) {
		int u=q[front++], v; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) if(d[u]+e[i].w<=tm[v=e[i].to] && f[u]+1>f[v]) {
			d[v]=tm[v]; f[v]=f[u]+1;
			if(!vis[v]) {
				vis[v]=1;
				q[tail++]=v; if(tail==N) tail=0;
			}
		}
	}
}
int main() {
	read(n);
	for1(i, 1, n) read(tm[i]);
	for1(i, 1, n) for1(j, 1, n) {
		int k=getint();
		if(k) add(i, j, k);
	}
	spfa(1);
	for1(i, 1, n) ans=max(ans, f[i]);
	print(ans);
	return 0;
}

