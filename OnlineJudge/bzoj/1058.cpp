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
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=500005, oo=~0u>>2;
set<int> s;
int b[N], n, m, ans2=oo, cnt;
struct node *null;
struct node {
    node *ch[2], *fa;
    int mn, w, s, v;
    node() { ch[0]=ch[1]=fa=null; mn=oo; w=oo; s=1; v=oo; }
    void pushup() { mn=w; mn=min(mn, min(ch[0]->mn, ch[1]->mn)); s=1+ch[0]->s+ch[1]->s; }
    bool d() { return fa->ch[1]==this; }
    void setc(node *c, bool d) { c->fa=this; ch[d]=c; }
}*root, *arr[N];
void rot(node *x) {
    node *fa=x->fa; bool d=x->d();
    fa->fa->setc(x, fa->d());
    fa->setc(x->ch[!d], d);
    x->setc(fa, !d);
    fa->pushup();
    if(fa==root) root=x;
}
void splay(node *x, node *fa=null) {
    while(x->fa!=fa)
        if(x->fa->fa==fa) rot(x);
        else x->d()==x->fa->d()?(rot(x->fa), rot(x)):(rot(x), rot(x));
    x->pushup();
}
node *sel(node *x, int k) {
    if(x==null) return null;
    int s=x->ch[0]->s;
    if(k==s) return x;
    if(k>s) return sel(x->ch[1], k-s-1); else return sel(x->ch[0], k);
}
node *getpos(int pos) {
    splay(sel(root, pos));
    splay(sel(root, pos+1), root);
    return root->ch[1];
}
void fix(int pos, int v, const bool flag) {
    node *fa=getpos(pos);
    node *c=new node;
    c->v=v; 
    if(fa->ch[1]!=null) c->w=abs(v-fa->v);
    fa->setc(c, 0);
    if(root->ch[0]!=null) root->w=abs(root->v-v);
    if(flag) { arr[++cnt]=c; }
    splay(c); 
}
void work1() { printf("%d\n", root->mn); }
void work2() { printf("%d\n", ans2); }
void maintain(const int &b) {
    set<int>::iterator it=s.lower_bound(b);
    ans2=min(ans2, abs(*it-b)); --it;
    ans2=min(ans2, abs(*it-b));
    s.insert(b);
}
void insert() {
    int x=getint(), y=getint();
    maintain(y);
    node *it=arr[x];
    splay(it);
    fix(it->ch[0]->s+b[x], y, 0);
    ++b[x];
}
void build() {
    int t;
    for1(i, 1, n) {
        read(t);
        maintain(t);
        fix(i-1, t, 1);
    }
}
void init() {
    s.insert(oo);
    s.insert(-oo);
    null=new node;
    null->ch[0]=null->ch[1]=null->fa=null; null->s=0;
    root=new node;
    node *c=new node;
    root->setc(c, 1);
}
void pri(node *x=root) {
    if(x==null) return;
    pri(x->ch[0]);
    printf("%d ", x->v);
    pri(x->ch[1]);
}
int main() {
    read(n); read(m);
    init();
    build();
    char od[20];
    for1(i, 1, m) {
        scanf("%s", od+1);
        if(od[5]=='R') insert();
        else if(od[5]=='G') work1();
        else if(od[5]=='S') work2();
    }
    //pri();
    return 0;
}