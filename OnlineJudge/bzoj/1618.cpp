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

const int N=105, oo=~0u>>1;
int f[50005+5005], v[N], w[N], n, V;

int main() {
	read(n); read(V);
	int mx=0;
	for1(i, 1, n) { read(v[i]); read(w[i]); mx=max(v[i], mx); }
	for1(i, 1, V+mx) f[i]=oo>>1;
	for1(i, 1, n) {
		for(int j=v[i]; j<=mx+V; ++j)
			f[j]=min(f[j], f[j-v[i]]+w[i]);
	}
	int ans=oo;
	for(int j=V; j<=mx+V; ++j) ans=min(ans, f[j]);
	print(ans);
	return 0;
}

