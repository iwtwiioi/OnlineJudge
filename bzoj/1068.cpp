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

const int N=52, oo=0x3f3f3f3f;
int d[N][N], n;
char s[N];
bool check(int i, int j) {
	int pos=(i+j-1), k=1;
	if(pos&1) return 0;
	pos>>=1;
	if(d[pos][j]>=oo) return 0;
	for1(x, j, pos) { if(s[x]!=s[pos+k]) return 0; ++k; }
	return 1;
}
int main() {
	scanf("%s", s+1);
	n=strlen(s+1);
	CC(d, oo);
	d[1][1]=1;
	for1(i, 2, n) {
		for1(j, 1, i-1) d[i][i]=min(d[i-1][j], d[i][i]);
		d[i][i]+=2;
		for1(j, 1, i-1) {
			if(check(i, j)) d[i][j]=d[(i+j-1)>>1][j]+1;
			for1(k, j, i-1) d[i][j]=min(d[i][j], d[k][j]+i-k);
		}
	}
	int ans=oo;
	for1(i, 1, n) ans=min(d[n][i], ans);
	print(ans);
	return 0;
}