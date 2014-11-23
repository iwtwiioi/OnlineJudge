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
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=1500005;
typedef long long ll;
struct dat { ll w, u; }cow[N];
inline const bool cmp(const dat &a, const dat &b) { return a.u==b.u ? a.w<b.w : a.u>b.u; }
int n;
ll m, a, b, c, d, e, f, g, h;

int main() {
	cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m; ll nn=n*3;
	for(ll i=0; i<nn; ++i) {
		ll i2=(i*i)%d, i3=(i2*i)%d, i5=(i3*i2)%d;
		cow[i].w=((a*i5)%d+(b*i2)%d+c)%d;
		i2=(i*i)%h; i3=(i2*i)%h, i5=(i3*i2)%h;
		cow[i].u=((e*i5)%h+(f*i3)%h+g)%h;
	}
	sort(cow, cow+nn, cmp);
	long long ans=0;
	rep(i, n) {
		ans+=cow[i].w; if(ans>=m) ans%=m;
	}
	print(ans);
	return 0;
}