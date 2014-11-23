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

const int N=5010, M=2000000, oo=~0u>>1, s=5000, t=s+1;
int ihead[N], cnt=1, d[N], p[N], cur[N], gap[N], n, m, k, S[25], H[25], a[25][30];
struct ED { int from, to, cap, w, next; } e[M];
inline void add(const int &u, const int &v, const int &c) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].from=u; e[cnt].cap=c;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].from=v; e[cnt].cap=0;
}
inline void update(const int &T) {
	for1(i, 0, n+1) add(i+(T-1)*22, i+T*22, oo);
	int u, v;
	for1(i, 1, m) {
		u=(T-1)*22+a[i][(T-1)%S[i]];
		v=T*22+a[i][T%S[i]];
		add(u, v, H[i]);
	}
}
int isap(const int &s, const int &t, const int &n) {
	for1(i, 0, t) cur[i]=ihead[i];
	CC(d, 0); CC(gap, 0);
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
int main() {
	read(n); read(m); read(k);
	for1(i, 1, m) {
		read(H[i]); read(S[i]);
		rep(j, S[i]) {
			read(a[i][j]);
			if(a[i][j]==-1) a[i][j]=n+1;
		}
	}
	for1(i, 0, 100) add(s, i*22, oo), add((n+1)+i*22, t, oo);
	for1(i, 1, 100) {
		update(i);
		k-=isap(s, t, t);
		if(k<=0) { print(i); return 0; }
	}
	print(0);
	return 0;
}
