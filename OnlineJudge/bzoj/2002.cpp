#include <cstdio>
#define read(x) x=getint()

using namespace std;
inline int getint() { char c; int ret=0; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=200005;
struct node* null;
struct node {
	node *f, *ch[2];
	int s;
	void pushup() { s=1+ch[0]->s+ch[1]->s; }
	bool d() { return f->ch[1]==this; }
	void setc(node* c, bool d) { ch[d]=c; c->f=this; }
	bool check() { return  f==null || (f->ch[0]!=this && f->ch[1]!=this); }
}*nd[N];

void rot(node* r) {
	node* f=r->f; bool d=r->d();
	if(f->check()) r->f=f->f;
	else f->f->setc(r, f->d());
	f->setc(r->ch[!d], d);
	r->setc(f, !d);
	f->pushup();
}

inline void splay(node* r) {
	while(!r->check())
		if(r->f->check()) rot(r);
		else r->d()==r->f->d()?(rot(r->f), rot(r)):(rot(r), rot(r));
	r->pushup();
}

inline void access(node* f) {
	for(node* c=null; f!=null; f=f->f) {
		splay(f);
		f->setc(c, 1);
		f->pushup();
		c=f;
	}
}

inline void link(node* c, node* f) {
	access(c); splay(c);
	c->ch[0]->f=null; c->ch[0]=null; c->f=f; c->pushup();
}

inline void init() {
	null=new node; null->s=0; null->f=null->ch[0]=null->ch[1]=null;
}

int main() {
	init();
	int n, t; read(n);
	for(int i=0; i<n; ++i) { nd[i]=new node; nd[i]->s=1; nd[i]->ch[0]=nd[i]->ch[1]=nd[i]->f=null; }
	for(int i=0; i<n; ++i) {
		read(t);
		if(i+t<n) nd[i]->f=nd[i+t];
	}
	int m, a, b, c; read(m);
	for(int i=0; i<m; ++i) {
		read(a); read(b);
		if(a==1) {
			access(nd[b]);
			splay(nd[b]);
			printf("%d\n", nd[b]->s);
		}
		else {
			read(c);
			if(b+c<n) link(nd[b], nd[b+c]);
			else link(nd[b], null);
		}
	}
	return 0;
}

