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

const int N=100005, oo=~0u>>1;
int p[N], sum[N], front, c, n, ans, mx;
struct dat { int x, y; }a[N];
multiset<dat> s;
set<dat>::iterator it;
inline const bool operator< (const dat &a, const dat &b) { return a.x<b.x; }
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
inline void un(const int &x, const int &y) { int fx=ifind(x), fy=ifind(y); if(fx!=fy) p[fx]=fy, --ans; }

int main() {
	read(n); read(c);
	int x, y; ans=n;
	for1(i, 1, n) read(x), read(y), a[i].x=x+y, a[i].y=x-y, p[i]=i;
	sort(a+1, a+1+n); front=1;
	s.insert((dat){oo, 0}); s.insert((dat){-oo, 0});
	for1(i, 1, n) {
		while(a[i].x-a[front].x>c) {
			s.erase(s.lower_bound((dat){a[front].y, front}));
			++front;
		}
		long long y=a[i].y;
		it=s.lower_bound((dat){a[i].y, i});
		dat r=*it, l=*--it;
		if((long long)r.x-y <= c) un(r.y, i);
		if(y-(long long)l.x <= c) un(l.y, i);
		s.insert((dat){a[i].y, i});
	}
	for1(i, 1, n) ++sum[ifind(i)];
	for1(i, 1, n) mx=max(mx, sum[i]);
	printf("%d %d", ans, mx);
	return 0;
}

