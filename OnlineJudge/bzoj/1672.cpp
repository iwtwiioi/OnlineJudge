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
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=10005;
int f[N], n, ans=~0u>>1;
struct dat { int x, y, w; }a[N];
const bool cmp(const dat &x, const dat &y) { return x.x==y.x ? x.y<y.y : x.x<y.x; }
int main() {
	read(n); a[0].y=getint()-1; a[n+1].x=getint()+1;
	for1(i, 1, n) read(a[i].x), read(a[i].y), read(a[i].w);
	sort(a+1, a+1+n, cmp);
	CC(f, 0x3f);
	f[0]=0;
	for1(i, 1, n+1) {
		int s=a[i].x, w=a[i].w;
		rep(j, i) if(s-1<=a[j].y) f[i]=min(f[i], f[j]+w);
	}
	for1(i, 1, n) if(a[i].y>=a[n+1].x-1 && ans>f[i]) ans=f[i];
	ans=min(ans, f[n+1]);
	if(ans==f[n+2]) ans=-1;
	print(ans);
	return 0;
}

