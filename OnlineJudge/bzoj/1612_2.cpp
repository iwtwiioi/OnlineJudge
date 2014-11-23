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
#define rdm(x) for(int i=ihead[x]; i; i=e[i].next)
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=105;
int win[N], los[N], ihead[N], cnt, n, m, vis[N];
struct ED { int to, next; }e[N*N];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
int dfs(int x) {
	++los[x];
	int s=0;
	vis[x]=1;
	rdm(x) if(!vis[e[i].to]) s+=dfs(e[i].to);
	return s+1;
}
int main() {
	read(n); read(m);
	int u, v;
	while(m--) {
		read(u); read(v);
		add(u, v);
	}
	int ans=0;
	for1(i, 1, n) { 
		CC(vis, 0); --los[i];
		win[i]=dfs(i)-1;
	}
	for1(i, 1, n)
		if(win[i]+los[i]==n-1) ++ans;
	print(ans);
	return 0;
}

