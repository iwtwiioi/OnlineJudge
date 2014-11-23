#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define dbg(x) cout << #x << "=" << x << endl
#define read(x) x=getint()
#define for1(i, a, n) for(int i=a; i<=(n); ++i)
#define MID (l+r)>>1
inline int getint() { char c; int ret=0, k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret*k; }
 
const int N=100010;
int id[N], a[N], b[N], n, m, root[N], cnt, key;
struct node { int l, r, s; } T[N*50];
void update(const int &l, const int &r, int &pos) {
    T[++cnt]=T[pos]; pos=cnt; ++T[pos].s;
    if(l==r) return;
    int m=MID;
    if(key<=m) update(l, m, T[pos].l); else update(m+1, r, T[pos].r);
}
int query(const int &l, const int &r, const int &x, const int &y, const int &k) {
    if(l==r) return l;
    int m=MID, s=T[T[y].l].s-T[T[x].l].s;
    if(k<=s) return query(l, m, T[x].l, T[y].l, k); else return query(m+1, r, T[x].r, T[y].r, k-s);
}
bool cmp(const int &x, const int &y) { return a[x]<a[y]; }
int main() {
    read(n); read(m);
    for1(i, 1, n) read(a[i]), id[i]=i;
    sort(id+1, id+1+n, cmp);
    for1(i, 1, n) b[id[i]]=i;
    for1(i, 1, n) {
        root[i]=root[i-1]; key=b[i];
        update(1, n, root[i]);
    }
    int x, y;
    while(m--) {
        read(x); read(y); read(key);
        printf("%d\n", a[id[query(1, n, root[x-1], root[y], key)]]);
    }
    return 0;
}