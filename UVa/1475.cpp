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

const int N=10005;
int n, a[N], g[N], f[N], h[N];

void lis() {
	CC(g, 0x3f);
	for1(i, 1, n) {
		int t=lower_bound(g+1, g+1+i, a[i])-g;
		f[i]=t;
		g[t]=a[i];
	}
	CC(g, 0x3f);
	for3(i, n, 1) {
		int t=lower_bound(g+1, g+1+i, a[i])-g;
		h[i]=t;
		g[t]=a[i];
	}
}

int main() {
	while(~scanf("%d", &n)) {
		for1(i, 1, n) read(a[i]);
		lis();
		int ans=0;
		for1(i, 1, n) ans=max(ans, min(f[i], h[i])*2-1);
		printf("%d\n", ans);
	}
	return 0;
}