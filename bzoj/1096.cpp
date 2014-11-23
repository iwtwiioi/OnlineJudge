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

const int N=1000005;
int n, q[N], front, tail;
ll x[N], p[N], c[N], sum[N], b[N], f[N];
#define F(x) (f[x]+b[x])
#define E(k,j) (F(k)-F(j))
#define S(k,j) (sum[k]-sum[j])

int main() {
	read(n);
	for1(i, 1, n) read(x[i]), read(p[i]), read(c[i]);
	for1(i, 1, n) sum[i]=sum[i-1]+p[i];
	for1(i, 1, n) b[i]=b[i-1]+p[i]*x[i];
	tail=1;
	for1(i, 1, n) {
		while(front<tail-1 && E(q[front+1], q[front])<x[i]*S(q[front+1], q[front])) ++front;
		int j=q[front];
		f[i]=f[j]+(sum[i]-sum[j])*x[i]-(b[i]-b[j])+c[i];
		while(front<tail-1 && E(q[tail-1], q[tail-2])*S(i, q[tail-1])>E(i, q[tail-1])*S(q[tail-1], q[tail-2])) --tail;
		q[tail++]=i;
	}
	printf("%lld", f[n]);
	return 0;
}
