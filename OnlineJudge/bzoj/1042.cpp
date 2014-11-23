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
#define printarr1(a, b) for1(_, 0, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=100005;
ll f[N], ans;
int n, c[5], d[5], s;

inline void cmp(int v) { for1(i, v, s) f[i]+=f[i-v]; }
void dfs(int dep, int x, int sum) {
	if(dep==5) {
		if(s-sum<0) return;
		if(x&1) ans-=f[s-sum];
		else ans+=f[s-sum];
		return;
	}
	dfs(dep+1, x, sum);
	dfs(dep+1, x+1, sum+d[dep]);
}
int main() {
	for1(i, 1, 4) read(c[i]); int tot=getint();
	f[0]=1;
	s=100005;
	for1(i, 1, 4) cmp(c[i]);
	while(tot--) {
		for1(i, 1, 4) read(d[i]);
		for1(i, 1, 4) d[i]=(d[i]+1)*c[i];
		read(s);
		ans=0;
		dfs(1, 0, 0);
		printf("%lld\n", ans);
	}
	return 0;
}