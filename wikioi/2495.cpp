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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int N=8;
int m[N][N], c[N][N], n, ans;
int fx[4]={-1, 1, 0, 0}, fy[4]={0, 0, -1, 1};
bool used[6];

inline int H() {
	int ret=0;
	CC(used, 0);
	rep(i, n) rep(j, n)
		if(!used[m[i][j]] && c[i][j]!=1)
			used[m[i][j]]=true, ++ret;
	return ret;
}

void change2(const int &x, const int &y, const int &color) {
	c[x][y]=1;
	int nx, ny;
	rep(i, 4) {
		nx=x+fx[i], ny=y+fy[i];
		if(nx<0 || nx>=n || ny<0 || ny>=n || c[nx][ny]==1) continue;
		c[nx][ny]=2;
		if(m[nx][ny]==color) change2(nx, ny, color);
	}
}

inline bool change(const int &color) {
	bool ret=false;
	rep(i, n) rep(j, n) if(c[i][j]==2 && m[i][j]==color) ret=true, change2(i, j, color);
	return ret;
}

bool dfs(const int &g) {
	int h=H();
	if(g+h>ans) return false;
	if(!h) return true;
	int t[N][N];
	for1(i, 0, 5) {
		memcpy(t, c, sizeof(c));
		if(change(i) && dfs(g+1)) return true;
		memcpy(c, t, sizeof(t));
	}
	return false;
}

int main() {
	for(read(n); n; read(n)) {
		CC(c, 0); CC(m, 0);
		rep(i, n) rep(j, n) read(m[i][j]);
		change2(0, 0, m[0][0]);
		for(ans=0; ; ++ans)
			if(dfs(0)) break;
		printf("%d\n", ans);
	}
	
	return 0;
}

