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

int n, f[1000], ans;

void mul(int x) {
	for1(i, 1, f[0]) f[i]*=x;
	int k=0, i;
	for(i=1; i<=f[0] || k; ++i) {
		f[i]+=k;
		k=f[i]/10; if(f[i]>=10) f[i]%=10;
	}
	while(!f[i]) --i;
	f[0]=i;
}
int main() {
	read(n); f[0]=f[1]=1;
	for1(i, 2, n) mul(i);
	for1(i, 1, f[0]) ans+=f[i];
	int m=sqrt(ans+0.5), flag=1;
	for1(i, 2, m) if(ans%i==0) { flag=0; break; }
	printf("%d", ans); flag?puts("T"):puts("F");
	return 0;
}