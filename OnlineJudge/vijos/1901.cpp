#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mkpii make_pair<int, int>
#define pdi pair<double, int>
#define mkpdi make_pair<double, int>
#define pli pair<ll, int>
#define mkpli make_pair<ll, int>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const ll max(const ll &a, const ll &b) { return a>b?a:b; }
inline const ll min(const ll &a, const ll &b) { return a<b?a:b; }

#define lc x<<1
#define rc x<<1|1
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1

const int N=100005;
const ll oo=~0ull>>1;
int n, num, arr[N<<1], m;
ll mn[N<<5];
struct dat { int l, r; ll t; }a[N];
bool cmp(const dat &a, const dat &b) { return a.r==b.r?a.l<b.l:a.r<b.r; }
inline int ifind(int x) { return lower_bound(arr+1, arr+1+num, x)-arr; }

void build(int l, int r, int x) {
	mn[x]=oo;
	if(l==r) return;
	int m=MID;
	build(lson); build(rson);
}
void upd(int l, int r, int x, int p, ll s) {
	if(l==r) { mn[x]=min(s, mn[x]); return; }
	int m=MID;
	if(p<=m) upd(lson, p, s); else upd(rson, p, s);
	mn[x]=min(mn[lc], mn[rc]);
}
ll ask(int l, int r, int x, int L, int R) {
	if(L<=l && r<=R) return mn[x];
	int m=MID; ll ret=oo;
	if(L<=m) ret=min(ret, ask(lson, L, R)); if(m<R) ret=min(ret, ask(rson, L, R));
	return ret;
}

int main() {
	int T=getint();
	for1(tt, 1, T) {
		read(n); read(m); num=0; arr[++num]=1; arr[++num]=m;
		for1(i, 1, n) read(a[i].r), read(a[i].l), read(a[i].t), arr[++num]=a[i].l, arr[++num]=a[i].r;
		sort(arr+1, arr+1+num);
		num=unique(arr+1, arr+1+num)-arr;
		build(1, num, 1);
		upd(1, num, 1, ifind(1), 0);
		sort(a+1, a+1+n, cmp);
		for1(i, 1, n) {
			int posl=ifind(a[i].l), posr=ifind(a[i].r);
			ll f=ask(1, num, 1, posl, num);
			if(f<oo) upd(1, num, 1, posr, f+a[i].t);
		}
		ll ans=ask(1, num, 1, ifind(m), num);
		if(ans==oo) ans=-1;
		printf("Case #%d: %lld\n", tt, ans);
	}

	return 0;
}