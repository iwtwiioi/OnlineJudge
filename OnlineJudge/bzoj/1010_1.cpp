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

const int N=5005;
int n, l;
ll sum[N], d[N];

inline ll sqr(ll a) { return a*a; }
int main() {
	read(n); read(l);
	for1(i, 1, n) sum[i]=sum[i-1]+(ll)getint();
	CC(d, 0x3f);
	d[1]=sqr(sum[1]-l);
	for1(i, 2, n)
		for1(j, 0, i-1) d[i]=min(d[i], d[j]+sqr(i-(j+1)+sum[i]-sum[j]-l));
	printf("%lld\n", d[n]);
	return 0;
}