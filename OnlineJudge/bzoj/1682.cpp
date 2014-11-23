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

const int N=2005, M=10005;
struct EDGE { int x, y, w; }e[M];
int p[N], n, m;
bool cmp(const EDGE &a, const EDGE &b) { return a.w<b.w; }
int ifind(int x) { return x==p[x]?x:p[x]=ifind(p[x]); }
int main() {
	read(n); read(m);
	for1(i, 1, m) e[i].x=getint(), e[i].y=getint(), e[i].w=getint();
	for1(i, 1, n) p[i]=i;
	sort(e+1, e+1+m, cmp);
	int ans=0;
	for1(i, 1, m) {
		int fx=ifind(e[i].x), fy=ifind(e[i].y);
		if(fx!=fy) {
			p[fx]=fy;
			ans=max(ans, e[i].w);
		}
	}
	print(ans);
	return 0;
}

