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

const int N=25;
int a[N], d[N][10], len;
int dfs(int x, int num, int front, int line) {
	if(!x) {
		//if(front) return 0;
		return 1;
	}
	if(!front && !line && d[x][num]!=-1) return d[x][num];
	int last=9, tot=0; if(line) last=a[x];
	for1(i, 0, last) {
		if(front) {
			if(i==0) tot+=dfs(x-1, i, 1, line && i==last);
			else tot+=dfs(x-1, i, 0, line && i==last);
		}
		else if(abs(i-num)>=2) tot+=dfs(x-1, i, 0, line && i==last);
	}
	if(!front && !line) d[x][num]=tot;
	return tot;
}
int getans(int x) {
	len=0;
	while(x) a[++len]=x%10, x/=10;
	return dfs(len, 0, 1, 1);
}
int main() {
	CC(d, -1);
	int x=getint(), y=getint();
	print(getans(y)-getans(x-1));
	return 0;
}