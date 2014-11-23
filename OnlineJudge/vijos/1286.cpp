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

typedef long long ll;
ll f[1<<9][212][2], sum[1<<9], ans;
int n, m, k, st[1<<9], cnt;
int cal(int x) {
	int ret=0;
	while(x) ++ret, x-=(x&-x);
	return ret;
}
ll c(ll x, ll y) {
	ll ret=1; if(x-y>y) y=x-y;
	for(ll i=x, j=2; i>=y+1; --i) {
		ret*=i;
		while(ret%j==0 && j<=x-y) ret/=j, ++j;
	}
	return ret;
}
ll gcd(ll a, ll b) { return b?gcd(b, a%b):a; }
int main() {
	read(n); read(m); read(k);
	if(m>n) swap(n, m);
	int all=(1<<m)-1;
	for1(i, 0, all) if(!(i&(i>>1)||(i&(i<<1)))) {
		st[++cnt]=i;
		sum[i]=cal(i);
		f[i][sum[i]][0]=1;
	}
	for1(line, 2, n) {
		for1(x, 1, cnt) for1(y, 1, cnt) if(!(st[x]&st[y])) {
			int i=st[x], j=st[y];
			for1(z, 0, k) f[i][z+sum[i]][1]+=f[j][z][0];
		}
		for1(x, 1, cnt) {
			int i=st[x];
			for1(z, 0, k) 
				f[i][z][0]=f[i][z][1], f[i][z][1]=0;
		}
	}
	for1(x, 1, cnt) ans+=f[st[x]][k][0];
	ll fm=c(n*m, k);
	ll d=gcd(fm, ans);
	if(ans) printf("%lld/%lld", fm/d, ans/d);
	else puts("Impossible!");
	return 0;
}