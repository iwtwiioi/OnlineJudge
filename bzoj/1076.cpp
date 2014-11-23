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

const int N=20, K=105;
double f[K][70000];
int g[N], w[N], b[N], n, k;

int main() {
	read(k); read(n);
	for1(i, 1, n+1) b[i]=1<<(i-1);
	for1(i, 1, n) {
		read(w[i]);
		for(int t=getint(); t; t=getint()) g[i]+=b[t];
	}
	for3(i, k, 1) {
		for1(j, 0, b[n+1]-1) {
			for1(l, 1, n) {
				if((g[l]&j)==g[l]) //如果依赖都已经拿了
					f[i][j]+=max(f[i+1][j], f[i+1][j|b[l]]+w[l]); //选择最大值（因为题目有负值）
				else f[i][j]+=f[i+1][j]; //（否则直接转移）
			}
			f[i][j]/=(double)n;
		}
	}
	printf("%.6f\n", f[1][0]);
	return 0;
}

