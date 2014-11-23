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

const int N=1005, C=105;
int c, cow[C], n, ihead[N], cnt, m;
bool vis[C][N];
struct ED { int to, next; }e[10005];
void add(int u, int v) { e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; }
void dfs(bool *v, int x) {
	v[x]=1;
	for(int i=ihead[x]; i; i=e[i].next) if(!v[e[i].to]) dfs(v, e[i].to);
}

int main() {
	read(c); read(n); read(m);
	for1(i, 1, c) read(cow[i]);
	while(m--) { int u=getint(), v=getint(); add(u, v); }
	for1(i, 1, c) dfs(vis[i], cow[i]);
	int ans=0;
	for1(i, 1, n) {
		bool v=1;
		for1(j, 1, c) v=v&&vis[j][i];
		if(v) ++ans;
	}
	print(ans);
	return 0;
}

