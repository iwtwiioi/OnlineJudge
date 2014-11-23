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
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=100005;
struct dat { int x, y; }a[N], b[N];
inline const bool cmp(const dat &x, const dat &y) { return x.y>y.y; }
multiset<int> s;
typedef multiset<int>::iterator iit;
int n, m;

int main() {
	read(n); read(m);
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	for1(i, 1, m) read(b[i].x), read(b[i].y);
	sort(a+1, a+1+n, cmp); sort(b+1, b+1+m, cmp);
	int j=1;
	long long ans=0;
	for1(i, 1, n) {
		while(a[i].y<=b[j].y && j<=m) { s.insert(b[j].x); ++j; }
		iit it=s.lower_bound(a[i].x);
		if(it==s.end()) { puts("-1"); return 0; }
		ans+=*it;
		s.erase(it);
	}
	printf("%lld", ans);
	return 0;
}

