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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=10005;
int sz[N], ihead[N], vis[N], mark[N], n, cnt;
struct ED { int to, next; }e[N+N];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
void dfs(int x) {
	sz[x]=vis[x]=1;
	int v, mx=0;
	for(int i=ihead[x]; i; i=e[i].next) if(!vis[v=e[i].to]) {
		dfs(v);
		sz[x]+=sz[v];
		mx=max(sz[v], mx);
	}
	mx=max(mx, n-sz[x]);
	if(mx<=(n>>1)) mark[x]=1;
}

int main() {
	read(n);
	for1(i, 1, n-1) add(getint(), getint());
	dfs((n+1)>>1);
	for1(i, 1, n) if(mark[i]) printf("%d\n", i);
	return 0;
}