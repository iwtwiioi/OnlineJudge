#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mkpii make_pair<int, int>
#define pdi pair<double, int>
#define mkpdi make_pair<double, int>
#define pli pair<ll, int>
#define mkpli make_pair<ll, int>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=10005;
int a[N], n, d[N][8];

int main() {
	read(n);
	for1(i, 1, n) read(a[i]);
	if(a[1]==0) d[1][8]=1;
	else if(a[1]==1) for1(i, 2, 3) d[1][i]=1;
	else if(a[1]==2) d[1][6]=1;
	for1(i, 2, n) {
		if(a[i]==0) d[i][8]=d[i-1][1]+d[i-1][8];
		else if(a[i]==1) {
			d[i][1]=d[i-1][2]+d[i-1][4];
			d[i][2]=d[i-1][3]+d[i-1][5];
			d[i][3]=d[i-1][1]+d[i-1][8];
		}
		else if(a[i]==2) {
			d[i][4]=d[i-1][6]+d[i-1][7];
			d[i][5]=d[i-1][4]+d[i-1][2];
			d[i][6]=d[i-1][3]+d[i-1][5];
		}
		else if(a[i]==3) d[i][7]=d[i-1][7]+d[i-1][6];
	}
	int ans=0;
	if(a[n]==0) ans=d[n][8];
	else if(a[n]==1) for1(i, 1, 2) ans+=d[n][i];
	else if(a[n]==2) ans=d[n][4];
	print(ans);
	return 0;
}