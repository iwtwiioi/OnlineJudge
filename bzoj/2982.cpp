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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int MD=10007;
int mpow(int a, int b) {
	int ret=1;
	for(; b; b>>=1, a=(a*a)%MD) if(b&1) ret=(ret*a)%MD;
	return ret;
}
int getc(int n, int m) {
	if(n<m) return 0;
	int up=1, down=1;
	for1(i, m+1, n) up=(up*i)%MD;
	for1(i, 1, n-m) down=(down*i)%MD;
	return (up*mpow(down, MD-2))%MD;
}
int lucas(int n, int m) {
	return m?(getc(n%MD, m%MD)*lucas(n/MD, m/MD))%MD:1;
}
int main() {
	int t=getint();
	while(t--) {
		int n=getint(), m=getint();
		printf("%d\n", lucas(n, m));
	}
	return 0;
}