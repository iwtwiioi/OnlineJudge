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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=15;
double A[N][N], a[N][N];
int n;

void gauss() {
	for1(i, 1, n-1) {
		int pos=i;
		for1(j, i+1, n) if(abs(A[pos][i])<abs(A[j][i])) pos=j;
		for1(j, 1, n+1) swap(A[i][j], A[pos][j]);
		for1(j, i+1, n) {
			double y=A[j][i]/A[i][i];
			for1(k, i, n+1) A[j][k]-=y*A[i][k];
		}
	}
	for3(i, n, 1) {
		for1(j, i+1, n) A[i][n+1]-=A[j][n+1]*A[i][j];
		A[i][n+1]/=A[i][i];
	}
}
int main() {
	read(n);
	for1(i, 1, n+1) for1(j, 1, n) scanf("%lf", &a[i][j]);
	for1(i, 1, n) {
		for1(j, 1, n) A[i][j]=2*(a[i+1][j]-a[i][j]);
		for1(j, 1, n) A[i][n+1]+=a[i+1][j]*a[i+1][j]-a[i][j]*a[i][j];
	}
	gauss();
	for1(i, 1, n-1) printf("%.3lf ", A[i][n+1]); printf("%.3lf\n", A[n][n+1]);
	return 0;
}