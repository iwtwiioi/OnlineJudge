#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
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

const int N=100005, M=10005;
int d[N][20], a[N], w[N], n, o;

void st() {
    for1(i, 1, n) d[i][0]=w[i];
    for(int j=1; (1<<j)<=n; ++j)
        for(int i=1; i+j-1<=n; ++i)
            d[i][j]=max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
}
inline const int getmax(const int &l, const int &r) {
	if(l>r) return -2000000000;
    int s=r-l+1, k=0;
    while((1<<(k+1))<=s) ++k;
    return max(d[l][k], d[r-(1<<k)+1][k]);
}
inline int getpos(const int &x) {
    return lower_bound(a+1, a+1+n, x)-a;
}

int main() {
    read(n);
    for1(i, 1, n) { read(a[i]); read(w[i]); }
    read(o);
    st();
    int x, y, m, r, l, ans;
    for1(i, 1, o) {
        read(x); read(y);
        l=getpos(x), r=getpos(y);
        bool nl=(l<=n && a[l]==x), nr=(r<=n && a[r]==y);
        if(nl) {
            if(nr) {
                m=getmax(l+1, r-1);
                if(w[l]<w[r]) ans=0;
                else if(m<w[r]) {
                    if(r-l==y-x) ans=1;
                    else ans=-1;
                }
                else ans=0;
            }
            else {
                m=getmax(l+1, r-1);
                if(m<w[l]) ans=-1;
                else ans=0;
            }
        }
        else {
            if(nr) {
                m=getmax(l, r-1);
                if(m<w[r]) ans=-1;
                else ans=0;
            }
            else ans=-1;
        }
        if(ans==1) puts("true");
        else if(ans==-1) puts("maybe");
        else puts("false");
    }
    return 0;
}

