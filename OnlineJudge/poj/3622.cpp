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

const int N=215;
const double eps=1e-4;
int n, nn, x[N], y[N], vis[N], s[N], ihead[N], cnt, top;
struct ED { int to, next; }e[(N*N)<<1];
void add(int u, int v) { e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; }
bool dfs(int u) {
	if(vis[u]) return true;
	if(vis[u^1]) return false;
	vis[u]=true; s[++top]=u;
	for(int i=ihead[u]; i; i=e[i].next) if(!dfs(e[i].to)) return false;
	return true;
}
bool check(double r) {
	CC(ihead, 0); cnt=0; CC(vis, 0);
	double dis=(r*r)*4;
	for1(i, 2, nn) {
		int t; if(i&1) t=i+1; else t=i+2;
		for1(j, t, nn) {
			double x1=x[i], y1=y[i], x2=x[j], y2=y[j];
			double rg=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
			if(rg<dis) add(i, j^1), add(j, i^1);
		}
	}
	for(int i=2; i<nn; i+=2) if(!vis[i] && !vis[i+1]) {
		top=0;
		if(!dfs(i)) {
			while(top) vis[s[top--]]=0;
			if(!dfs(i+1)) return false;
		}
	}
	return true;
}

int main() {
	while(~scanf("%d", &n)) {
		for1(i, 1, n) rep(j, 2) read(x[(i<<1)+j]), read(y[(i<<1)+j]); nn=(n<<1)+1;
		double l=0, r=50000;
		while(r-l>eps) {
			double m=(l+r)/2;
			if(check(m)) l=m;
			else r=m;
		}
		printf("%.2lf\n", l);
	}
	return 0;
}