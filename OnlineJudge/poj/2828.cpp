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

const int N=200005;
int n;
struct node* null;
struct node {
	int key, s;
	node *ch[2], *fa;
	node(const int &_k=0, const int &_s=1) : key(_k), s(_s) { ch[0]=ch[1]=fa=null; }
	inline void setc(node* c, const bool d) { ch[d]=c; c->fa=this; }
	inline int d() { return fa->ch[1]==this; }
	inline void pushup() { s=1+ch[0]->s+ch[1]->s; }
}*root;
inline void rot(node* r) {
	node* fa=r->fa; bool d=r->d();
	fa->fa->setc(r, fa->d());
	fa->setc(r->ch[!d], d);
	r->setc(fa, !d);
	fa->pushup();
	if(fa==root) root=r;
}
inline void splay(node* r, node* fa) {
	while(r->fa!=fa) 
		if(r->fa->fa==fa) rot(r);
		else r->d()==r->fa->d()?(rot(r->fa), rot(r)):(rot(r), rot(r));
	r->pushup();
}
inline node* select(node* r, const int &k) {
	if(r==null) return null;
	int s=r->ch[0]->s+1;
	if(s==k) return r;
	if(s>k) return select(r->ch[0], k);
	else return select(r->ch[1], k-s);
}
void getans(node* r) {
	if(r==null) return;
	getans(r->ch[0]);
	printf("%d ", r->key);
	getans(r->ch[1]);
	delete r;
}
int main() {
	null=new node(0, 0); null->ch[0]=null->ch[1]=null->fa=null;
	int pos, id;
	while(~scanf("%d", &n)) {
		root=null;
		rep(i, n) {
			read(pos); read(id);
			++pos;
			node* c=new node(id);
			if(root==null) root=c;
			else if(pos>root->s) {
				splay(select(root, root->s), null);
				root->setc(c, 1);
				splay(c, null);
			}
			else {
				splay(select(root, pos), null);
				c->setc(root->ch[0], 0);
				c->pushup();
				root->setc(c, 0);
				splay(c, null);
			}
		}
		getans(root);
		puts("");
	}
	return 0;
}

