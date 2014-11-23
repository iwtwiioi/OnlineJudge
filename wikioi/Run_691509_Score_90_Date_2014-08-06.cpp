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
	if(k==s) { if(check()) flag=1; return; }
	if(flag) return;
	int nx, ny;
	vis2[x][y]=1;
	rep(i, 4) {
		nx=x+fx[i]; ny=y+fy[i];
		if(nx>0 && nx<6 && ny>0 && ny<6 && !vis2[nx][ny]) {
			if(m[nx][ny]) dfs(nx, ny, k);
			else {
				m[nx][ny]=1;
				dfs(nx, ny, k+1);
				m[nx][ny]=0;
			}
		}
	}
	vis2[x][y]=0;
}

int main() {
	char c;
	int ans=25;
	for1(i, 1, 5) for1(j, 1, 5) {
		for(c=getchar(); c<'0'||c>'9'; c=getchar());
		m[i][j]=c-'0';
	}
	int nx, ny, f=0;
	for1(i, 1, 5) {
		for1(j, 1, 5) if(m[i][j]) { nx=i, ny=j; f=1; break; }
		if(f) break;
	}
	for1(i, 1, 25) {
		s=i;
		CC(vis2, 0);
		dfs(nx, ny, 0);
		if(flag) { ans=i; break; }
	}
	print(ans);
	return 0;
}
