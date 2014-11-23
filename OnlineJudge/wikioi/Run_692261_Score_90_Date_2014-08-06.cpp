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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
#define bit(x) (1<<x)
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int N=17;
int f[1<<N][N], d[N][N], all, n;

int main() {
	read(n); ++n;
	CC(f, 0x3f); all=bit(n)-1;
	rep(i, n) rep(j, n) read(d[i][j]);
	rep(k, n) rep(i, n) rep(j, n) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
	f[0][0]=0;
	for1(i, 0, all) for2(now, 0, n) for2(from, 0, n) if(i&bit(now))
		f[i][now]=min(f[i][now], min(f[i-bit(now)][from]+d[from][now], f[i][from]+d[from][now]));
	print(f[all][0]);
	return 0;
}
