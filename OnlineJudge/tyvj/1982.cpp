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

const int N=1010, M=2000000, oo=1000000000;
int ihead[N], cnt=1, d[N], p[N], n, a, b, wa[N], wb[N], vis[N], q[N], front, tail;
struct ED { int from, to, cap, w, next; } e[M];
inline void add(const int &u, const int &v, const int &c, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].from=u; e[cnt].cap=c; e[cnt].w=w;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].from=v; e[cnt].cap=0; e[cnt].w=-w;
}
inline const bool spfa(const int &s, const int &t) {
	for1(i, 0, t) d[i]=oo, vis[i]=0;
	vis[s]=1; d[s]=front=tail=0; q[tail++]=s;
	int u, v, i;
	while(front!=tail) {
		u=q[front++]; if(front==N) front=0;
		for(i=ihead[u]; i; i=e[i].next) if(e[i].cap && d[v=e[i].to]>d[u]+e[i].w) {
			d[v]=d[u]+e[i].w; p[v]=i;
			if(!vis[v]) {
				vis[v]=1, q[tail++]=v;
				if(tail==N) tail=0;
			}
		}
		vis[u]=0;
	}
	return d[t]!=oo;
}
int mcf(const int &s, const int &t) {
	int ret=0, f, u;
	while(spfa(s, t)) {
		for(f=oo, u=t; u!=s; u=e[p[u]].from) f=min(f, e[p[u]].cap);
		for(u=t; u!=s; u=e[p[u]].from) e[p[u]].cap-=f, e[p[u]^1].cap+=f;
		ret+=d[t]*f;
	}
	return ret;
}
int main() {
	read(n); read(a); read(b);
	int s=0, na=1000, t=na+1;
	for1(i, 1, n) add(s, i, 1, 0), add(i, na, 1, 0);
	for1(i, 1, a) read(wa[i]);
	for1(i, 1, b) read(wb[i]);
	for1(i, 1, a) add(na, n+i, 1, 0);
	for1(i, 1, b) add(n+a+i, t, 1, 0);
	for1(i, 1, a) for1(j, 1, b) add(n+i, n+a+j, 1, (wa[i]-wb[j])*(wa[i]-wb[j]));
	print(mcf(s, t));

	return 0;
}
