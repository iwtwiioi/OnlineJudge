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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

priority_queue<int> id;
const int N=100005, M=200005;
int ihead[N], cnt, n, m, tot, in[N], a[N];
struct ED { int to, next; }e[M];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}

int main() {
	read(n); read(m); tot=n+1;
	rep(i, m) {
		int u=getint(), v=getint();
		add(v, u); ++in[u];
	}
	for1(i, 1, n) if(in[i]==0) id.push(i);
	while(!id.empty()) {
		int u=id.top(); id.pop();
		a[u]=--tot;
		for(int i=ihead[u]; i; i=e[i].next) {
			--in[e[i].to];
			if(in[e[i].to]==0) id.push(e[i].to);
		}
	}
	for1(i, 1, n) printf("%d ", a[i]);
	return 0;
}