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

typedef long long matrix[2][2];
typedef long long ll;
matrix ta, tb, f;
inline const ll mul(ll a, ll b, const ll &MOD) {
	ll ret=0;
	while(b) {
		if(b&1) ret=(ret+a)%MOD;
		a=(a<<1)%MOD;
		b>>=1;
	}
	return ret;
}
inline void matrixmul(matrix a, matrix b, matrix c, const int &la, const int &lb, const int &lc, const ll &MOD) {
	matrix t;
	rep(i, la) rep(j, lc) {
		t[i][j]=0;
		rep(k, lb) t[i][j]=(t[i][j]+mul(a[i][k], b[k][j], MOD))%MOD;
	}
	rep(i, la) rep(j, lc)
		c[i][j]=t[i][j];
}
int main() {
	ll m, a, c, x, n, g;
	cin >> m >> a >> c >> x >> n >> g;
	ta[0][0]=a; ta[1][0]=ta[1][1]=1;
	tb[0][0]=tb[1][1]=1;
	f[0][0]=x; f[0][1]=c;
	while(n) {
		if(n&1) matrixmul(ta, tb, tb, 2, 2, 2, m);
		matrixmul(ta, ta, ta, 2, 2, 2, m);
		n>>=1;
	}
	matrixmul(f, tb, f, 1, 2, 2, m);
	cout << f[0][0]%g;
	return 0;
}

