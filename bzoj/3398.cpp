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

const int N=100005;
const long long MOD=5000011;
int p[N], n, k;
long long fastpow(long long a, long long b) {
	long long ret=1; a%=MOD;
	while(b) {
		if(b&1) ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}
int main() {
	read(n); read(k); p[0]=p[1]=1;
	for1(i, 2, n) p[i]=((long long)p[i-1]*(long long)i)%MOD;
	long long ans=1+n;
	for1(i, 2, n) {
		int b=n-i, x=i, y=b-(x-1)*k;
		if(y<0) break;
		//逆元就是(a / b) % p = a * b ^ (phi(p)-1) % p
		ans=(ans+((long long)p[x+y]*fastpow((long long)p[x]*(long long)p[y], MOD-2))%MOD)%MOD;
	}
	print(ans);
	return 0;
}