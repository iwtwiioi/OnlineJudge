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

const int N=17, oo=0x3f3f3f3f;
int f[1<<N], n, m, s, sum[N];
struct dat { int c, s; }a[105], b[105];

void readin(dat arr[], int n) {
	for1(i, 1, n) {
		arr[i].s=0; arr[i].c=oo;
		read(arr[i].c); //dbg(arr[i].c);
		char ch=getchar();
		int r=0;
		while(ch!='\n' && ch!='\r') {
			if(ch<'0'||ch>'9') {
				if(r!=0) arr[i].s|=(3<<((r-1)<<1));
				r=0;
				while(ch<'0'||ch>'9') {
					ch=getchar();
					if(ch=='\n' || ch=='\r') break;
				}
				if(ch=='\n' || ch=='\r') break;
			}
			r=r*10+ch-'0';
			ch=getchar();
		}
		if(r!=0) arr[i].s|=(3<<((r-1)<<1));
		//rep(k, s) if(arr[i].s&(3<<(k<<1))) printf("%d ", k+1);
		//puts("");
	}
}
void Prin(int x) {
	for3(k, ((s-1)<<1)+1, 0) { printf("%d", (bool)(x&(1<<k))); if((k&1)==0) printf(" "); }
	puts("");
}
int main() {
	read(s); read(n); read(m);
	while(s) {
		int all=(1<<(s<<1))-1;
		CC(f, 0x3f); CC(sum, 0);
		readin(a, n); readin(b, m);

		int tc=0, tn=0;
		for1(i, 1, n) rep(k, s) if((a[i].s>>(k<<1))&3) sum[k]++;
		rep(k, s) if(sum[k]) {
			int t=1;
			if(sum[k]>=2) t=3;
			tc|=(t<<(k<<1));
		}
		for1(i, 1, n) tn+=a[i].c;
		f[tc]=tn;

		for1(i, 1, m) {
			//dbg(i);
			for3(j, all, 0) if(f[j]!=oo) {
			int nx=0; //Prin(j);
			rep(k, s) if(b[i].s&(3<<(k<<1))) {
				int now=(j>>(k<<1))&3;
				if(now==0 || now==2) nx|=1<<(k<<1);
				if(now==1 || now==3) nx|=2<<(k<<1);
			}
			f[j|nx]=min(f[j|nx], f[j]+b[i].c); //Prin(nx); Prin(j|nx); puts("");
		} }
		if(f[all]==oo) f[all]=-1;
		printf("%d\n", f[all]);
		read(s); read(n); read(m);
	}
	return 0;
}