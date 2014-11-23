#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << "=" << x << endl;
#define dbgarr(a, n) for1(i, 0, n) cout << a[i] << " "; cout << endl

inline int getnum() { int ret=0, k=1; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret*k; }

const int N=10005;
int n, m;

struct node* null;
struct node {
	node* ch[2], *fa;
	bool rev;
	bool d() const { return fa->ch[1]==this; }
	void setc(node* c, bool d) { ch[d]=c; c->fa=this; }
	bool check() const { return fa->ch[0]!=this && fa->ch[1]!=this; }
	void pushdown() {
		if(rev) {
			ch[0]->rev^=true;
			ch[1]->rev^=true;
			swap(ch[0], ch[1]);
			rev=false;
		}
	}
}*nd[N];

inline void rot(node* r) {
	node* fa=r->fa; bool d=r->d();
	fa->pushdown(); r->pushdown();
	if(fa->check()) r->fa=fa->fa;
	else fa->fa->setc(r, fa->d());
	fa->setc(r->ch[!d], d);
	r->setc(fa, !d);
}

void fix(node* x) {
	if(!x->check()) fix(x->fa);
	x->pushdown();
}

inline void splay(node* r) {
	fix(r);
	while(!r->check())
		if(r->fa->check()) rot(r);
		else rot(r), rot(r);
}

inline node* access(node* x) {
	node* y=null;
	for(; x!=null; y=x, x=x->fa) {
		splay(x);
		x->ch[1]=y;
	}
	return y;
}

inline void mkroot(node* x) {
	access(x)->rev^=true; splay(x);
}

inline void link(node* x, node* y) {
	mkroot(x); x->fa=y;
}

inline void cut(node* x, node* y) {
	mkroot(x);
	access(y); splay(y);
	y->ch[0]->fa=null; y->ch[0]=null;
}

inline node* findrt(node* x) {
	access(x); splay(x);
	while(x->ch[0]!=null) x=x->ch[0];
	return x;
}

int main() {
	read(n); read(m);
	null=new node; null->fa=null->ch[0]=null->ch[1]=null; null->rev=false;
	char s[10];
	int u, v;
	for1(i, 1, n) { 
		nd[i]=new node;
		nd[i]->fa=nd[i]->ch[0]=nd[i]->ch[1]=null; nd[i]->rev=false;
	}
	rep(i, m) {
		scanf("%s", s);
		read(u); read(v);
		if(s[0]=='Q')
			findrt(nd[u])==findrt(nd[v])?(printf("Yes\n")):(printf("No\n"));
		else if(s[0]=='C') link(nd[u], nd[v]);
		else cut(nd[u], nd[v]);
	}
	
	return 0;
}

