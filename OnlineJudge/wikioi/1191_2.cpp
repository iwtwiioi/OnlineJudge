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

const int N=200005;
int c[N], n, R, L;
inline void update(int x, const int &s) { for(; x<=n; x+=x&-x) c[x]+=s; }
inline int sum(int x) { int ret=0; for(; x; x-=x&-x) ret+=c[x]; return ret; }

int main() {
	read(n); int m; read(m);
	for(int i=1; i<=n; ++i) update(i, 1);
	while(m--) {
		read(L); read(R);
		for(int i=L; i<=R; ++i) update(i, -1), dbg(sum(n));
		printf("%d\n", sum(n));
	}	
	return 0;
}

