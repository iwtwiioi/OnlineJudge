#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define for1(i,a,n) for(i=a;i<=n;++i)
#define for2(i,a,n) for(i=a;i<n;++i)
#define for3(i,a,n) for(i=a;i>=n;--i)
#define for4(i,a,n) for(i=a;i>n;--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int N=1005;
int s[N], p[N];

int ifind(const int &x) {
	if(x==p[x]) return x;
	int fa=p[x]; p[x]=ifind(p[x]);
	s[x]+=s[fa];
	return p[x];
}

int main() {
	int n, m, w, i, t, x, y, fx, fy, ok;
	read(w);
	while(w--) {
		read(n); read(m);
		ok=1;
		CC(s, 0);
		for1(i, 0, n+2) p[i]=i;
		for1(i, 1, m) {
			read(x); read(y); read(t); --x;
			fx=ifind(x); fy=ifind(y);
			if(fx!=fy) {
				p[fx]=fy;
				s[fx]=s[y]-s[x]+t;
			}
			else if(s[x]-s[y]!=t) { ok=0; break; }
		}
		ok?puts("true"):puts("false");
	}
	return 0;
}

