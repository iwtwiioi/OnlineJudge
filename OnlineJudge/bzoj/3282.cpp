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

const int N=300005;
struct node *null;
struct node {
	int v, rev, w;
	node *ch[2], *fa;
	node(const int _v=0) : v(_v), rev(0), w(0) { ch[0]=ch[1]=fa=null; }
	bool d() { return fa->ch[1]==this; }
	bool check() { return fa->ch[0]!=this && fa->ch[1]!=this; }
	void setc(node* c, int d) { ch[d]=c; c->fa=this; }
	void pushup() { w=ch[0]->w^ch[1]->w^v; }
	void pushdown() {
		if(rev) {
			ch[0]->rev^=1;
			ch[1]->rev^=1;
			swap(ch[0], ch[1]);
			rev=0;
		}
	}
}*t[N];
void rot(node* x) {
	node* fa=x->fa; bool d=x->d();
	fa->pushdown(); x->pushdown();
	if(!fa->check()) fa->fa->setc(x, fa->d());
	else x->fa=fa->fa;
	fa->setc(x->ch[!d], d);
	x->setc(fa, !d);
	fa->pushup();
}
void fix(node* x) {
	if(!x->check()) fix(x->fa);
	x->pushdown();
}
void splay(node* x) {
	fix(x);
	while(!x->check())
		if(x->fa->check()) rot(x);
		else x->d()==x->fa->d()?(rot(x->fa), rot(x)):(rot(x), rot(x));
	x->pushup();
}
node* access(node* x) {
	node* y=null;
	for(; x!=null; y=x, x=x->fa) {
		splay(x);
		x->ch[1]=y;
	}
	return y;
}
void mkroot(node* x) { access(x)->rev^=1; splay(x); }
void link(node* x, node* y) { mkroot(x); x->fa=y; }
void cut(node* x, node* y) {
	mkroot(x); access(y); splay(y);
	y->ch[0]->fa=null; y->ch[0]=null;
}
node* findrt(node* x) {
	access(x); splay(x);
	while(x->ch[0]!=null) x=x->ch[0];
	return x;
}
void init() { null=new node; null->ch[0]=null->ch[1]=null->fa=null; }
int n, m;

int main() {
	init();
	read(n); read(m);
	for1(i, 1, n) t[i]=new node(getint());
	rep(i, m) {
		int c=getint(), x=getint(), y=getint();
		if(c==0) { mkroot(t[x]); access(t[y]); splay(t[y]); printf("%d\n", t[y]->w); }
		else if(c==1) { if(findrt(t[x])!=findrt(t[y])) link(t[x], t[y]); }
		else if(c==2) { if(findrt(t[x])==findrt(t[y])) cut(t[x], t[y]); }
		else if(c==3) { mkroot(t[x]); t[x]->v=y; t[x]->pushup(); }
	}
	return 0;
}