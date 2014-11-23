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

const int N=35;
int d[N][N], a[N][N], vis[N][N], ans, n, m;
int dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, +1};
struct qu{ int x, y; } q[N*N*2];
int front, tail;

void spfa(const int &s, const int &t) {
	int x, y;
	CC(vis, 0); CC(d, 0x7f);
	d[s][t]=front=tail=0;
	vis[s][t]=1; q[tail].x=s, q[tail++].y=t;
	while(front<tail) {
		x=q[front].x; y=q[front++].y;
		rep(i, 4) if(x+dx[i] && x+dx[i]<=n && y+dy[i] && y+dy[i]<=m && d[x][y]+a[x+dx[i]][y+dy[i]]<d[x+dx[i]][y+dy[i]]) {
			d[x+dx[i]][y+dy[i]]=d[x][y]+a[x+dx[i]][y+dy[i]];
			if(!vis[x+dx[i]][y+dy[i]]) {
				vis[x+dx[i]][y+dy[i]]=1;
				q[tail].x=x+dx[i]; q[tail++].y=y+dy[i];
			}
		}
		vis[x][y]=0;
	}
}

int main() {
	read(n); read(m);
	int t=getnum();
	char c;
	for1(i, 1, n) for1(j, 1, m) {
		for(c=getchar(); c<'0' || c>'9'; c=getchar()); 
		a[i][j]=c-'0';
	}
	int t1;
	for1(i, 1, n) for1(j, 1, m) {
		spfa(i, j);
		t1=t; if(a[i][j]) --t1;
		for1(x, 1, n) for1(y, 1, m)	if(d[x][y]<=t1)
			ans=max(ans, (i-x)*(i-x)+(j-y)*(j-y));
	}
	printf("%.6lf", sqrt((double)ans));
	return 0;
}

