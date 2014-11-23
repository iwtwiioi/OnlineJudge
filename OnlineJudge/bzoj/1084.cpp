#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
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
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret*k; }

const int N=105;
int f[N][N][15], s[N][5], ans, d[N][15];

int main() {
	int n=getnum(), m=getnum(), K=getnum();
	for1(i, 1, n) for1(j, 1, m) s[i][j]=s[i-1][j]+getnum();
	if(m==1) {
		for1(i, 1, n) for1(j, 1, K) {
			d[i][j]=d[i-1][j];
			for1(k, 0, i-1) d[i][j]=max(d[i][j], d[k][j-1]+s[i][1]-s[k][1]);
		}
		ans=d[n][K];
	}
	else {
		for1(i, 1, n) for1(j, 1, n) for1(k, 1, K) {
			f[i][j][k]=max(f[i-1][j][k], f[i][j-1][k]);
			for1(l, 0, i-1)
				f[i][j][k]=max(f[i][j][k], f[l][j][k-1]+s[i][1]-s[l][1]);
			for1(l, 0, j-1)
				f[i][j][k]=max(f[i][j][k], f[i][l][k-1]+s[j][2]-s[l][2]);
			if(i==j) for1(l, 0, i-1)
				f[i][j][k]=max(f[i][j][k], f[l][l][k-1]+s[i][1]-s[l][1]+s[j][2]-s[l][2]);
		}
		ans=f[n][n][K];
	}
	print(ans);
	return 0;
}

