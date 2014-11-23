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

const int N=5005, M=50005;
int n, m, ihead[N], cnt, in[N], f1[N], f2[N], a[M], b[M];
struct ED { int to, next; }e[M];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
void dfs1(int x) {
	if(ihead[x]==0) f1[x]=1;
	for(int i=ihead[x]; i; i=e[i].next) {
		if(!f1[e[i].to]) dfs1(e[i].to);
		f1[x]+=f1[e[i].to];
	}
}
void dfs2(int x) {
	if(ihead[x]==0) f2[x]=1;
	for(int i=ihead[x]; i; i=e[i].next) {
		if(!f2[e[i].to]) dfs2(e[i].to);
		f2[x]+=f2[e[i].to];
	}
}
int main() {
	read(n); read(m);
	for1(i, 1, m) {
		int u=getint(), v=getint();
		a[i]=u, b[i]=v;
		add(u, v);
		in[v]=1;
	}
	for1(i, 1, n) if(!in[i]) dfs1(i);
	CC(ihead, 0); cnt=0;
	for1(i, 1, m) add(b[i], a[i]);
	dfs2(n);
	int ans=0;
	for1(i, 1, m) 
		ans=max(ans, f1[b[i]]*f2[a[i]]);
	print(ans);
	return 0;
}

