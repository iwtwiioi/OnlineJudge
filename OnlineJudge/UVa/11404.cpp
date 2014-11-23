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


const int N=1005;
char s1[N], s2[N];
int f[N][N], mn[N][N];
string p[N][N];
int main() {
	while(~scanf("%s", s1+1)) {
		CC(mn, 0x3f);
		int n=strlen(s1+1);
		for1(i, 1, n) s2[n-i+1]=s1[i];
		for1(i, 1, n) for1(j, 1, n) {
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1, p[i][j]=p[i-1][j-1]+s1[i];
			else {
				f[i][j]=max(f[i-1][j], f[i][j-1]);
				if(f[i-1][j]==f[i][j-1]) p[i][j]=min(p[i-1][j], p[i][j-1]);
				else if(f[i-1][j]>f[i][j-1]) p[i][j]=p[i-1][j];
				else p[i][j]=p[i][j-1];
			}
		}
		int len=(f[n][n]+1)>>1;
		string ans1(p[n][n].begin(), p[n][n].begin()+len);
		string ans2(ans1.rbegin()+(f[n][n]&1), ans1.rend());
		printf("%s\n", (ans1+ans2).c_str());
	}
	return 0;
}