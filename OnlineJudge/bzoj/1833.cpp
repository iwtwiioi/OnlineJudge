#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
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
inline const ll getint() { ll r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

ll f[100], c[100], a[100], p[100];

ll dfs(int x, int dig, int front, int line) {
	if(!x) return 0;
	if(!front && !line && f[x]!=-1) return f[x];
	ll last=(line?a[x]:9), tot=0;
	for1(i, 0, last) {
		if(front && i==0) tot+=dfs(x-1, dig, 1, line&&i==last);
		else if(i==dig) {
			if(i==last && line) tot+=c[x-1]+1+dfs(x-1, dig, 0, line&&i==last); //正好在这个数上
			else tot+=p[x-1]+dfs(x-1, dig, 0, line&&i==last);
		}
		else tot+=dfs(x-1, dig, 0, line&&i==last);
	}
	if(!front && !line) f[x]=tot;
	return tot;
}
ll getans(ll x, int dig) {
	CC(f, -1);
	ll t=x; int len=0;
	while(t) a[++len]=t%10, t/=10, c[len]=c[len-1]+a[len]*p[len-1];
	return dfs(len, dig, 1, 1);
}
int main() {
	ll a=getint(), b=getint();
	p[0]=1; for1(i, 1, 15) p[i]=p[i-1]*10;
	rep(i, 9) printf("%lld ", getans(b, i)-getans(a-1, i));
	printf("%lld\n", getans(b, 9)-getans(a-1, 9));
	return 0;
}