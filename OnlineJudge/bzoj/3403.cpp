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
int q[N], n, front, tail;

inline void fix(int &x) { if(x<0) x=N+x; if(x>=N) x-=N; }
int main() {
    read(n);
    int cnt=0;
    for1(i, 1, n) {
        char ch=getchar(); while(ch<'A'||ch>'Z') ch=getchar();
        if(ch=='A') {
            ch=getchar(); while(ch<'A'||ch>'Z') ch=getchar();
            if(ch=='L') { --front; fix(front); q[front]=++cnt; }
            else if(ch=='R') q[tail++]=++cnt, fix(tail);
        }
        else if(ch=='D') {
            ch=getchar(); while(ch<'A'||ch>'Z') ch=getchar();
            int t=getint();
            if(ch=='L') front+=t, fix(front);
            else if(ch=='R') tail-=t, fix(tail);
        }
    }
    while(front!=tail) {
        printf("%d\n", q[front++]); fix(front);
    }
    return 0;
}