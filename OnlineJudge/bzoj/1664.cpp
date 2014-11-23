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
const int N=10005;
int mx[N<<8], mxi, n;
struct dat { int a, b; }a[N];
bool cmp(const dat &a, const dat &b) { return a.a<b.a; }
void pushup(int x) { mx[x]=max(mx[lc], mx[rc]); }
void update(int l, int r, int x, int key, int p) {
	if(l==r) {
		mx[x]=key;
		return;
	}
	int m=MID;
	if(p<=m) update(lson, key, p); else update(rson, key, p);
	pushup(x);
}
int query(int l, int r, int x, int L, int R) {
	if(L<=l && r<=R) return mx[x];
	int m=MID, ret=0;
	if(L<=m) ret=query(lson, L, R); if(m<R) ret=max(ret, query(rson, L, R));
	return ret;
}

int main() {
	read(n);
	for1(i, 1, n) read(a[i].a), read(a[i].b), mxi=max(a[i].a+a[i].b, mxi);
	sort(a+1, a+1+n, cmp);
	int ans;
	for1(i, 1, n) {
		if(a[i].a<=1) ans=0; else ans=query(1, mxi, 1, 1, a[i].a-1);
		update(1, mxi, 1, ans+1, a[i].a+a[i].b-1);
	}
	print(query(1, mxi, 1, 1, mxi));
	return 0;
}

