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
#define read(a) scanf("%d", &a)
#define print(a) printf("%d", a)
#define bit(x) (1<<(x))
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int N=16;
int f[N][1<<N], d[N][N], all, n;

int main() {
	read(n);
	CC(f, 0x3f); all=bit(n+1)-1;
	for1(i, 0, n) for1(j, 0, n) read(d[i][j]);
	for1(k, 0, n) for1(i, 0, n) for1(j, 0, n) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
	f[0][0]=0;
	for1(i, 0, all) for1(now, 0, n) for1(from, 0, n) if(i&bit(now))
		f[now][i]=min(f[now][i], min(f[from][i-bit(now)]+d[from][now], f[from][i]+d[from][now]));
	print(f[0][all]);
	return 0;
}
