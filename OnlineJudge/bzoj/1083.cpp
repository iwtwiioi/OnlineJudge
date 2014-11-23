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

const int N=305, M=N*N;
struct dat { int x, y, w; }e[M];
int n, m, ans, p[N];
inline const bool cmp(const dat &a, const dat &b) { return a.w<b.w; }
inline const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
int main() {
	read(n); read(m);
	for1(i, 1, m) read(e[i].x), read(e[i].y), read(e[i].w);
	for1(i, 1, n) p[i]=i;
	sort(e+1, e+1+m, cmp);
	for1(i, 1, m) {
		int fx=ifind(e[i].x), fy=ifind(e[i].y);
		if(fx!=fy) {
			p[fx]=fy;
			ans=e[i].w;
		}
	}
	printf("%d %d\n", n-1, ans);
	return 0;
}