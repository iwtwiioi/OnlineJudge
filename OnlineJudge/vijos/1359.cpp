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

int n;
bool check(int x) {
	if(x<2) return 0;
	int m=sqrt(x+0.5);
	for1(i, 2, m) if(x%i==0) return 0;
	return 1;
}
void dfs(int x, int s) {
	if(x==n) {
		printf("%d\n", s); return;
	}
	int beg=(x==0?2:1);
	for1(i, beg, 10) if(i==2 || i&1) {
		int nx=s*10+i;
		if((x==0 && i==1) || check(nx)) dfs(x+1, nx);
	}
}
int main() {
	read(n);
	dfs(0, 0);
	return 0;
}