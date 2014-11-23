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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=105, M=1005;
int f[N][M], n, T, K, w[N], h[N], hh[N], ans;

int main() {
	read(n); read(T); read(K);
	for1(i, 1, n) read(w[i]), read(h[i]), hh[i]=h[i]/5*4;
	for1(i, 1, n) if(h[i]<K)
		for1(j, h[i], T)
			f[0][j]=max(f[0][j], f[0][j-h[i]]+w[i]);
	for1(i, 1, n) if(h[i]>=K) {
		f[i][h[i]]=w[i];
		for1(j, 1, n)
			for1(v, h[i]+hh[j], T)
				f[i][v]=max(f[i][v], f[i][v-hh[j]]+w[j]);
	}
	for1(i, 0, n) for1(j, h[i], T) ans=max(ans, f[i][j]);
	print(ans);
	return 0;
}