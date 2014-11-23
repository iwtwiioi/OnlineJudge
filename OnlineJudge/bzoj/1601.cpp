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

const int N=500;
int p[N], cnt, n;
struct ED { int u, v, w; } e[N*N+N];
const bool cmp(const ED &a, const ED &b) { return a.w<b.w; }
void add(const int &u, const int &v, const int &w) {
	e[++cnt].u=u; e[cnt].v=v; e[cnt].w=w;
}
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
int main() {
	read(n);
	for1(i, 1, n)  add(0, i, getint());
	int fx, fy, ans=0;
	for1(i, 1, n) for1(j, 1, n)  {
		read(fx);
		if(i!=j) add(i, j, fx);
	}
	sort(e+1, e+1+cnt, cmp);
	for1(i, 1, n) p[i]=i;
	for1(i, 1, cnt) {
		fx=ifind(e[i].u); fy=ifind(e[i].v);
		if(fx!=fy) {
			p[fx]=fy;
			ans+=e[i].w;
		}
	}
	print(ans);
	return 0;
}

