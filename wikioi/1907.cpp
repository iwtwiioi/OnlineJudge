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

const int N=1000, M=N<<4, oo=~0u>>1;
struct ED { int u, v, next, cap; } e[M];
int n, m, cnt=1;
int d[N], gap[N], cur[N], p[N], ihead[N];
inline int id(const int &x, const int &y) { return (x-1)*m+y; }
inline void add(const int &u, const int &v, const int &c) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].v=v; e[cnt].u=u; e[cnt].cap=c;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].v=u; e[cnt].u=v; e[cnt].cap=0;
}
int isap(const int &s, const int &t, const int &n) {
	int ret=0, f, u, v, i;
	for1(i, 0, n) cur[i]=ihead[i];
	gap[0]=n; u=s;
	while(d[s]<n) {
		for(i=cur[u]; i; i=e[i].next) if(e[i].cap && d[u]==d[e[i].v]+1) break;
		if(i) {
			v=e[i].v; p[v]=cur[u]=i; u=v;
			if(u==t) {
				for(f=oo; u!=s; u=e[p[u]].u) f=min(f, e[p[u]].cap);
				for(u=t; u!=s; u=e[p[u]].u) e[p[u]].cap-=f, e[p[u]^1].cap+=f;
				ret+=f;
			}
		}
		else {
			if(! (--gap[d[u]]) ) break;
			d[u]=n;
			cur[u]=ihead[u];
			for(i=ihead[u]; i; i=e[i].next) if(e[i].cap && d[u]>d[e[i].v]+1) d[u]=d[e[i].v]+1;
			++gap[d[u]];
			if(u!=s) u=e[p[u]].u;
		}
	}
	return ret;
}
int main() {
	read(n); read(m);
	int ans=0, t, now, S=id(n, m)+1, T=id(n, m)+2;
	for1(i, 1, n) for1(j, 1, m) {
		read(t); ans+=t;
		now=id(i, j);
		if((i+j)%2) {
			add(S, now, t);
			if(j<m) add(now, id(i, j+1), oo);
			if(i<n) add(now, id(i+1, j), oo);
			if(j>1) add(now, id(i, j-1), oo);
			if(i>1) add(now, id(i-1, j), oo);
		}
		else add(now, T, t);
	}
	print(ans-isap(S, T, T));
	return 0;
}

