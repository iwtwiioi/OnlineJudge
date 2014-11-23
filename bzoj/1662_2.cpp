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
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int BIT=32;
int f[BIT][BIT][BIT], s[BIT];

int dfs(int x, int x1, int x2, bool first, bool line) {
	if(!x) {
		if(first) return 1; //要考虑0这个状态，也可以不考虑，因为此时x1和x2都等于0
		if(x1>=x2) return 1;
		return 0;
	}
	if(!first && !line && f[x][x1][x2]!=-1) return f[x][x1][x2]; //当隐式条件都不满足时才能记忆化
	int last=1, tot=0; if(line) last=s[x]; //当这个状态在n这个数的路径上
	for1(i, 0, last) {
		if(first) { //当这个状态是根
			if(!i) tot+=dfs(x-1, 0, 0, 1, line && (last==i)); //遍历左子树，重新计数，并且判断是否在n这个数的路径上
			else tot+=dfs(x-1, x1, x2+1, 0, line && (last==i));
		}
		else {
			if(!i) tot+=dfs(x-1, x1+1, x2, 0, line && (last==i));
			else tot+=dfs(x-1, x1, x2+1, 0, line && (last==i));
		}
	}
	if(!first && !line) f[x][x1][x2]=tot; //同之前的记忆化
	return tot;
}
int sum(int x) {
	int len=0;
	while(x) {
		s[++len]=x&1;
		x>>=1;
	}
	return dfs(len, 0, 0, 1, 1);
}

int main() {
	int l=getint(), r=getint();
	CC(f, -1);
	print(sum(r)-sum(l-1));
	return 0;
}

