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
#define printarr(a, n, m) for1(aaa, 1, n) { for1(bbb, 1, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

int mp[7][7], ans, xy[10], x[10], y[10], vis[7][7], vv[7][7], cnt;
const int dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
void dfs(int x, int y) {
	vv[x][y]=1;
	++cnt;
	rep(i, 4) {
		int fx=dx[i]+x, fy=dy[i]+y;
		if(vis[fx][fy] && !vv[fx][fy]) dfs(fx, fy);
	}
}
bool check() {
	for1(i, 1, 7) x[i]=(xy[i]+4)/5, y[i]=xy[i]-(x[i]-1)*5;
	CC(vis, 0); CC(vv, 0);
	for1(i, 1, 7) vis[x[i]][y[i]]=1;
	cnt=0;
	dfs(x[1], y[1]);
	if(cnt!=7) return 0;
	int sum=0;
	for1(i, 1, 7) sum+=mp[x[i]][y[i]];
	return sum>3;
}
int main() {
	for1(i, 1, 5) for1(j, 1, 5) {
		char ch; for(ch=getchar(); ch!='H'&&ch!='J'; ch=getchar());
		mp[i][j]=ch=='J';
	}
	for(xy[1]=1; xy[1]<=19; ++xy[1])
		for(xy[2]=xy[1]+1; xy[2]<=20; ++xy[2])
			for(xy[3]=xy[2]+1; xy[3]<=21; ++xy[3])
				for(xy[4]=xy[3]+1; xy[4]<=22; ++xy[4])
					for(xy[5]=xy[4]+1; xy[5]<=23; ++xy[5])
						for(xy[6]=xy[5]+1; xy[6]<=24; ++xy[6])
							for(xy[7]=xy[6]+1; xy[7]<=25; ++xy[7])
								if(check()) ++ans;
	print(ans);
	return 0;
}

