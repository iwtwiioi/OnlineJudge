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

const int N=1005;
int ihead[N], inext[N], to[N], cnt, d[N], f[N], n, vis[N];
void dfs(const int &x, const int &t) {
	if(vis[x]) return;
	vis[x]=1;
	f[x]=t;
	for(int i=ihead[x]; i; i=inext[i]) dfs(to[i], t^d[i]);
}

int main() {
	read(n);
	int u, v, w;
	rep(i, n-1) {
		read(u); read(v); read(w);
		inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v; d[cnt]=w;
	}
	dfs(1, 0);
	print(f[n]);
	return 0;
}

