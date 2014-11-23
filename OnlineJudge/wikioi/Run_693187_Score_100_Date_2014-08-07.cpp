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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
#define debug(x) printf("debug: %d\n", x)
#define printarr(a, x) { for1(i, 0, x) printf("%d ", a[i]); printf("\n"); }
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret*k; }

const int N=305;
int ihead[N], inext[N*N], to[N*N], fa[N], d[N], cnt, n, m, ans=~0u>>1;
bool die[N], vis[N];

inline void add(int u, int v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; to[cnt]=u;
}

void build(const int &x) {
	if(vis[x]) return; vis[x]=true;
	for(int i=ihead[x]; i; i=inext[i]) if(!vis[to[i]]) {
		fa[to[i]]=x; d[to[i]]=d[x]+1;
		build(to[i]);
	}
}

void dfs(const int &dis, int num) {
	if(num>=ans) return;
	bool flag=1;
	for1(u, 1, n) if(d[u]==dis && die[u])
		for(int i=ihead[u]; i; i=inext[i])
			if(fa[to[i]]==u) flag=0, die[to[i]]=1, ++num;
	--num;
	for1(u, 1, n) if(d[u]==dis+1 && die[u]) die[u]=0, dfs(dis+1, num), die[u]=1;
	++num;
	for1(u, 1, n) if(d[u]==dis && die[u])
		for(int i=ihead[u]; i; i=inext[i])
			if(fa[to[i]]==u) die[to[i]]=0, --num;
	if(flag && ans>num) ans=num;
}

int main() {
	read(n); read(m);
	rep(i, m) add(getnum(), getnum());
	die[1]=true; d[1]=1;
	build(1);
	dfs(1, 1);
	print(ans);
	return 0;
}
