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
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int N=105;

double d[N][N], I[N], f[N][N];
int main() {
	int n=getnum(), m=getnum(), u, v;
	for1(i, 1, n) for1(j, 1, n) d[i][j]=1e15;
	for1(i, 1, m) read(u), read(v), scanf("%lf", &d[u][v]), d[v][u]=d[u][v], f[u][v]=f[v][u]=1;
	for1(k, 1, n) for1(i, 1, n) for1(j, 1, n) {
		if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j], f[i][j]=0;
		if(d[i][j]==d[i][k]+d[k][j]) f[i][j]+=f[i][k]*f[k][j];
	}
	for1(i, 1, n) f[i][i]=0;
	for1(k, 1, n) 
		for1(i, 1, n) for1(j, 1, n) if(d[i][j]==d[i][k]+d[k][j] && f[i][j]>0)
			I[k]+=f[i][k]*f[k][j]/f[i][j];
	for1(i, 1, n) printf("%.3lf\n", I[i]);
	return 0;
}

