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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=100, Q=N*N, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
int mp[N][N], n, m, f[N][N], front, tail, ans1[N], ans2[N], cnt, X, Y, XX, YY;
char s[N];
struct dat { int x, y; }q[Q];
void bfs() {
	front=tail=0;
	q[tail].x=X, q[tail++].y=Y;
	CC(f, 0x3f); f[X][Y]=0;
	while(tail!=front) {
		dat &t=q[front++]; if(front==Q) front=0;
		int x=t.x, y=t.y, d=f[x][y];
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>m || !mp[fx][fy] || f[fx][fy]<=d+1) continue;
			f[fx][fy]=d+1;
			q[tail].x=fx, q[tail++].y=fy; if(tail==Q) tail=0;
		}
	}
	int x=XX, y=YY, now=-1, tot=0;
	while(!(x==X && y==Y)) {
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>m || !mp[fx][fy] || f[fx][fy]!=f[x][y]-1) continue;
			if(mp[fx][fy]==1) ++tot;
			if(now!=i && now!=-1) {
				ans1[++cnt]=now;
				ans2[cnt]=tot;
				tot=0;
			}
			now=i;
			x=fx, y=fy;
		}
	}
	ans1[++cnt]=now; ans2[cnt]=tot+1;
}

int main() {
	read(n); read(m); n=n*2-1, m=m*2-1;
	for1(i, 1, n) {
		scanf("%s", s+1);
		for1(j, 1, m) {
			if(s[j]=='+') mp[i][j]=1;
			else if(s[j]=='S') X=i, Y=j, mp[i][j]=3;
			else if(s[j]=='E') XX=i, YY=j, mp[i][j]=4;
			else if(s[j]=='.') mp[i][j]=0;
			else mp[i][j]=2;
		}
	}
	bfs();
	for3(i, cnt, 1) {
		char c='H';
		if(ans1[i]==2) c='E';
		else if(ans1[i]==3) c='W';
		else if(ans1[i]==1) c='N';
		else if(ans1[i]==0) c='S';
		printf("%c %d\n", c, ans2[i]);
	}
	return 0;
}