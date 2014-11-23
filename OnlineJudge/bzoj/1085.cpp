#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
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
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }
inline void swap(int &a, int &b) { int c=b; b=a; a=c; }

const int dx[8]={1,2,2,1,-1,-2,-2,-1}, dy[8]={2,1,-1,-2,-2,-1,1,2};
int mb[6][6]=
{  
{0,0,0,0,0,0},  
{0,1,1,1,1,1},  
{0,0,1,1,1,1},  
{0,0,0,2,1,1},  
{0,0,0,0,0,1},  
{0,0,0,0,0,0}  
};
int s[6][6], ans, flag;

inline bool check() {
	for1(i, 1, 5) for1(j, 1, 5) if(s[i][j]!=mb[i][j]) return false;
	return true;
}

inline bool f(const int &g) {
	int h=0;
	for1(i, 1, 5) for1(j, 1, 5) if(s[i][j]!=mb[i][j]) {
		++h;
		if(h+g>ans) return false;
	}
	return true;
}

void dfs(const int &x, const int &y, const int &g) {
	if(g==ans) {
		if(check()) flag=1;
		return;
	}
	if(flag) return;
	rep(i, 8) {
		int fx=x+dx[i], fy=y+dy[i];
		if(fx<1 || fy<1 || fx>5 || fy>5) continue;
		swap(s[x][y], s[fx][fy]);
		if(f(g)) dfs(fx, fy, g+1);
		swap(s[x][y], s[fx][fy]);
	}
}

int main() {
	int t=getnum();
	char c;
	int x, y;
	while(t--) {
		for1(i, 1, 5) for1(j, 1, 5) { for(c=getchar(); c!='*' && (c<'0' || c>'9'); c=getchar()); if(c=='*') s[i][j]=2, x=i, y=j; else s[i][j]=c-'0'; }
		flag=0;
		for(ans=1; ans<=15; ++ans) {
			dfs(x, y, 0);
			if(flag) break;
		}
		if(flag) printf("%d\n", ans);
		else printf("-1\n");
	}
	
	return 0;
}

