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

const int N=1005;
int p[N], vis[N], cnt, n;
ll d[2][N];
void init() {
	for1(i, 2, n) {
		if(!vis[i]) p[++cnt]=i;
		for(int j=1; j<=cnt && p[j]*i<=n; ++j) {
			vis[p[j]*i]=1;
			if(!(i%p[j])) break;
		}
	}
}

int main() {
	read(n); init();
	int now=1, last=0;
	d[last][0]=1;
	for1(i, 1, cnt) {
		for1(j, 0, n) {
			d[now][j]=d[last][j];
			for(int k=p[i]; j-k>=0; k*=p[i])
				d[now][j]+=d[last][j-k];
		}
		for1(j, 0, n) d[last][j]=0;
		now^=1;
		last^=1;
	}
	ll ans=0;
	for1(i, 0, n) ans+=d[last][i];
	printf("%lld", ans);
	return 0;
}