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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

#define mkpii(a, b) make_pair<int, int> (a, b)
const int N=305, oo=(~0u>>2)-10005;
typedef pair<int, int> pii;
int d[N][N], n, m, ihead[N], cnt, v[N], ans=oo, vis[N];
struct ED { int next, to, w; }e[N*N<<1];
priority_queue<pii, vector<pii>, greater<pii> > q;
void add(int u, int v, int w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].w=w;
}
void dij(int s, int *d) {
	for1(i, 1, n) d[i]=oo, vis[i]=0; int y;
	while(!q.empty()) q.pop();
	d[s]=0; q.push(mkpii(0, s));
	while(!q.empty()) {
		int x=q.top().second; q.pop();
		if(vis[x]) continue; vis[x]=1;
		for(int i=ihead[x]; i; i=e[i].next) if(d[y=e[i].to]>d[x]+e[i].w) {
			d[y]=d[x]+e[i].w;
			q.push(mkpii(d[y], y));
		}
	}
}
int main() {
	read(n); read(m);
	for1(i, 1, n) read(v[i]);
	for1(i, 1, m) {
		int u=getint(), v=getint(), w=getint();
		add(u, v, w);
	}
	for1(i, 1, n) dij(i, d[i]);
	read(m);
	while(m--) {
		int x=getint(), y=getint();
		ans=oo;
		for1(i, 1, n) ans=min(ans, d[i][x]+d[i][y]+v[i]);
		if(ans==oo) ans=-1;
		printf("%d\n", ans);
	}
	return 0;
}