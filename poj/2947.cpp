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

const int N=305;
typedef int mtx[N][N];
string Dt[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int gauss(mtx A, int n, int m, int MD) {
	int x=1, y=1, pos;
	while(x<=n && y<=m) {
		pos=x;
		while(!A[pos][y] && pos<=n) ++pos;
		if(A[pos][y]) {
			for1(i, 1, m+1) swap(A[pos][i], A[x][i]);
			for1(i, x+1, n) if(A[i][y]) {
				int l=A[x][y], r=A[i][y];
				for1(j, y, m+1) A[i][j]=((A[i][j]*l-A[x][j]*r)%MD+MD)%MD;
			}
			++x;
		}
		++y;
	}
	for1(i, x, n) if(A[i][m+1]) return -1;
	if(x<=m) return m-x+1;
	for3(i, m, 1) {
		for1(j, i+1, m) if(A[i][j]) A[i][m+1]=((A[i][m+1]-(A[j][m+1]*A[i][j]))%MD+MD)%MD;
		while(A[i][m+1]%A[i][i]!=0) A[i][m+1]+=MD; //这里可以用拓欧搞掉。。
		A[i][m+1]=(A[i][m+1]/A[i][i])%MD;
	}
	return 0;
}
inline int get(string s) { return find(Dt, Dt+7, s)-Dt+1; }
int main() {
	int n=getint(), m=getint(), t;
	char s[2][5];
	mtx a;
	while(n|m) {
		CC(a, 0);
		for1(i, 1, m) {
			read(t); scanf("%s%s", s[0], s[1]);
			a[i][n+1]=(get(s[1])-get(s[0])+1+7)%7;
			for1(j, 1, t) ++a[i][getint()];
			for1(j, 1, n) a[i][j]%=7;
		}
		int ans=gauss(a, m, n, 7);
		if(ans==-1) puts("Inconsistent data.");
		else if(ans) puts("Multiple solutions.");
		else {
			for1(i, 1, n) if(a[i][n+1]<3) a[i][n+1]+=7;
			for1(i, 1, n-1) printf("%d ", a[i][n+1]); printf("%d\n", a[n][n+1]);
		}
		n=getint(), m=getint();
	}
	return 0;
}