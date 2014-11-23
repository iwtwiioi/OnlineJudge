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
#define lc x<<1
#define rc x<<1|1
#define MID (l+r)>>1
#define lson l, m, lc
#define rson m+1, r, rc

const int N=10005, oo=~0u>>1;
int n, st, en;
int ans;
struct dat { int x, y, w; }a[N];
struct node { int mn; }t[500005];
const bool cmp(const dat &x, const dat &y) { return x.x<y.x; }
void pushup(int x) { t[x].mn=min(t[lc].mn, t[rc].mn); }
void build(int l, int r, int x) {
	t[x].mn=oo;
	if(l==r) return;
	int m=MID;
	build(lson); build(rson);
}
void update(int l, int r, int x, const int &key, const int &R) {
	if(l==r) {
		t[x].mn=min(key, t[x].mn);
		return;
	}
	int m=MID;
	if(R<=m) update(lson, key, R); else update(rson, key, R);
	pushup(x);
}
int query(int l, int r, int x, const int &L, const int &R) {
	if(L<=l && r<=R) return t[x].mn;
	int m=MID; int mn=oo;
	if(L<=m) mn=min(mn, query(lson, L, R)); if(m<R) mn=min(mn, query(rson, L, R));
	return mn;
}
int main() {
	read(n); read(st); read(en);
	for1(i, 1, n) read(a[i].x), read(a[i].y), read(a[i].w);
	sort(a+1, a+1+n, cmp);
	build(st, en, 1);
	for1(i, 1, n) {
		if(a[i].x<=st) ans=0; else ans=query(st, en, 1, a[i].x-1, a[i].y);
		if(ans!=oo) update(st, en, 1, ans+a[i].w, a[i].y);
	}
	ans=query(st, en, 1, en, en);
	if(ans==oo) puts("-1");
	else printf("%d", ans);
	return 0;
}

