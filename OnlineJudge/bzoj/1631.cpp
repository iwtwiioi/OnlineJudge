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

const int N=1005, M=100005, oo=~0u>>2;
int ihead[N], n, m, d[N], T, cnt, d1[N], X[M], Y[M], W[M];
struct ED { int to, next, w; }e[M];
struct ND { int id; const bool operator<(const ND &b) const { return d[id]>d[b.id]; } };
priority_queue<ND> q;
void add(int u, int v, int w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}
void dij(int s) {
	for1(i, 0, n) d[i]=oo;
	d[s]=0;
	ND t={s};
	int u, v;
	q.push(t);
	while(q.size()) {
		u=q.top().id; q.pop();
		for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+e[i].w) {
			d[v]=d[u]+e[i].w;
			t.id=v;
			q.push(t);
		}
	}
}

int main() {
	read(n); read(m); read(T);
	int u, v, w;
	rep(i, m) {
		read(u); read(v); read(w);
		X[i]=u; Y[i]=v; W[i]=w;
		add(v, u, w);
	}
	int mx=0;
	dij(T);
	for1(i, 1, n) d1[i]=d[i];
	cnt=0; CC(ihead, 0);
	rep(i, m) add(X[i], Y[i], W[i]);
	dij(T);
	for1(i, 1, n) {
		mx=max(mx, d1[i]+d[i]);
	}
	print(mx);
	return 0;

}

