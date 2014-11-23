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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

typedef unsigned long long ll;
ll l, r, ans, a[18];
int n;
ll get(ll c) { return r/c-(l-1)/c; }
ll gcd(ll a, ll b) { return b?gcd(b, a%b):a; }
void dfs(int x, ll c, int pos) {
	if(c>r) return;
	if(x&1) ans-=get(c);
	else ans+=get(c);
	for1(i, pos+1, n) dfs(x+1, c/gcd(c, a[i])*a[i], i);
}
int main() {
	read(n);
	for1(i, 1, n) read(a[i]);
	read(l); read(r);
	dfs(0, 8, 0);
	printf("%lld\n", ans);
	return 0;
}