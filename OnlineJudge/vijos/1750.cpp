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

#define lc x<<1
#define rc x<<1|1
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1

typedef long long ll;
const int N=1005, oo=0x7f7f7f7f;
struct dat { int x, y; ll d; }home[N*N], ans[N*N];
bool cmp(const dat &a, const dat &b) {
	if(a.d==b.d) {
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	}
	return a.d<b.d;
}
int mn[N<<2][N<<2], a[N][N], A, B, cnt, ct, nn, mm;
bool vis[N][N];
ll sum[N][N];

void pushup1(int x) { for1(i, 1, mm<<2) mn[x][i]=min(mn[lc][i], mn[rc][i]); }
void pushup2(int *s, int x) { s[x]=min(s[lc], s[rc]); }
void build2(int l, int r, int x, int *s, int row) {
	if(l==r) { s[x]=a[row][l]; return; }
	int m=MID;
	build2(lson, s, row); build2(rson, s, row);
	pushup2(s, x);
}
void build1(int l, int r, int x) {
	if(l==r) { build2(1, mm, 1, mn[x], l); return; }
	int m=MID;
	build1(lson); build1(rson);
	pushup1(x);
}
int query2(int l, int r, int x, int *s, int L, int R) {
	if(L<=l && r<=R) return s[x];
	int m=MID, ret=oo;
	if(L<=m) ret=min(ret, query2(lson, s, L, R));
	if(m<R) ret=min(ret, query2(rson, s, L, R));
	return ret;
}
int query1(int l, int r, int x, int L, int R, int LL, int RR) {
	if(L<=l && r<=R) return query2(1, mm, 1, mn[x], LL, RR);
	int m=MID, ret=oo;
	if(L<=m) ret=min(ret, query1(lson, L, R, LL ,RR));
	if(m<R) ret=min(ret, query1(rson, L, R, LL, RR));
	return ret;
}
ll ask(int x, int y) {
	int ret=query1(1, nn, 1, x, x+A-1, y, y+B-1); //printf("%d %d %d\n", x, y, ret);
	ll s=sum[x][y]-sum[x+A][y]-sum[x][y+B]+sum[x+A][y+B];
	return s-(ll)ret*(ll)A*(ll)B;
}
void dfs(int x, int y, int a, int b) {
	if(vis[x][y]) return;
	vis[x][y]=1;
	if(a<A) dfs(x+1, y, a+1, b);
	if(b<B) dfs(x, y+1, a, b+1);
}
void init() {
	CC(mn, 0x7f);
	read(nn); read(mm); read(A); read(B);
	for1(i, 1, nn) for1(j, 1, mm) read(a[i][j]);
	//for1(i, 1, nn) { for1(j, 1, mm) printf("%d\t", a[i][j]); puts(""); }
	for3(i, nn, 1) for3(j, mm, 1) sum[i][j]=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1]+a[i][j];
	build1(1, nn, 1);
	for1(i, 1, nn-A+1) for1(j, 1, mm-B+1) {
		home[++cnt].x=i;
		home[cnt].y=j;
		home[cnt].d=ask(i, j);
	}
}
int main() {
	init();
	sort(home+1, home+1+cnt, cmp);
	for1(i, 1, cnt) {
		int x=home[i].x, y=home[i].y;
		if(!vis[x][y] && !vis[x+A-1][y] && !vis[x][y+B-1] && !vis[x+A-1][y+B-1]) {
			ans[++ct]=home[i];
			dfs(x, y, 1, 1);
		}
	}
	printf("%d\n", ct);
	for1(i, 1, ct) printf("%d %d %lld\n", ans[i].x, ans[i].y, ans[i].d);
	return 0;
}