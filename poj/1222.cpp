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

const int N=35;
typedef int mtx[N][N];
mtx a;
void gauss(mtx A, int n) {
	for1(i, 1, n) {
		int now=i;
		while(!A[now][i] && now<=n) ++now;
		for1(j, 1, n+1) swap(A[now][j], A[i][j]);
		for1(j, i+1, n) if(A[j][i])
			for1(k, i, n+1) A[j][k]^=A[i][k];
	}
	for3(i, n, 1)
		for1(j, i+1, n) if(A[i][j]) A[i][n+1]^=A[j][n+1];
}
int main() {
	int cs=getint();
	for1(ttt, 1, cs) {
		CC(a, 0);
		for1(i, 1, 30) {
			read(a[i][31]);
			a[i][i]=1;
			if(i%6!=1) a[i][i-1]=1;
			if(i%6!=0) a[i][i+1]=1;
			if(i>6) a[i][i-6]=1;
			if(i<25) a[i][i+6]=1;
		}
		gauss(a, 30);
		printf("PUZZLE #%d\n", ttt);
		for1(i, 1, 30) {
			printf("%d ", a[i][31]); if(i%6==0) puts("");
		}
	}
	return 0;
}