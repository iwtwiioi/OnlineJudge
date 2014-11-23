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

const int N=100005;
int getans(int *a, int *b, int n) {
	int h1=1, t1=n, ret=0, h2=1, t2=n;
	while(h1<=t1) {
		if(a[h1]>b[h2]) { ret+=2; ++h1; ++h2; continue; }
		if(a[t1]>b[t2]) { ret+=2; --t1; --t2; continue; }
		if(a[h1]==b[t2])  ret+=1;
		++h1, --t2;
	}
	return ret;
}
int n, ans1, ans2;
int a[N], b[N];
int main() {
	read(n);
	for1(i, 1, n) read(a[i]);
	for1(i, 1, n) read(b[i]);
	sort(a+1, a+1+n);
	sort(b+1, b+1+n);
	printf("%d %d\n", getans(a, b, n), 2*n-getans(b, a, n));
	return 0;
}