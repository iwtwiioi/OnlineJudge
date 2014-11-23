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

const int N=1005;
struct nod { int s, e, w; }a[N];
int n, r, m, f[N];
bool cmp(const nod &a, const nod &b) { return a.s<b.s; }

int main() {
	read(n); read(m); read(r);
	for1(i, 1, m) read(a[i].s), read(a[i].e), read(a[i].w);
	sort(a+1, a+1+m, cmp);
	int ans=0;
	for1(i, 1, m) {
		f[i]=a[i].w;
		for1(j, 1, i-1) if(a[i].s>=a[j].e+r && f[i]<f[j]+a[i].w) f[i]=f[j]+a[i].w;
		ans=max(ans, f[i]);
	}
	print(ans);
	return 0;
}

