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

const int N=50005;
int n, l, front, tail, q[N];
ll s[N], d[N], f[N], c;
inline ll sqr(ll a) { return a*a; }
inline double x(int j, int k) { return (double)(d[k]-d[j]+sqr(f[k]+c)-sqr(f[j]+c))/2.0/(double)(f[k]-f[j]); }
int main() {
	read(n); read(l);
	for1(i, 1, n) s[i]=s[i-1]+(ll)getint();
	for1(i, 1, n) f[i]=s[i]+i;
	c=l+1;
	tail=1;
	for1(i, 1, n) {
		while(front+1<tail && x(q[front], q[front+1])<=f[i]) ++front;
		int j=q[front];
		d[i]=d[j]+sqr(f[i]-f[j]-c);
		while(front+1<tail && x(q[tail-2], q[tail-1])>=x(q[tail-1], i)) --tail;
		q[tail++]=i;
	}
	printf("%lld\n", d[n]);
	return 0;
}