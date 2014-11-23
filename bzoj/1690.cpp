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
#define rdm(i, x) for(int i=ihead[x]; i; i=e[i].next)
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
const int N=1005;
int ihead[N], a[N], n, m, cnt, vis[N], flag;
double d[N];
struct ED { int to, next, t; double w; }e[5005];
void add(int u, int v, int w) { e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].t=w; }
void spfa(int x) {
	vis[x]=1;
	int v;
	rdm(i, x) if(d[v=e[i].to]>d[x]+e[i].w) {
		if(vis[v]) { flag=1; return; }
		d[v]=d[x]+e[i].w;
		spfa(v);
		if(flag) return;
	}
	vis[x]=0;
}
bool check(double L) {
	for1(i, 1, n) rdm(j, i) e[j].w=L*e[j].t-a[e[j].to];
	for1(i, 1, n) vis[i]=d[i]=0;
	flag=0;
	for1(i, 1, n) if(!vis[i]) { spfa(i); if(flag) return 1; }
	return 0;
}
int main() {
	read(n); read(m);
	for1(i, 1, n) read(a[i]);
	int u, v, w;
	rep(i, m) { read(u); read(v); read(w); add(u, v, w); }
	double L=0, R=10000, mid;
	while(R-L>0.001) {
		mid=(L+R)/2;
		if(check(mid)) L=mid; else R=mid;
	}
	printf("%.2lf", L);
	return 0;
}

