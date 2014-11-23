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
inline const long long getint() { long long r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
typedef long long matrix[505];
void mul(matrix a, matrix b, matrix c, int lb, int lc, long long md) {
	matrix t;
	rep(j, lc) {
		t[j]=0;
		rep(k, lb)
			if(j-k>=0) t[j]=(t[j]+a[k]*b[j-k])%md;
			else t[j]=(t[j]+a[k]*b[lb+j-k])%md;
	}
	rep(j, lc) c[j]=t[j];
}
matrix a, b, c;
int main() {
	long long n, m, d, k;
	cin >> n >> m >> d >> k;
	rep(i, n) read(c[i]);
	a[0]=b[0]=1;
	rep(j, d+1) a[j]=1;
	for2(j, n-d, n) a[j]=1;
	while(k) {
		if(k&1) mul(a, b, b, n, n, m);
		mul(a, a, a, n, n, m);
		k>>=1;
	}
	mul(c, b, c, n, n, m);
	rep(i, n) printf("%lld ", c[i]);
	return 0;
}

