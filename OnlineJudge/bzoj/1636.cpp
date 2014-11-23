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

const int N=50005;
int mx[N], n, q, a[N], mn[N];
void update(int x, int c) { for(; x<=n; x+=x&-x) mx[x]=max(c, mx[x]), mn[x]=min(c, mn[x]); }
int ask(int l, int r) {
	int x=0, y=~0u>>1;
	while(l<=r) {
		x=max(x, a[r]); y=min(y, a[r]);
		for(--r; r-l>=(r&-r); r-=r&-r)
			x=max(mx[r], x), y=min(mn[r], y);
	}
	return x-y;
}

int main() {
	read(n); read(q);
	CC(mn, 0x7f);
	for1(i, 1, n) { read(a[i]); update(i, a[i]); }
	int l, r;
	while(q--) {
		read(l); read(r);
		printf("%d\n", ask(l, r));
	}
	return 0;
}

