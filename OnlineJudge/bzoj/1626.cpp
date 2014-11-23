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
struct ED { int u, v; double w; } e[N*N];
int n, m, x[N], y[N], vis[N][N], p[N], cnt;
void add(int u, int v, double w) { e[++cnt].u=u; e[cnt].v=v; e[cnt].w=w; }
const int ifind(int x) { return x==p[x]?x:p[x]=ifind(p[x]); }
bool cmp(const ED &a, const ED &b) { return a.w<b.w; }
int main() {
	read(n); read(m);
	int u, v;
	for1(i, 1, n) { read(x[i]); read(y[i]); }
	rep(i, m) { read(u); read(v); add(u, v, 0); vis[u][v]=vis[v][u]=1; }
	for2(i, 1, n) for1(j, i+1, n) if(!vis[i][j]) add(i, j, sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j])));
	sort(e+1, e+1+cnt, cmp);
	double ans=0;
	for1(i, 1, n) p[i]=i;
	for1(i, 1, cnt) {
		int fx=ifind(e[i].u), fy=ifind(e[i].v);
		if(fx!=fy) {
			p[fx]=fy;
			ans+=e[i].w;
		}
	}
	printf("%.2lf", ans);
	return 0;
}

