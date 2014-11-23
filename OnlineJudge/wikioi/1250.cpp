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

typedef int mtx[2][2];
void mul(mtx a, mtx b, mtx c, int la, int lb, int lc, int md) {
	mtx t;
	rep(i, la) rep(j, lc) {
		t[i][j]=0;
		rep(k, lb) t[i][j]=(t[i][j]+a[i][k]*b[k][j])%md;
	}
	rep(i, la) rep(j, lc) c[i][j]=t[i][j];
}
mtx a, b, c;
int main() {
	int cs, n, q;
	read(cs);
	while(cs--) {
		read(n); read(q);
		a[0][0]=b[0][1]=b[1][0]=0;
		a[0][1]=a[1][0]=a[1][1]=1;
		b[0][0]=b[1][1]=1;
		c[0][0]=0; c[0][1]=1;
		while(n) {
			if(n&1) mul(a, b, b, 2, 2, 2, q);
			mul(a, a, a, 2, 2, 2, q);
			n>>=1;
		}
		mul(c, b, c, 1, 2, 2, q);
		printf("%d\n", c[0][1]);
	}
	return 0;
}

