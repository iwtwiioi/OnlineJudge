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
#define print(a) printf("%lld", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
typedef long long ll;
#define lc x<<1
#define rc x<<1|1
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1
const int N=40005;
int n, b[N+N];
ll ans;
struct dat { int x, y, h; }a[N];
struct nod { int h, flg; }t[N<<4];
void pushup(int x) { t[x].h=max(t[lc].h, t[rc].h); }
void pushdown(int x) {
	if(t[x].flg) {
		int flg=t[x].flg;
		t[x].flg=0;
		t[lc].flg=max(t[lc].flg, flg); t[lc].h=max(t[lc].h, flg);
		t[rc].flg=max(t[rc].flg, flg); t[rc].h=max(t[rc].h, flg);
	}
}
void update(int l, int r, int x, int L, int R, int fix) {
	pushdown(x);
	if(L<=l && r<=R) {
		t[x].flg=fix;
		t[x].h=max(t[x].h, fix);
		return;
	}
	int m=MID;
	if(L<=m) update(lson, L, R, fix); if(m<R) update(rson, L, R, fix);
	pushup(x);
}
int query(int l, int r, int x, int L) {
	pushdown(x);
	if(l==r) return t[x].h;
	int m=MID;
	if(L<=m) return query(lson, L); 
	else return query(rson, L);
}
int main() {
	read(n);
	for1(i, 1, n) read(a[i].x), read(a[i].y), read(a[i].h), b[i<<1]=a[i].x, b[(i<<1)-1]=a[i].y;
	int sz=n<<1;
	sort(b+1, b+1+sz);
	for1(i, 1, n) a[i].x=lower_bound(b+1, b+1+sz, a[i].x)-b, a[i].y=lower_bound(b+1, b+1+sz, a[i].y)-b;
	for1(i, 1, n)
		update(1, sz, 1, a[i].x, a[i].y-1, a[i].h);
	for1(i, 1, sz-1)
		ans+=(ll)query(1, sz, 1, i)*(ll)(b[i+1]-b[i]);
	print(ans);
	return 0;
}

