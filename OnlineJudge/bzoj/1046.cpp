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

const int N=10005, oo=~0u>>1;
int a[N], f[N], g[N], n, mx;
bool cmp(const int &a, const int &b) { return a>b; }
void lis() {
	CC(g, 128);
	for3(i, n, 1) {
		int t=lower_bound(g+1, g+1+(n-i+1), a[i], cmp)-g; dbg(t);
		f[i]=t;
		g[t]=a[i];
		mx=max(mx, t);
	}
}

int main() {
	read(n);
	for1(i, 1, n) read(a[i]);
	lis();
	int tot=getint();
	while(tot--) {
		int m=getint();
		if(m>mx) { puts("Impossible"); continue; }
		int now=-oo;
		for1(i, 1, n) if(m && f[i]>=m && a[i]>now) { printf("%d", a[i]); m==1?puts(""):printf(" "); --m; now=a[i]; }
	}
	return 0;
}