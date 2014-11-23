#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
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

const int N=1005*1005/2, oo=~0u>>2;
int ihead[N], len, cnt, d[N], vis[N], w[N];
struct dat { int to, next; }e[N<<2];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
priority_queue<pii, vector<pii>, greater<pii> >q;
inline int id(int i, int j) { return ((i-1)+1)*(i-1)/2+j; }
void dij() {
	int n=id(len, len);
	for1(i, 1, n) d[i]=oo;
	d[1]=0; q.push(mkpii(0, 1));
	while(!q.empty()) {
		int u=q.top().second, v; q.pop(); if(vis[u]) continue; vis[u]=1;
		for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+w[u]) {
			d[v]=d[u]+w[u];
			q.push(mkpii(d[v], v));
		}
	}
}

int main() {
	read(len);
	for1(i, 1, len) {
		for1(j, 1, i) {
			int now=id(i, j);
			read(w[now]);
			if(i<len) add(now, id(i+1, j)), add(now, id(i+1, j+1));
			if(i>1 && i<len && j==1) add(now, id(i+1, i+1));
			if(i>1 && i<len && j==i) add(now, id(i+1, 1));
			int l=j-1; if(l<1) l=i;
			int r=j+1; if(r>i) r=1;
			if(i!=1) add(now, id(i, l)), add(now, id(i, r));
		}
	}
	dij();
	printf("%d\n", d[id(len, 1)]+w[id(len, 1)]);
	return 0;
}