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

const int N=1010, M=2010000, oo=~0u>>1;
int ihead[N], cnt=1, cur[N], gap[N], d[N], p[N], n, m, k, vis[N], q[N], front, tail, nd[N][3];
struct ED { int from, to, cap, w, next; } e[M];
inline void add(const int &u, const int &v, const int &c, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].from=u; e[cnt].cap=c; e[cnt].w=w;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].from=v; e[cnt].cap=0; e[cnt].w=-w;
}
int isap(const int &s, const int &t, const int &n) {
	for1(i, 0, n) cur[i]=ihead[i];
	int ret=0, i, f, u=s;
	gap[0]=n;
	while(d[s]<n) {
		for(i=cur[u]; i; i=e[i].next) if(e[i].cap && d[u]==d[e[i].to]+1) break;
		if(i) {
			p[e[i].to]=cur[u]=i; u=e[i].to;
			if(u==t) {
				for(f=oo; u!=s; u=e[p[u]].from) f=min(f, e[p[u]].cap);
				for(u=t; u!=s; u=e[p[u]].from) e[p[u]].cap-=f, e[p[u]^1].cap+=f;
				ret+=f;
			}
		}
		else {
			if(! (--gap[d[u]]) ) break;
			d[u]=n; cur[u]=ihead[u];
			for(i=ihead[u]; i; i=e[i].next) if(e[i].cap && d[u]>d[e[i].to]+1) d[u]=d[e[i].to]+1;
			++gap[d[u]];
			if(u!=s) u=e[p[u]].from;
		}
	}
	return ret;
}
inline const bool spfa(const int &s, const int &t) {
	for1(i, s, t) d[i]=1000000000, vis[i]=0;
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
	return d[t]!=1000000000;
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
	read(n); read(m); read(k);
	int s=1, t=n, u, v, c;
	for1(i, 1, m) {
		read(u); read(v); read(c); read(nd[i][2]);
		add(u, v, c, 0);
		nd[i][0]=u; nd[i][1]=v;
	}
	printf("%d ", isap(s, t, t));
	for1(i, 1, m) add(nd[i][0], nd[i][1], oo, nd[i][2]);
	s=0; add(s, 1, k, 0);
	print(mcf(s, t));
	return 0;
}
