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

const int N=1005, oo=~0u>>2;
int arr[N][N], sum[2][N][N], mx[N][N], n, m, a, b, ans=-oo;

int get(int x, int y, int k) {
	int ret=-oo, fx=x-(k*a)+k, fy=y-(k*b)+k, now=(k==1?0:1);
	if(fx>=1 && fy>=1 && fx<=n && fy<=m) ret=max(ret, sum[now][x][y]-sum[now][fx-k][y]-sum[now][x][fy-k]+sum[now][fx-k][fy-k]);
	fx=x-(k*b)+k, fy=y-(k*a)+k;
	if(fx>=1 && fy>=1 && fx<=n && fy<=m) ret=max(ret, sum[now][x][y]-sum[now][fx-k][y]-sum[now][x][fy-k]+sum[now][fx-k][fy-k]);
	return ret;
}
int main() {
	read(n); read(m); read(a); read(b);
	for1(i, 1, n) for1(j, 1, m) read(arr[i][j]);
	for1(i, 1, n) for1(j, 1, m) sum[0][i][j]=sum[0][i-1][j]+sum[0][i][j-1]-sum[0][i-1][j-1]+arr[i][j];
	for3(i, n, 1) for3(j, m, 1) sum[1][i][j]=sum[1][i+1][j]+sum[1][i][j+1]-sum[1][i+1][j+1]+arr[i][j];
	for3(i, n+1, 0) for3(j, m+1, 0) mx[i][j]=-oo;
	for3(i, n, 1) for3(j, m, 1) mx[i][j]=max(get(i, j, -1), max(mx[i][j+1], mx[i+1][j]));
	for1(i, 1, n) for1(j, 1, m) ans=max(ans, get(i, j, 1)+max(mx[i+1][1], mx[1][j+1]));
	if(ans==-oo) puts("Impossible");
	else print(ans);
	return 0;
}