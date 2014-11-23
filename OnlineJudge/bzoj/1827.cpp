#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%lld", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const ll min(const ll &a, const ll &b) { return a<b?a:b; }

const int N=100005;
int ihead[N], cnt, n;
struct ED { int to, next; ll w; }e[N<<1];
ll d[N][2], ans=~0ull>>1, c[N], son[N][2];
void add(int u, int v, ll w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].w=w;
}
void dfs1(int x, int fa) {
	int y;
	for(int i=ihead[x]; i; i=e[i].next) if((y=e[i].to)!=fa) {
		ll w=e[i].w;
		dfs1(y, x);
		son[x][0]+=son[y][0]+c[y];
		d[x][0]+=d[y][0]+w*(son[y][0]+c[y]);
	}
}
void dfs2(int x, int fa) {
	int y;
	for(int i=ihead[x]; i; i=e[i].next) if((y=e[i].to)!=fa) {
		ll w=e[i].w;
		son[y][1]=son[x][1]+c[x]+son[x][0]-son[y][0]-c[y];
		d[y][1]=d[x][1]+w*son[y][1]+d[x][0]-d[y][0]-w*(son[y][0]+c[y]);
		dfs2(y, x);
	}
}
int main() {
	read(n);
	for1(i, 1, n) read(c[i]);
	rep(i, n-1) { int u=getint(), v=getint(), w=getint(); add(u, v, w); }
	dfs1(1, 0); dfs2(1, 0);
	for1(i, 1, n) ans=min(ans, d[i][0]+d[i][1]);
	print(ans);
	return 0;
}