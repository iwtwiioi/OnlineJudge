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

const int N=100005;
int ihead[N], cnt, n, m, l, k, FF[N], LL[N], ed[N], dep[N], tot, TM, X[N], Y[N], vis[N], a[N], b[N];
struct ED { int to, next, id; }e[N<<1];
void add(int u, int v, int id) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].id=id;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].id=id;
}
void tarjan(int x, int fa) {
	FF[x]=LL[x]=++TM;
	int y;
	for(int i=ihead[x]; i; i=e[i].next) {
		y=e[i].to;
		if(!FF[y]) {
			tarjan(y, x);
			if(LL[y]>FF[x]) ed[++tot]=e[i].id;
			LL[x]=min(LL[x], LL[y]);
		}
		else if(FF[y]<FF[x] && y!=fa) LL[x]=min(LL[x], FF[y]);
	}
}
void dfs(int x, int fa) {
	dep[x]=dep[fa]+1;
	vis[x]=1;
	for(int i=ihead[x]; i; i=e[i].next) if(!vis[e[i].to]) {
		dfs(e[i].to, x);
		a[x]+=a[e[i].to];
		b[x]+=b[e[i].to];
	}
}
int main() {
	read(n); read(m); read(k); read(l);
	for1(i, 1, k) a[getint()]=1;
	for1(i, 1, l) b[getint()]=1;
	for1(i, 1, m) {
		read(X[i]); read(Y[i]);
		add(X[i], Y[i], i);
	}
	for1(i, 1, n) if(!FF[i]) tarjan(i, 0);
	dfs((n+1)>>1, 0); CC(vis, 0);
	sort(ed+1, ed+1+tot); ed[tot+1]=-1; int num=0;
	for1(i, 1, tot) if(ed[i]!=ed[i+1]) ed[++num]=ed[i]; tot=num;
	int ans=0;
	for1(i, 1, tot) {
		int x=X[ed[i]], y=Y[ed[i]];
		if(dep[y]<dep[x]) swap(x, y);
		if(a[y]==0 || a[y]==k || b[y]==0 || b[y]==l) vis[i]=1, ++ans;
	}
	printf("%d\n", ans);
	for1(i, 1, tot) if(vis[i]) printf("%d\n", ed[i]);
	return 0;
}