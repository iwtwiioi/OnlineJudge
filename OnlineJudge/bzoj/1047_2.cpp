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

const int N=1005, oo=~0u>>1;
int a[N][N], n, m, s;
int mm[2][N][N], nd[2][N][N], num[2][N][N], num1[2][N][N], ans=oo;

//0:min 1:max
inline int check(const int &a, const int &b, const int &flag) { if(flag) return max(a,b); return min(a,b); }
inline void upd1(int *c, int *b, int x, const int &k, const int &flag) {
	b[x]=check(b[x], k, flag);
	for(; x<=m; x+=x&-x) c[x]=check(c[x], k, flag);
}
inline void upd(int x, const int &y, const int &k) {
	upd1(nd[0][x], num1[0][x], y, k, 0);
	upd1(nd[1][x], num1[1][x], y, k, 1);
	for(; x<=n; x+=x&-x) 
		upd1(mm[0][x], num[0][x], y, k, 0),
		upd1(mm[1][x], num[1][x], y, k, 1);
}
inline int get1(int *c, int *b, int l, int r, const int &flag) {
	int ret=-oo;
	if(!flag) ret=oo;
	while(l<=r) {
		if(r-l+1>=(r&-r)) {
			ret=check(ret, c[r], flag);
			r-=r&-r;
		}
		else {
			ret=check(ret, b[r], flag);
			--r;
		}
	}
	return ret;
}
inline int get(int l, int r, const int &y1, const int &y2, const int &flag) {
	int ret=-oo;
	if(!flag) ret=oo;
	while(l<=r) {
		if(r-l+1>=(r&-r)) {
			ret=check(ret, get1(mm[flag][r], num[flag][r], y1, y2, flag), flag);
			r-=r&-r;
		}
		else {
			ret=check(ret, get1(nd[flag][r], num1[flag][r], y1, y2, flag), flag);
			--r;
		}
	}
	return ret;
}
void work() {
	for1(i, 1, n) for1(j, 1, m) mm[0][i][j]=oo, num[0][i][j]=oo;
	for1(i, 1, n) for1(j, 1, m) mm[1][i][j]=-oo, num[1][i][j]=-oo;
	for1(i, 1, n) for1(j, 1, m) nd[0][i][j]=oo, num1[0][i][j]=oo;
	for1(i, 1, n) for1(j, 1, m) nd[1][i][j]=-oo, num1[1][i][j]=-oo;
	for1(i, 1, n) for1(j, 1, m) upd(i, j, a[i][j]);
	int mx, mn;
	//dbg(get(4, 4, 1, 2, 0));
	for1(i, s, n) for1(j, s, m) {
		mx=get(i-s+1, i, j-s+1, j, 1);
		mn=get(i-s+1, i, j-s+1, j, 0);
		//printf("%d %d: %d\t%d\n", i, j, mx, mn);
		if(mx!=-oo && mn!=oo) ans=min(ans, mx-mn);
	}
}

int main() {
	read(n); read(m); read(s);
	for1(i, 1, n) for1(j, 1, m) read(a[i][j]);
	work();
	print(ans);
	return 0;
}