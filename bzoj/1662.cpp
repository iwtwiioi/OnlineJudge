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

const int BIT=32;
int f[BIT][BIT], d[BIT][BIT];
void init() {
	f[0][0]=1;
	for1(i, 1, BIT) {
		f[i][0]=1;
		for1(j, 1, i)
			f[i][j]=f[i-1][j]+f[i-1][j-1];
	}
	d[0][0]=1;
	for1(i, 1, BIT)
		for3(j, i, 0)
			d[i][j]=d[i][j+1]+f[i][j];
}
int sum(int x) {
	int len=0, ret=0, k=0;
	while(x>>len) ++len;
	for1(i, 1, len-1) ret+=d[i-1][(i+1)>>1];
	for3(i, len-2, 0)
		if((x>>i)&1) {
			int j=((len+1)>>1)-k-1;
			if(j<0) j=0;
			ret+=d[i][j];
		}
		else ++k;
	return ret;
}
int main() {
	int l=getint(), r=getint();
	init();
	print(sum(r+1)-sum(l));
	return 0;
}

