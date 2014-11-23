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

const int N=35;
typedef int mtx[N][N];
int gauss(mtx A, int n) {
	int x=1, y=1;
	while(x<=n && y<=n) {
		int pos=x;
		while(!A[pos][y] && pos<=n) ++pos;
		if(A[pos][y]) {
			for1(i, 1, n+1) swap(A[pos][i], A[x][i]);
			for1(i, x+1, n) if(A[i][y])
				for1(j, y, n+1) A[i][j]^=A[x][j];
			++x;
		}
		++y;
	}
	for1(i, x, n) if(A[i][n+1]) return -1;
	return n-x+1;
}
int main() {
	int cs=getint();
	mtx a;
	while(cs--) {
		CC(a, 0);
		int n=getint();
		for1(i, 1, n) read(a[i][n+1]), a[i][i]=1;
		for1(i, 1, n) a[i][n+1]^=getint();
		int x=getint(), y=getint();
		while(x+y) {
			a[y][x]=1;
			x=getint(), y=getint();
		}
		int ans=gauss(a, n);
		if(ans==-1) puts("Oh,it's impossible~!!");
		else printf("%d\n", 1<<ans);
	}
	return 0;
}