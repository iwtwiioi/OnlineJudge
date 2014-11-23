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
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=100005;
int n;
struct nod { int a, b; }cow[N];
bool cmp(const nod &a, const nod &b) { return b.a*a.b>a.a*b.b; }
int main() {
	read(n);
	for1(i, 1, n) read(cow[i].a), read(cow[i].b);
	long long ans=0, sum=0;
	sort(cow+1, cow+1+n, cmp);
	for1(i, 1, n) sum+=cow[i].b;
	for1(i, 1, n) {
		sum-=cow[i].b;
		ans+=cow[i].a*sum;
	}
	printf("%lld", ans<<1);
	return 0;
}

