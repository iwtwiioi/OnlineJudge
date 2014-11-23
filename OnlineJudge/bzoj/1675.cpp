#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
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

const int md=1000000007;
int mp[7][7], vis[7][7], ans;
set<int> hs;
const int dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
int Hash() {
	int ret=0, k=7;
	for1(i, 1, 5) for1(j, 1, 5) if(vis[i][j]) {
		ret=(ret+(((mp[i][j]*k)%md)*(i*5+j)%md))%md;
		k=(k*7)%md;
	}
	return ret;
}
bool check(int x, int y) {
	rep(i, 4) if(vis[x+dx[i]][y+dy[i]]) return 1;
	return 0;
}
void dfs(int now, int a, int b) {
	if(now==8) {
		if(a>b) {
			int h=Hash();
			if(hs.count(h)==0) { hs.insert(h); ++ans; }
		}
		return;
	}
	for1(i, 1, 5) for1(j, 1, 5) if(!vis[i][j] && (check(i, j) || now==1)) {
		vis[i][j]=1;
		dfs(now+1, a+(mp[i][j]==31), b+(mp[i][j]==43));
		vis[i][j]=0;
	}
}

int main() {
	for1(i, 1, 5) for1(j, 1, 5) {
		char ch; for(ch=getchar(); !(ch=='H'||ch=='J'); ch=getchar());
		if(ch=='J') mp[i][j]=31;
		else mp[i][j]=43;
	}
	dfs(1, 0, 0);
	print(ans);
	return 0;
}

