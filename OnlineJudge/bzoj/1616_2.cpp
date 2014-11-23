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

const int N=105, fx[]={-1, 1, 0, 0}, fy[]={0, 0, -1, 1};
int mp[N][N], n, m, T, R, C, X, Y, f[20][N][N];
int main() {
	read(n); read(m); read(T);
	int dx, dy;
	char st[105];
	for1(i, 1, n) {
		scanf("%s", st);
		for1(j, 1, m) if(st[j-1]!='.') mp[i][j]=1;
	}
	read(X); read(Y); read(R); read(C);
	f[0][X][Y]=1;
	for1(i, 1, T) for1(j, 1, N) for1(k, 1, N) if(!mp[j][k]) rep(l, 4) {
		dx=fx[l]+j; dy=fy[l]+k;
		if(dx<1 || dy<1 || dx>n || dy>m || mp[dx][dy]) continue;
		f[i][j][k]+=f[i-1][dx][dy];
	}
	print(f[T][R][C]);
	return 0;
}
