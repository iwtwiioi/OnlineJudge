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

const int N=2005;
int f[N][N], n, a[N], sum[N];
int main() {
	read(n);
	for3(i, n, 1) read(a[i]);
	for1(i, 1, n) sum[i]=sum[i-1]+a[i];
	for1(i, 1, n)
		for1(j, 1, n) {
			f[i][j]=f[i][j-1];
			if(i>=(j<<1))
				f[i][j]=max(f[i][j], sum[i]-f[i-(j<<1)][(j<<1)]);
			if(i-((j<<1)-1)>=0)
				f[i][j]=max(f[i][j], sum[i]-f[i-((j<<1)-1)][(j<<1)-1]);
		}
	print(f[n][1]);
	return 0;
}