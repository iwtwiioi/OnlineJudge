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
#define dbg(x) cout << #x << " = " << x << endl
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

typedef long long ll;
const int N=50005;
ll a[N];
int n, d;
bool check(ll x) {
	ll sum=0; int tot=1;
	for1(i, 1, n) {
		sum+=a[i];
		while(tot<=d && sum>=x) sum>>=1, ++tot;
		if(tot>d) return 1;
	}
	return 0;
}
void pri(ll x) {
	ll sum=0; int tot=1;
	for1(i, 1, n) {
		sum+=a[i]; printf("%d\n", tot);
		while(tot<d && sum>=x) sum>>=1, ++tot;
	}
}

int main() {
	read(n); read(d);
	ll l=0, r=0;
	for1(i, 1, n) read(a[i]), r+=a[i];
	while(l<=r) {
		ll m=(l+r)>>1;
		if(check(m)) l=m+1;
		else r=m-1;
	}
	printf("%lld\n", l-1);
	pri(l-1);
	return 0;
}