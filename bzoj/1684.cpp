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
typedef long double llf;
llf eps=1e30;
int a, b, ans1, ans2;
void cal(int x, int y) {
	if(a*y==b*x) return;
	llf c=abs((llf)x/y-(llf)a/b);
	if(c<eps) {
		eps=c;
		ans1=x; ans2=y;
	}
}
int main() {
	a=getint(), b=getint();
	for1(i, 1, 32767) {
		int j=(llf)a/(llf)b*(llf)i;
		cal(j, i); cal(j+1, i);
	}
	printf("%d %d", ans1, ans2);
	return 0;
}

