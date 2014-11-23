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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j] << '\t'; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=60, Q=N*N*10, dx[]={-1, 1, 0, 0, -1, 1, -1, 1}, dy[]={0, 0, -1, 1, -1, -1, 1, 1};
int a[N][N], line[N][N], f[2][N][N], n, m, front, tail, flag, x, y, X, Y;
struct dat { int x, y, f; }q[Q];

int main() {
	read(n); read(m);
	for1(i, 1, n) for1(j, 1, m) {
		char ch=getchar(); while(ch!='.'&&ch!='X'&&ch!='*') ch=getchar();
		if(ch=='X') a[i][j]=1, x=i, y=j;
		else if(ch=='*') X=i, Y=j;
	}
	for1(i, 1, n) if(i+x<=n) line[i+x][y]=1; else break;
	q[tail].x=X, q[tail].y=Y, q[tail++].f=0;
	while(front!=tail) {
		dat &t=q[front++]; if(front==Q) front=0;
		x=t.x, y=t.y, flag=t.f;
		rep(i, 8) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<0 || fy<0 || fx>n || fy>m || a[fx][fy]) continue;
			if((line[x][y] || line[fx][fy]) && fy<=y) continue; //当前在射线上或下一个点是射线上时（即从右向左），不能向右拓展
			if(line[fx][fy] && !f[1][fx][fy]) { //当这是从射线左边向射线过来时，更新上的点
				f[1][fx][fy]=f[flag][x][y]+1;
				q[tail].x=fx, q[tail].y=fy, q[tail++].f=1; if(tail==Q) tail=0;
			}
			else if(!f[flag][fx][fy]) { //继承饶了一圈后的距离向四周拓展
				f[flag][fx][fy]=f[flag][x][y]+1;
				q[tail].x=fx, q[tail].y=fy, q[tail++].f=flag; if(tail==Q) tail=0;
			}
		}
	}
	print(f[1][X][Y]);
	return 0;
}