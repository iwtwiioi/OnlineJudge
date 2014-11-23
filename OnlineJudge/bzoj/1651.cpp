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
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1
struct nod { int mx, tag; }t[4000005];
int n;
void pushdown(int x) {
	int g=t[x].tag; t[x].tag=0;
	t[lc].mx+=g; t[lc].tag+=g;
	t[rc].mx+=g; t[rc].tag+=g;
}
void pushup(int x) { t[x].mx=max(t[lc].mx, t[rc].mx); }
void update(int l, int r, int x, int L, int R) {
	if(L<=l && r<=R) { ++t[x].mx; ++t[x].tag; return; }
	pushdown(x);
	int m=MID;
	if(L<=m) update(lson, L, R); if(m<R) update(rson, L, R);
	pushup(x);
}
int main() {
	read(n);
	for1(i, 1, n) {
		int l=getint(), r=getint();
		update(1, 1000000, 1, l, r);
	}
	print(t[1].mx);
	return 0;
}

