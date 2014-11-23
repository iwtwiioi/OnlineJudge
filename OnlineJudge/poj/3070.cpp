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
typedef int matrix[2][2];
matrix a, b;
const int M=10000;
int n;
inline void mul(matrix a, matrix b, matrix c, const int &la, const int &lb, const int &lc, const int &MOD) {
	matrix t;
	rep(i, la) rep(j, lc) {
		t[i][j]=0;
		rep(k, lb) t[i][j]=(t[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
	}
	rep(i, la) rep(j, lc) c[i][j]=t[i][j];
}
int main() {
	while(~scanf("%d", &n) && n!=-1) {
		b[0][0]=b[1][1]=1;
		a[0][0]=a[0][1]=a[1][0]=1;
		b[0][1]=b[1][0]=a[1][1]=0;
		while(n) {
			if(n&1) mul(a, b, b, 2, 2, 2, M);
			mul(a, a, a, 2, 2, 2, M);
			n>>=1;
		}
		printf("%d\n", b[1][0]);
	}
	return 0;
}

