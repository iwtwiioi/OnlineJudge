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
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const double eps=1e-8;
const int N=1e5+10, T=100;
int g[N], n;
double k, ans[N], m[N];
int main() {
	read(n); scanf("%lf", &k);
	for1(i, 1, n) scanf("%lf", &m[i]);
	for1(i, 1, n) g[i]=(int)(floor(k*(double)i)+eps);
	for1(i, 1, min(n, T)) {
		for1(j, 1, g[i]) ans[i]+=m[j]/(i-j);
		ans[i]*=m[i];
	}
	for1(i, min(n, T)+1, n) {
		int pre=i-T;
		for1(j, g[pre]+1, g[i]) ans[i]+=m[j]/(i-j);
		ans[i]+=ans[pre]*(pre-g[pre]/2.0)/m[pre]/(i-g[pre]/2.0);
		ans[i]*=m[i];
	}
	for1(i, 1, n) printf("%.6f\n", ans[i]+eps);
	return 0;
}