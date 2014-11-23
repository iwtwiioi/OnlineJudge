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

const int N=505;
int ihead[N], mn[N][N], cnt, FF[N], LL[N], vis[N], tot, q[N], top, p[N], scc, n;
struct ED { int to, next; }e[N*N<<1];
void add(int u, int v) { 
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; 
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; 
}
void tarjan(int u) {
	int v;
	FF[u]=LL[u]=++tot; q[++top]=u; vis[u]=1;
	for(int i=ihead[u]; i; i=e[i].next) {
		v=e[i].to;
		if(!FF[v]) tarjan(v), LL[u]=min(LL[u], LL[v]);
		else if(vis[v]) LL[u]=min(LL[u], FF[v]);
	}
	if(FF[u]==LL[u]) {
		++scc;
		do {
			v=q[top--];
			p[v]=scc;
			vis[v]=0;
		} while(u!=v);
	}
}

int main() {
	read(n);
	for1(i, 1, n) {
		int u=getint(), v=getint();
		add(u, v);
	}
	for1(i, 1, n) if(!FF[i]) tarjan(i);
	CC(mn, 0x3f);
	for1(i, 1, n) for1(j, 1, n) {
		int t=getint(), u=p[i], v=p[j];
		if(u!=v && mn[u][v]>t) mn[u][v]=t;
	}
	int ans=~0u>>1;
	for1(i, 1, scc) {
		int t=0;
		for1(j, 1, scc) if(i!=j)
			t+=mn[i][j];
		ans=min(t, ans);
	}
	print(ans<<1);
	return 0;
}