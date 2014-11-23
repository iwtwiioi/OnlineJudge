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

const int N=1005;
int f[N][N], n, ans;
struct dat { int x, w; }a[N];
bool cmp(const dat &a, const dat &b) { return a.x<b.x; }

int main() {
	read(n);
	for1(i, 1, n) read(a[i].x), read(a[i].w);
	sort(a+1, a+1+n, cmp);
	for1(i, 1, n) for1(j, 0, i-1) {
		f[i][j]=f[j][0];
		for1(k, 1, j-1) if(a[i].x-a[j].x>=a[j].x-a[k].x)
			f[i][j]=max(f[i][j], f[j][k]);
		f[i][j]+=a[i].w;
		ans=max(f[i][j], ans);
	}
	CC(f, 0);
	for3(i, n, 1) for1(j, i+1, n+1) {
		f[i][j]=f[j][n+1];
		for1(k, j+1, n) if(a[i].x-a[j].x<=a[j].x-a[k].x)
			f[i][j]=max(f[i][j], f[j][k]);
		f[i][j]+=a[i].w;
		ans=max(f[i][j], ans);
	}
	print(ans);
	return 0;
}