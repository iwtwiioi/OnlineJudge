#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
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

using namespace std;

const int N=100005;
struct node { 
	double x, y; 
	node(const double &_x=0, const double &_y=0) : x(_x), y(_y) {}
}st[N], p[N];
int cnt, n;
node operator - (const node &a, const node &b) { return node(a.x-b.x, a.y-b.y); }
double cross(const node &a, const node &b) { return a.x*b.y-b.x*a.y; }
const bool cmp(const node &a, const node &b) { return (a.x==b.x)?(a.y<b.y):(a.x<b.x); }
const double dis(const node &a, const node &b) { return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
void tubao() {
	sort(p, p+n, cmp);
	cnt=0;
	rep(i, n) {
		while(cnt>1 && cross(st[cnt-1]-st[cnt-2], p[i]-st[cnt-2])<=0) --cnt;
		st[cnt++]=p[i];
	}
	int k=cnt;
	for3(i, n-2, 0) {
		while(cnt>k && cross(st[cnt-1]-st[cnt-2], p[i]-st[cnt-2])<=0) --cnt;
		st[cnt++]=p[i];
	}
	if(n>1) --cnt;
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%lf%lf", &p[i].x, &p[i].y);
	tubao();
	double ans=0;
	rep(i, cnt) ans+=dis(st[i], st[(i+1)%cnt]);
	printf("%.1lf\n", ans);
	return 0;
}
