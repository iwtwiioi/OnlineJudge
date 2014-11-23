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

int vis[105], n, cs, a[105];
ll m, p[50], ans;

int main() {
	read(n); read(cs);
	p[0]=1;
	for1(i, 1, 25) p[i]=p[i-1]*(ll)i;
	char s[3];
	rep(tt, cs) {
		int j, k, t;
		scanf("%s", s);
		CC(vis, 0);
		if(s[0]=='P') {
			read(m); --m;
			for3(i, n, 1) {
				k=m/p[i-1]; m%=p[i-1];
				for(j=1, t=0; t<=k; ++j) if(!vis[j]) ++t;
				a[i]=j-1;
				vis[j-1]=1;
			}
			for3(i, n, 2) printf("%d ", a[i]); printf("%d\n", a[1]);
		}
		else {
			ans=0;
			for3(i, n, 1) read(a[i]);
			for3(i, n, 1) {
				for(j=1, t=0; j<a[i]; ++j) if(!vis[j]) ++t;
				ans+=(ll)t*p[i-1];
				vis[a[i]]=1;
			}
			printf("%lld\n", ans+1);
		}
	}
	return 0;
}