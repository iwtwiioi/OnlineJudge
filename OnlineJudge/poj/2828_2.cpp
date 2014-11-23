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
const int N=200005;
int n, sum[N*10], a[N], b[N], ans[N];
inline void pushup(const int &x) { sum[x]=sum[lc]+sum[rc]; }
void build(const int &l, const int &r, const int &x) {
	if(l==r) { sum[x]=1; return; }
	int m=MID;
	build(lson); build(rson);
	pushup(x);
}
void update(const int &l, const int &r, const int &x, const int &id, const int &s) {
	if(l==r) { ans[l]=id; sum[x]=0; return; }
	int m=MID;
	if(sum[lc]>=s) update(lson, id, s);
	else update(rson, id, s-sum[lc]);
	pushup(x);
}
int main() {
	while(~scanf("%d", &n)) {
		build(1, N, 1);
		rep(i, n) { read(a[i]); read(b[i]); }
		for3(i, n-1, 0) update(1, N, 1, b[i], a[i]+1);
		for1(i, 1, n) printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}

