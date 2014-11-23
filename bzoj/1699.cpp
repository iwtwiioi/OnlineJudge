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

const int N=50005, oo=~0u>>1;
int mx[N], mn[N], n, q, a[N];
void update(int x, int c) { for(; x<=n; x+=x&-x) mx[x]=max(mx[x], c), mn[x]=min(mn[x], c); }
int ask(int l, int r) {
	int x=-oo, y=oo;
	while(l<=r) {
		if(r-l+1>=(r&-r)) {
			y=min(y, mn[r]);
			x=max(x, mx[r]);
			r-=r&-r;
		}
		else {
			y=min(y, a[r]);
			x=max(x, a[r]);
			--r;
		}
	}
	return x-y;
}

int main() {
	read(n); read(q);
	int x, y;
	CC(mx, -1); CC(mn, 0x7f);
	for1(i, 1, n) { read(a[i]); update(i, a[i]); }
	for1(i, 1, q) {
		read(x); read(y);
		printf("%d\n", ask(x, y));
	}
	return 0;
}

