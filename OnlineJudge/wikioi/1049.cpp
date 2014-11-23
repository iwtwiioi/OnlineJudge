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

int m[7][7], vis[7][7], vis2[7][7];
const int fx[4]={-1, 1, 0, 0}, fy[4]={0, 0, -1, 1};

int s, flag;

void dfs2(int x, int y) {
	vis[x][y]=1;
	int nx, ny;
	rep(i, 4) {
		nx=x+fx[i]; ny=y+fy[i];
		if(nx>0 && nx<6 && ny>0 && ny<6 && m[nx][ny] && !vis[nx][ny]) 
			dfs2(nx, ny);
	}
}

bool check() {
	int nx=0, ny=0, f=0;
	for1(i, 1, 5) {
		for1(j, 1, 5) if(m[i][j]) { nx=i, ny=j; f=1; break; }
		if(f) break;
	}
	if(!nx && !ny) return false;
	CC(vis, 0);
	dfs2(nx, ny);
	for1(i, 1, 5) for1(j, 1, 5) if(m[i][j] && !vis[i][j]) return false;
	return true;
}

void dfs(int x, int y, int k) {
	if(k==s) { /*for1(i, 1, 5) {for1(j, 1, 5) print(m[i][j]); puts(""); }*/if(check()) flag=1; return; }
	if(flag||x==6) return;
	for1(i, y, 5) if(!m[x][i]) {
		m[x][i]=1;
		i==5?dfs(x+1, 1, k+1):dfs(x, i+1, k+1);
		m[x][i]=0;
	}
	for1(i, x+1, 5) for1(j, 1, 5) if(!m[i][j]) {
		m[i][j]=1;
		j==5?dfs(i+1, 1, k+1):dfs(i, j+1, k+1);
		m[i][j]=0;
	}
}

int main() {
	char c;
	int ans=25;
	for1(i, 1, 5) for1(j, 1, 5) {
		for(c=getchar(); c<'0'||c>'9'; c=getchar());
		m[i][j]=c-'0';
	}
	for1(i, 1, 25) {
		s=i;
		dfs(1, 1, 0);
		if(flag) { ans=i; break; }
	}
	print(ans);
	return 0;
}

