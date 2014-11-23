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
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb] << '\t'; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

int mp[105][105], n, m, f[105][105];

int main() {
	read(n); read(m);
	for1(i, 1, n) for1(j, 1, m) read(mp[i][j]);
	f[1][1]=mp[1][1];
	for1(j, 2, m) for1(i, 1, n) {
		if(i>1) f[i][j]=max(f[i][j], f[i-1][j-1]);
		if(i<n) f[i][j]=max(f[i][j], f[i+1][j-1]);
		f[i][j]=max(f[i][j], f[i][j-1]);
		if(f[i-1][j-1] || f[i+1][j-1] || f[i][j-1]) f[i][j]+=mp[i][j];
	}
	print(f[n][m]);
	return 0;
}

