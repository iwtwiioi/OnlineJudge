#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
const int N=30005, oo=~0u>>1;
int f[N], ans=0, n, a[N], g[N];
void dp() {
	CC(f, 0); CC(g, 0);
	for1(i, 1, n) g[i]=oo;
	for1(i, 1, n) {
		int d=upper_bound(g+1, g+1+i, a[i])-g;
		f[i]=d;
		g[d]=min(a[i], g[d]);
		ans=max(f[i], ans);
	}
}

int main() {
	read(n);
	for1(i, 1, n) read(a[i]);
	dp();
	for1(i, 1, n>>1) swap(a[i], a[n-i+1]);
	dp();
	print(n-ans);
	return 0;
}

