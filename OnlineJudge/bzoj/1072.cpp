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

const int N=12;
int f[3005][1005], d, n, c[N], x[N], p[N];
int main() {
	int cs=getint();
	char s[N];
	p[0]=1;
	for1(i, 1, 11) p[i]=p[i-1]*i;
	while(cs--) {
		scanf("%s", s);
		n=strlen(s); read(d);
		CC(x, 0);
		rep(i, n) c[i]=s[i]-'0', x[c[i]]++;
		int all=(1<<n)-1;
		for1(i, 0, all) rep(j, d) f[i][j]=0;
		f[0][0]=1;
		rep(i, all) rep(j, d) if(f[i][j])
			rep(k, n) if(!(i&(1<<k))) f[i|(1<<k)][(j*10+c[k])%d]+=f[i][j];
		int ans=f[all][0];
		rep(i, 10) ans/=p[x[i]];
		printf("%d\n", ans);
	}
	return 0;
}