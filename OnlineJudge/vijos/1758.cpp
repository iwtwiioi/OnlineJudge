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

const int Q=1000005;
struct dat { int a[11], d; }q1[Q], q2[Q];
int front1, tail1, front2, tail2, n, m, ans=~0u>>1, vis1[2000], vis2[2000];
int main() {
	int sum=0;
	read(n); for1(i, 1, n) read(q1[0].a[i]), sum+=q1[0].a[i];
	read(m); for1(i, 1, m) read(q2[0].a[i]), sum-=q2[0].a[i];
	if(sum) { puts("-1"); return 0; }
	tail1=tail2=1;
	q1[0].a[0]=n; q1[0].d=0;
	q2[0].a[0]=m; q2[0].d=0;
	sort(q1[0].a+1, q1[0].a+1+n);
	sort(q2[0].a+1, q2[0].a+1+m);
	if(n==m) {
		int i;
		for(i=1; i<=n; ++i) if(q1[0].a[i]!=q2[0].a[i]) break;
		if(i>n) { puts("0"); return 0; }
	}
	CC(vis1, -1); CC(vis2, -1);
	vis1[(1<<n)-1]=0;
	vis2[(1<<m)-1]=0;
	while(front1!=tail1 || front2!=tail2) {
		if(front1!=tail1) {
			dat &t=q1[front1++]; if(front1==Q) front1=0;
			for1(i, 1, 10) if(t.a[0]&(1<<(i-1)))
				for1(j, 1, 10) if(j!=i && (t.a[0]&(1<<(j-1)))) {
					dat &t2=q1[tail1];
					memcpy(t2.a, t.a, sizeof(t.a));
					t2.a[i]=t2.a[i]+t2.a[j];
					t2.a[0]^=(1<<(j-1));
					if(vis2[t2.a[0]]!=-1) { ans=min(ans, vis2[t2.a[0]]+t.d+1); continue; }
					if(vis1[t2.a[0]]!=-1) continue;
					vis1[t2.a[0]]=t.d+1;
					t2.d=t.d+1;
					if(++tail1==Q) tail1=0;
			}
		}
		if(front2!=tail2) {
			dat &t=q2[front2++]; if(front2==Q) front2=0;
			for1(i, 1, 10) if(t.a[0]&(1<<(i-1)))
				for1(j, 1, 10) if(j!=i && (t.a[0]&(1<<(j-1)))) {
					dat &t2=q2[tail2];
					memcpy(t2.a, t.a, sizeof(t.a));
					t2.a[i]=t2.a[i]+t2.a[j];
					t2.a[0]^=(1<<(j-1));
					if(vis1[t2.a[0]]!=-1) { ans=min(ans, vis1[t2.a[0]]+t.d+1); continue; }
					if(vis2[t2.a[0]]!=-1) continue;
					vis2[t2.a[0]]=t.d+1;
					t2.d=t.d+1;
					if(++tail2==Q) tail2=0;
			}
		}
	}
	if(ans==~0u>>1) ans=-1;
	printf("%d\n", ans);
	return 0;
}