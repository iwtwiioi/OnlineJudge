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
//good morning
int a[10], T, b[10]={1,2,3,1,1,1,2,1};
string s;

int main() {
	read(T);
	//ios::sync_with_stdio(false);
	for1(tt, 1, T) {
		getline(cin, s); //dbg(s);
		CC(a, 0);
		rep(i, s.size()) {
			switch(s[i]) {
				case ' ': ++a[0]; break;
				case 'g': ++a[1]; break;
				case 'o': ++a[2]; break;
				case 'd': ++a[3]; break;
				case 'm': ++a[4]; break;
				case 'r': ++a[5]; break;
				case 'n': ++a[6]; break;
				case 'i': ++a[7]; break;
			}
		}
		int ans=10000;
		rep(i, 8) ans=min(ans, a[i]/b[i]);
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}