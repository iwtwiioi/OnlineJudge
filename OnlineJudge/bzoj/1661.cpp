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

const int N=1005;
int mp[N][N], n, ans;

int main() {
	read(n);
	for1(i, 1, n) for1(j, 1, n) {
		char ch=getchar(); while(ch!='J'&&ch!='B'&&ch!='*') ch=getchar();
		if(ch=='J') mp[i][j]=2;
		else if(ch=='*') mp[i][j]=1;
	}
	for1(x, 1, n) for1(y, 1, n) if(mp[x][y]==2)
		for1(i, 1, n) for1(j, 1, n) if(!(x==i&&y==j) && mp[i][j]) {
			int l=i-x, r=j-y;
			if(l*l+r*r<ans) continue;
			if(i-r>=0 && j+l>=0 && x-r>=0 && y+l>=0 && mp[i-r][j+l]==2 && mp[x-r][y+l]==2)
				ans=l*l+r*r;
			if(i+r>=0 && j-l>=0 && x+r>=0 && y-l>=0 && mp[i+r][j-l]==2 && mp[x+r][y-l]==2)
				ans=l*l+r*r;
		}
	print(ans);
	return 0;
}