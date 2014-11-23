#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
inline int getnum() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
const int N=60;
const int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
struct ED { int x, y, w; }e[N*N*N];
int n, m, a[N][N], d[N][N], ans, sum, cnt, p[N];
inline const bool cmp(const ED &a, const ED &b) { return a.w<b.w; }
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }

void dfs1(const int &x, const int &y) {
	int fx, fy;
	d[x][y]=ans;
	rep(i, 4) {
		fx=x+dx[i]; fy=y+dy[i];
		if(fx<1 || fx>n || fy<1 || fy>m || d[fx][fy] || !a[fx][fy]) continue;
		dfs1(fx, fy);
	}
}
void work1() {
	for1(i, 1, n) for1(j, 1, m) if(a[i][j] && !d[i][j]) { ++ans; dfs1(i, j); }
	printf("%d\n", ans);
}
inline const bool insert(const int &fx, const int &fy, const int &x, const int &y, const int &w) {
	if(x<1 || x>n || y<1 || y>m || !d[x][y]) return 1;
	if(d[x][y]==d[fx][fy]) return 0;
	e[++cnt].x=d[fx][fy]; e[cnt].y=d[x][y];
	e[cnt].w=w-1;
	return 1;
}
void build(const int &x, const int &y) {
	for1(i, x+1, n) if(!insert(x, y, i, y, i-x) || !insert(x, y, i, y+1, i-x) || !insert(x, y, i, y-1, i-x)) break;
	for3(i, x-1, 1) if(!insert(x, y, i, y, x-i) || !insert(x, y, i, y+1, x-i) || !insert(x, y, i, y-1, x-i)) break;
	for1(i, y+1, m) if(!insert(x, y, x, i, i-y) || !insert(x, y, x+1, i, i-y) || !insert(x, y, x-1, i, i-y)) break;
	for3(i, y-1, 1) if(!insert(x, y, x, i, y-i) || !insert(x, y, x+1, i, y-i) || !insert(x, y, x-1, i, y-i)) break;
}
void work2() {
	for1(i, 1, n) for1(j, 1, m) if(a[i][j]) build(i, j);
	sort(e+1, e+1+cnt, cmp);
	for1(i, 1, ans) p[i]=i;
	sum=ans=0; int fx, fy;
	for1(i, 1, cnt) {
		fx=ifind(e[i].x); fy=ifind(e[i].y);
		if(fx!=fy) {
			p[fx]=fy;
			++ans;
			sum+=e[i].w;
		}
	}
	printf("%d %d\n", ans, sum);
}

int main() {
	read(n); read(m); char c;
	for1(i, 1, n) for1(j, 1, m) {
		for(c=getchar(); c!='#'&&c!='.'; c=getchar());
		if(c=='#') a[i][j]=1;
	}
	work1();
	work2();
	return 0;
}

