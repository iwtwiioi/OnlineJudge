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
int f[N][4], ans=oo, n, a[N];

void dp() {
	for1(i, 1, n) for1(j, 1, 3) f[i][j]=oo;
	for1(i, 1, n) for1(j, 1, 3) for1(k, 1, j)
		if(a[i]==j) f[i][j]=min(f[i][j], f[i-1][k]);
		else f[i][j]=min(f[i][j], f[i-1][k]+1);
	for1(i, 1, 3) ans=min(ans, f[n][i]);
}

int main() {
	read(n);
	for1(i, 1, n) read(a[i]);
	dp();
	for1(i, 1, n>>1) swap(a[i], a[n-i+1]);
	dp();
	print(ans);
	return 0;
}

