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

const int N=1000010;
int vis[N], q[N], front, tail, in[N], son[N], root[N], cnt, bak[N], n;
long long f[N][4], w[N], ans;
void dfs(const int &x) {
	vis[x]=x; int i;
	for(i=son[x]; !vis[i]; i=son[i]) vis[i]=x;
	if(vis[i]==x) {
		root[++cnt]=i; bak[son[i]]=1;
		--in[son[i]]; son[i]=0;
	}
}
void treedp() {
	int x, y;
	for1(i, 1, n) {
		f[i][1]=w[i];
		if(!bak[i]) f[i][3]=w[i];
	}
	for1(i, 1, n) if(!in[i]) q[tail++]=i;
	while(front!=tail) {
		x=q[front++]; if(front==N) front=0;
		y=son[x];
		if(!y) continue;
		f[y][0]+=max(f[x][1], f[x][0]);
		f[y][1]+=f[x][0];
		f[y][2]+=max(f[x][2], f[x][3]);
		if(!bak[y]) f[y][3]+=f[x][2];
		--in[y];
		if(!in[y]) { q[tail++]=y; if(tail==N) tail=0; }
	}
}

int main() {
	read(n);
	for1(i, 1, n) {
		read(w[i]); read(son[i]);
		++in[son[i]];
	}
	for1(i, 1, n) if(!vis[i]) dfs(i);
	treedp();
	for1(i, 1, cnt) ans+=max(f[root[i]][0], f[root[i]][3]);
	printf("%lld", ans);
	return 0;
}

