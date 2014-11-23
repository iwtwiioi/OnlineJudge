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
int n, k, front, tail, q[N], d[N], vis[N];
void add(int x) { if(vis[x]) return; vis[x]=1; q[tail++]=x; if(tail==N) tail=0; }
int main() {
	read(n); read(k);
	int mx=max(n, k)+1, t;
	q[tail++]=n;
	CC(d, 0x7f); d[n]=0;
	while(front!=tail) {
		t=q[front++]; if(front==N) front=0; vis[t]=0;
		if(t==k) break;
		int dt=d[t]+1;
		if(t>0 && dt+1<d[t-1]) d[t-1]=dt, add(t-1);
		if(t<mx && dt<d[t+1]) d[t+1]=dt, add(t+1);
		if((t<<1)<=mx && dt<d[t<<1]) d[t<<1]=dt, add(t<<1);
	}
	print(d[k]);
	return 0;
}

