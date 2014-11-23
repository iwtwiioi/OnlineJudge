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

const int N=10005, M=1005;
struct dat { int x, w, f, c; } a[N];
inline const bool cmp(const dat &a, const dat &b) { return a.x<b.x; }
int f[M][M], n, l, m;
int main() {
	read(l); read(n); read(m);
	for1(i, 1, n) read(a[i].x), read(a[i].w), read(a[i].f), read(a[i].c);
	sort(a+1, a+1+n, cmp);
	int ans=-1;
	CC(f, -1); f[0][0]=0;
	for1(i, 1, n) {
		int x=a[i].x, c=a[i].c, e=x+a[i].w, ff=a[i].f;
		for1(j, c, m) if(f[j-c][x]!=-1) f[j][e]=max(f[j][e], f[j-c][x]+ff);
	}
	for1(i, 1, m) ans=max(f[i][l], ans);
	print(ans);
	return 0;
}

