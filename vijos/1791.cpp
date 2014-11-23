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

const int N=40, dx[]={-1, -2, -2, -1, 1, 2, 2, 1}, dy[]={-2, -1, 1, 2, 2, 1, -1, -2};
int vis[2][N][N], n, T, X, Y, cnt, a[N][N];
int main() {
	read(n); read(T); read(X); read(Y);
	for1(i, 1, n) for1(j, 1, n) read(a[i][j]);
	CC(vis, -1);
	vis[0][X][Y]=0; int flag=0;
	for1(t, 1, T) {
		for1(i, 1, n) for1(j, 1, n) if(t%a[i][j]==0) {
			rep(k, 8) {
				int fx=dx[k]+i, fy=dy[k]+j;
				if(fx<1 || fy<1 || fx>n || fy>n || vis[flag][fx][fy]!=t-1) continue;
				vis[!flag][i][j]=t;
				break;
			}
		}
		flag=!flag;
	}
	for1(i, 1, n) for1(j, 1, n) if(vis[flag][i][j]==T) ++cnt;
	printf("%d\n", cnt);
	for1(i, 1, n) for1(j, 1, n) if(vis[flag][i][j]==T) printf("%d %d\n", i, j);
	return 0;
}