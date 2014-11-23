#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
#define debug(a) printf("%lld\n", a)
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }
typedef long long ll;
ll gcd(ll a, ll b) { return b?gcd(b, a%b):a; }

inline bool check(ll A, ll B) {
	if(((ll)sqrt(B)*(ll)sqrt(B))==B && A!=B)
		if(gcd(A, B)==1) return true;
	return false;
}

int main() {
	int ans=0;
	ll d, d2, r, r2;
	scanf("%lld", &r);
	r2=r<<1;
	ll m=sqrt(r2);
	ll a;
	for(d=1; d<=m; ++d) {
		if(!(r2%d)) {
			d2=d<<1;
			for(a=1; a<=(ll)sqrt(r2/d2); ++a)
				if(check(a*a, r2/d-a*a)) ++ans;
			if(d!=r2/d) {
				for(a=1; a<=(ll)sqrt(d/2); ++a)
					if(check(a*a, d-a*a)) ++ans;
			}
		}
	}
	printf("%lld\n", (ll)(ans*4+4));
	return 0;
}

