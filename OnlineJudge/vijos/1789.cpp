#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(ll i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const ll getint() { ll r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const ll MD=1e9+7;
ll n, m, k, ans=1;
ll mul(ll a, ll b) { return ((a%MD)*(b%MD))%MD; }
int main() {
	read(n); read(m); read(k);
	if(k==1 || k>n) for1(i, 1, n) ans=mul(ans, m);
	else if(n==k) {
		ll mid=(n+1)>>1; ans=1;
		for1(i, 1, mid) ans=mul(ans, m);
	}
	else if(k&1) ans=mul(m, m);
	else ans=m;
	printf("%lld\n", ans%MD);
	return 0;
}