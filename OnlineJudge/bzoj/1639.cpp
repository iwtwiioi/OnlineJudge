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
 
const int N=100005;
int n, m, a[N];
 
inline const bool check(const int &x) {
    int sum=0, t=0, i;
    for(i=1; i<=n; ++i) {
        sum+=a[i];
        if(sum>x) sum=a[i], ++t;
        if(t>=m) return 0;
    }
    return 1;
}
 
int main() {
    read(n); read(m);
    int mx=0, sum=0;
    for1(i, 1, n) { read(a[i]); mx=max(mx, a[i]); sum+=a[i]; }
    int l=mx, r=sum, mid;
    while(l<=r) {
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    print(r+1);
    return 0;
}