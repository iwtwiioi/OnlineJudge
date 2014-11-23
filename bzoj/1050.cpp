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

const int N=1005, M=10005;
struct dat { int x, y, w; }a[M];
inline const bool cmp(const dat &a, const dat &b) { return a.w<b.w; }
int p[N], ans1, ans2, n, m;
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
const int gcd(const int &a, const int &b) { return !b?a:gcd(b, a%b); }

int main() {
	read(n); read(m);
	for1(i, 1, m) read(a[i].x), read(a[i].y), read(a[i].w);
	int s=getint(), t=getint();
	sort(a+1, a+1+m, cmp);
	bool flag=1;
	for1(i, 1, m) {
		for1(j, 1, n) p[j]=j;
		int j=i;
		for(; j<=m; ++j) {
			int fx=ifind(a[j].x), fy=ifind(a[j].y);
			p[fx]=fy;
			if(ifind(s)==ifind(t)) {
				flag=0;
				if(a[j].w*ans2<=a[i].w*ans1) ans1=a[j].w, ans2=a[i].w;
				break;
			}
		}
		if(ifind(s)!=ifind(t)) break;
		if(a[j].w*ans2<=a[i].w*ans1) ans1=a[j].w, ans2=a[i].w;
	}
	if(flag) { puts("IMPOSSIBLE"); return 0; }
	int d=gcd(ans1, ans2);
	ans1/=d; ans2/=d;
	if(ans2==1) printf("%d\n", ans1);
	else printf("%d/%d\n", ans1, ans2);
	return 0;
}