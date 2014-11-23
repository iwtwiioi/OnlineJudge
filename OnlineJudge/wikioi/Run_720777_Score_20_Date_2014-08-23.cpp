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
#define read(a) a=getnum()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
inline int getnum() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int fx[4]={1, 1, 0, -1}, fy[4]={0, 1, 1, 1}, N=70;
int n, m, vis[N][N], flag;
char a[N][N];
inline const bool cmp(const char &a, const char &b, const char &c) { if(a==b && b==c && a!=' ') return true; return false; }
inline void lian(int x, int y, const int &i, const char &c) { for(x+=fx[i], y+=fy[i]; x>=0 && x<n && y>=0 && y<m && a[x][y]==c; x+=fx[i], y+=fy[i]) vis[x][y]=1; }
inline void xiao(const int &x, const int &y) {
	int x1, x2, y1, y2;
	rep(i, 4) {
		x1=x+fx[i]; y1=y+fy[i];
		x2=x1+fx[i]; y2=y1+fy[i];
		if(cmp(a[x][y], a[x1][y1], a[x2][y2])) {
			lian(x2, y2, i, a[x][y]);
			vis[x][y]=vis[x1][y1]=vis[x2][y2]=1;
			flag=1;
		}
	}
}
inline void clean() {
	CC(vis, 0); flag=0;
	rep(i, n) rep(j, m) if(!vis[i][j]) xiao(i, j);
	if(flag) rep(i, n) rep(j, m) if(vis[i][j]) a[i][j]=' ';
}
inline void fix() { rep(i, m) for(int t=n-1; t; --t) if(a[t][i]==' ') swap(a[t-1][i], a[t][i]); }


int main() {
	read(n); read(m);
	rep(i, n) scanf("%s", a[i]);
	while(1) {
		clean(); fix();
		if(!flag) break;
	}
	rep(i, n) printf("%s\n", a[i]);
	return 0;
}

