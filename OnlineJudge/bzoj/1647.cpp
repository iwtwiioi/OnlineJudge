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

const int N=20, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
int c[N][N], ans[N][N], n, m, tot, mn=~0u>>1;
bool a[N][N], b[N][N];

void rot(int x, int y) {
	b[x][y]=!b[x][y]; ++c[x][y];
	rep(i, 4) {
		int fx=dx[i]+x, fy=dy[i]+y;
		if(fx<1 || fy<1 || fx>n || fy>m) continue;
		b[fx][fy]=!b[fx][fy];
	}
}
void getans(int x) {
	CC(c, 0); tot=0;
	for1(i, 1, n) for1(j, 1, m) b[i][j]=a[i][j];
	for1(i, 0, m-1) if((1<<i)&x) { rot(1, i+1); ++tot; if(tot>=mn) return; }
	for1(i, 2, n) for1(j, 1, m) if(b[i-1][j]) { rot(i, j); ++tot; if(tot>=mn) return; }
	for1(i, 1, n) for1(j, 1, m) if(b[i][j]) return;
	mn=tot;
	for1(i, 1, n) for1(j, 1, m) ans[i][j]=c[i][j];
}

int main() {
	read(n); read(m);
	for1(i, 1, n) for1(j, 1, m) read(a[i][j]);
	int end=(1<<m)-1;
	for1(i, 0, end) getans(i);
	if(mn!=~0u>>1) for1(i, 1, n) { printf("%d", ans[i][1]); for1(j, 2, m) printf(" %d", ans[i][j]); puts(""); }
	else puts("IMPOSSIBLE");
	return 0;
}

