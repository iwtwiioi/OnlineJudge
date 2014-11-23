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
#define dbg(x) cout << #x << " = " << x << endl
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
typedef long long ll;
inline const ll getint() { ll r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const ll min(const ll &a, const ll &b) { return a<b?a:b; }

const int N=100005;
struct dat { ll c, w; }a[N];
bool cmp(const dat &a, const dat &b) { return a.c<b.c; }
ll V, ans; int n;

int main() {
	read(n); read(V);
	for1(i, 1, n) read(a[i].c), read(a[i].w);
	sort(a+1, a+1+n, cmp);
	for1(i, 1, n) {
		if(V<a[i].c) break;
		ll t=V/a[i].c;
		t=min(t, a[i].w);
		ans+=t;
		V-=a[i].c*t;
	}
	print(ans);
	return 0;
}