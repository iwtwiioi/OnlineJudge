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

const int N=50005;
int s[N], top, h[N], n, L[N], R[N], power[N], sum[N], ans;

void update(int x) {
	bool flag=1;
	while(top) {
		if(h[x]>=h[s[top]]) {
			if(h[x]==h[s[top]]) {
				L[x]=s[top];
				R[top]=x;
				flag=0;
			}
			else R[s[top]]=x;
			--top;
		}
		else break;
	}
	if(flag) L[x]=s[top];
	s[++top]=x;
}

int main() {
	read(n);
	for1(i, 1, n) { read(h[i]); read(power[i]); }
	for1(i, 1, n) update(i);
	for1(i, 1, n) {
		sum[L[i]]+=power[i];
		sum[R[i]]+=power[i];
	}
	for1(i, 1, n) ans=max(ans, sum[i]);
	print(ans);
	return 0;
}

