#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mkpii make_pair<int, int>
#define pdi pair<double, int>
#define mkpdi make_pair<double, int>
#define pli pair<ll, int>
#define mkpli make_pair<ll, int>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=155, MD=12345678;
int d[N][N][25][25], n, m, k;
inline void add(int &a, const int &b) { a=(a+b)%MD; }
int main() {
	read(n); read(m); read(k);
	d[0][0][0][0]=1;
	for1(x, 0, n) for1(y, 0, m) for1(k1, 0, k) for1(k2, 0, k) {
		if(k1+1<=k) add(d[x+1][y][k1+1][max(k2-1, 0)], d[x][y][k1][k2]);
		if(k2+1<=k) add(d[x][y+1][max(k1-1, 0)][k2+1], d[x][y][k1][k2]);
	}
	int ans=0;
	for1(x, 0, k) for1(y, 0, k) add(ans, d[n][m][x][y]);
	print(ans);
	return 0;
}