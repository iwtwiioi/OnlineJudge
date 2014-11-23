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
#define printarr2(a, b, c) for1(_, 1, b) { rep(__, c) cout << a[_][__] << '\t'; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
 
const int N=1500005;
int ihead[N], cnt, n, f[N][2], st[N], r[N];
ll MD, sumr[N], d[N][2];
struct ED { int next, to; }e[N<<1];
void add(int u, int v) {
    e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
    e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
void dp(int x, int fa) {
    int t0=0; ll s0=1;
    for(int i=ihead[x]; i; i=e[i].next) if(e[i].to!=fa) {
        int y=e[i].to;
        dp(y, x);
        int mx=max(f[y][0], f[y][1]); ll tp=0;
        if(f[y][0]==mx) tp+=d[y][0];
        if(f[y][1]==mx) tp+=d[y][1];
        s0=(s0*tp)%MD;
        t0+=mx;
    }
    f[x][0]=t0;
    d[x][0]=s0;
    int sz=0, l=0; ll suml=1;
    for(int i=ihead[x]; i; i=e[i].next) if(e[i].to!=fa) st[++sz]=e[i].to;
    sumr[sz+1]=1; r[sz+1]=0;
    for3(i, sz, 1) {
        int mx=max(f[st[i]][0], f[st[i]][1]); ll tp=0;
        if(mx==f[st[i]][0]) tp+=d[st[i]][0];
        if(mx==f[st[i]][1]) tp+=d[st[i]][1];
        r[i]=r[i+1]+mx;
        sumr[i]=(sumr[i+1]*tp)%MD;
    }
    f[x][1]=-N;
    for1(i, 1, sz) {
        int tp=l+f[st[i]][0]+r[i+1]+1;
        if(tp>f[x][1]) {
            f[x][1]=tp;
            d[x][1]=(d[st[i]][0]*((suml*sumr[i+1])%MD))%MD;
        }
        else if(tp==f[x][1]) {
            d[x][1]=d[x][1]+(d[st[i]][0]*((suml*sumr[i+1])%MD))%MD;
        }
        int mx=max(f[st[i]][0], f[st[i]][1]); s0=0;
        if(mx==f[st[i]][0]) s0+=d[st[i]][0];
        if(mx==f[st[i]][1]) s0+=d[st[i]][1];
        suml=(suml*s0)%MD;
        l+=mx;
    }
}
 
int main() {
    read(n);
    for1(i, 1, n-1) add(getint(), getint());
    read(MD);
    int root=(n+1)>>1;
    dp(root, -1);
    int ans1=max(f[root][0], f[root][1]); ll ans2=0;
    if(ans1==f[root][0]) ans2+=d[root][0];
    if(ans1==f[root][1]) ans2+=d[root][1];
    printf("%d\n%lld\n", ans1, ans2%MD);
    return 0;
}