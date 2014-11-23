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
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }

const int oo=~0u>>2;
int n, m;
struct node *null;
struct node {
	node *ch[2], *fa;
	bool rev, tag;
	int sum, s, mx, mxl, mxr, w;
	void pushup() {
		s=1+ch[0]->s+ch[1]->s;
		sum=ch[0]->sum+ch[1]->sum+w;
		int l=max(0, ch[1]->mxl), r=max(0, ch[0]->mxr);
		mxl=max(ch[0]->mxl, ch[0]->sum+w+l);
		mxr=max(ch[1]->mxr, ch[1]->sum+w+r);
		mx=max(l+w+r, max(ch[0]->mx, ch[1]->mx));
	}
	void upd(const int &k) {
		if(this==null) return;
		w=k;
		sum=s*k;
		mx=mxl=mxr=max(k, k*s);
		tag=true;
	}
	void upd2() {
		if(this==null) return;
		rev=!rev;
		swap(ch[0], ch[1]);
		swap(mxl, mxr);
	}
	void pushdown() {
		if(rev) {
			rev=false;
			ch[0]->upd2();
			ch[1]->upd2();
		}
		if(tag) {
			tag=false;
			ch[0]->upd(w);
			ch[1]->upd(w);
		}
	}
	bool d() { return fa->ch[1]==this; }
	void setc(node *c, bool d) { ch[d]=c; c->fa=this; }
	void init(const int &k) { sum=mx=mxl=mxr=w=k; }
	void set(int c=0) { ch[0]=ch[1]=fa=null; rev=tag=false; sum=w=mx=mxl=mxr=c; s=1; }
}*root, *s[1000005];
void rot(node *x) {
	node *fa=x->fa;
	fa->pushdown(); x->pushdown(); bool d=x->d();
	fa->fa->setc(x, fa->d());
	fa->setc(x->ch[!d], d);
	x->setc(fa, !d);
	fa->pushup();
	if(fa==root) root=x;
}
void splay(node *x, node *fa=null) {
	x->pushdown();
	while(x->fa!=fa)
		if(x->fa->fa==fa) rot(x);
		else x->d()==x->fa->d()?(rot(x->fa), rot(x)):(rot(x), rot(x));
	x->pushup();
}
node *sel(node *x, const int &k) {
	x->pushdown();
	int s=x->ch[0]->s;
	if(s==k) return x;
	if(k>s) return sel(x->ch[1], k-s-1); return sel(x->ch[0], k);
}
node *getrange(const int &l, const int &r) {
	splay(sel(root, l-1));
	splay(sel(root, r+1), root);
	return root->ch[1];
}
int top;
node *newnode(int c=0) {
	node *ret;
	if(top) ret=s[top--];
	else ret=new node;
	ret->set(c);
	return ret;
}
void build(node *&x, const int &l, const int &r) {
	if(l>r) return;
	x=newnode();
	if(l==r) { x->init(getint()); return; }
	int m=(l+r)>>1;
	build(x->ch[0], l, m-1);
	x->init(getint());
	build(x->ch[1], m+1, r);
	if(l<=m-1) x->ch[0]->fa=x;
	if(m+1<=r) x->ch[1]->fa=x;
	x->pushup();
}
void insert() {
	int pos=getint(), tot=getint();
	node *x;
	build(x, 1, tot);
	node *fa=getrange(pos+1, pos); //注意getrange的地方
	fa->setc(x, 0);
	root->ch[1]->pushup();
	root->pushup();
}
void cln(node *x) {
	if(x==null) return;
	cln(x->ch[0]);
	cln(x->ch[1]);
	s[++top]=x;
}
void dele() {
	int l=getint(), r=l+getint()-1;
	node *fa=getrange(l, r);
	cln(fa->ch[0]);
	fa->ch[0]=null;
	root->ch[1]->pushup();
	root->pushup();
}
void ask1() {
	int l=getint(), r=l+getint()-1;
	node *x=getrange(l, r)->ch[0];
	printf("%d\n", x->sum);
}
void ask2() {
	node *x=getrange(1, root->s-2)->ch[0];
	printf("%d\n", x->mx);
}
void fix1() {
	int l=getint(), r=l+getint()-1, c=getint();
	node *x=getrange(l, r)->ch[0];
	x->upd(c);
	root->ch[1]->pushup();
	root->pushup();
}
void fix2() {
	int l=getint(), r=l+getint()-1;
	node *x=getrange(l, r)->ch[0];
	x->upd2();
	root->ch[1]->pushup();
	root->pushup();
}
void init() {
	null=newnode(-oo);
	null->ch[0]=null->ch[1]=null->fa=null; null->s=null->sum=null->w=0;
	root=newnode();
	node *c=newnode();
	root->setc(c, 1);

	node *t;
	build(t, 1, n);
	root->ch[1]->setc(t, 0);
	root->ch[1]->pushup();
	root->pushup();
}
int main() {
	read(n); read(m);
	init();
	char s[15];
	for1(i, 1, m) {
		scanf("%s", s+1);
		char ch=s[3];
		if(ch=='S') insert();		//INSERT
		else if(ch=='L') dele();	//DELETE
		else if(ch=='T') ask1();	//GET-SUM
		else if(ch=='X') ask2();	//MAX-SUM
		else if(ch=='K') fix1();	//MAKE-SAME
		else if(ch=='V') fix2();	//REVERSE
		//P(root, 1);
	}
	return 0;
}