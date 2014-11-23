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

const int N=505;
int d[N][N], n, f, m, l[N];

int main() {
	read(n); read(f); read(m);
	CC(d, 0x3f);
	rep(i, f) read(l[i]);
	rep(i, m) {
		int u=getint(), v=getint(), w=getint();
		d[u][v]=d[v][u]=w;
	}
	for1(i, 1, n) d[i][i]=0;
	for1(k, 1, n) for1(i, 1, n) for1(j, 1, n) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
	int ans, mn=~0u>>1;
	for1(i, 1, n) {
		int sum=0;
		rep(j, f) if(d[i][l[j]]!=0x3f3f3f3f) sum+=d[i][l[j]];
		if(sum<mn) {
			mn=sum;
			ans=i;
		}
	}
	print(ans);
	return 0;
}