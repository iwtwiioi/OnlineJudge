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

const int N=705, dx[]={1,1,1,0,0,-1,-1,-1}, dy[]={1,0,-1,1,-1,1,0,-1};  
int vis[N][N], h[N][N], ans, cnt, n, m;
struct dat{ int x, y, h; } mp[N*N];
bool cmp(const dat &a, const dat &b) { return a.h>b.h; }
void dfs(int x, int y) {
	vis[x][y]=1;
	rep(i, 8) {
		int fx=dx[i]+x, fy=dy[i]+y;
		if(fx<1 || fy<1 || fx>n || fy>m || vis[fx][fy] || h[fx][fy]>h[x][y]) continue;
		dfs(fx, fy);
	}
}
int main() {
	read(n); read(m);
	for1(i, 1, n) for1(j, 1, m) read(h[i][j]), mp[++cnt].h=h[i][j], mp[cnt].x=i, mp[cnt].y=j;
	sort(mp+1, mp+1+cnt, cmp);
	for1(i, 1, cnt) {
		int x=mp[i].x, y=mp[i].y;
		if(!vis[x][y]) { dfs(x, y); ++ans; }
	}
	print(ans);
	return 0;
}

