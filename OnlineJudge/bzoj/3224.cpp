#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;
const int oo=~0u>>1;
struct node {
	node* ch[2];
	int key, size, wei, cnt;
	node(int _key, node* f) { ch[0]=ch[1]=f; key=_key; size=cnt=1; wei=rand(); }
	void pushup() { size=ch[0]->size+ch[1]->size+cnt; }
};

struct Treap {
	node *null, *root;
	Treap() {
		null=new node(0, 0);
		null->size=null->cnt=0;  null->wei=oo;
		root=null;
	}
	void rot(node* &rt, bool d) {
		node* c=rt->ch[!d]; rt->ch[!d]=c->ch[d]; c->ch[d]=rt;
		rt->pushup(); c->pushup();
		rt=c;
	}
	void insert(const int &key, node* &rt) {
		if(rt==null) { rt=new node(key, null); return; }
		if(key==rt->key) {
			rt->cnt++; rt->size++;
			return;
		}
		bool d=key>rt->key;
		insert(key, rt->ch[d]);
		if(rt->wei>rt->ch[d]->wei) rot(rt, !d);
		rt->pushup();
	}
	void remove(const int &key, node* &rt) {
		if(rt==null) return;
		bool d=key>rt->key;
		if(key==rt->key) {
			if(rt->cnt>1) { rt->cnt--; rt->size--; return; }
			d=rt->ch[0]->wei>rt->ch[1]->wei;
			if(rt->ch[d]==null) {
				delete rt;
				rt=null;
				return;
			}
			rot(rt, !d);
			remove(key, rt->ch[!d]);
		}
		else remove(key, rt->ch[d]);
		rt->pushup();
	}
	node* select(int k, node* rt) {
		int s=rt->ch[0]->size+rt->cnt;
		if(k>=rt->ch[0]->size+1 && k<=s) return rt;
		if(s>k) return select(k, rt->ch[0]);
		else return select(k-s, rt->ch[1]);
	}
	int rank(const int &key, node* rt) {
		if(rt==null) return 0;
		int s=rt->ch[0]->size+rt->cnt;
		if(key==rt->key) return rt->ch[0]->size+1;
		if(key<rt->key) return rank(key, rt->ch[0]);
		else return s+rank(key, rt->ch[1]);
	}
	int suc(const int &k) {
		node* t=root;
		int ret=0;
		while(t!=null) {
			if(t->key>k) {
				ret=t->key;
				t=t->ch[0];
			}
			else t=t->ch[1];
		}
		return ret;
	}
	int pre(const int &k) {
		node* t=root;
		int ret=0;
		while(t!=null) {
			if(t->key<k) {
				ret=t->key;
				t=t->ch[1];
			}
			else t=t->ch[0];
		}
		return ret;
	}
};

int main() {
	int n, a, b;
	srand(time(0));
	Treap tree;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &a, &b);
		if(a==1) tree.insert(b, tree.root);
		else if(a==2) tree.remove(b, tree.root);
		else if(a==3) printf("%d\n", tree.rank(b, tree.root));
		else if(a==4) printf("%d\n", tree.select(b, tree.root)->key);
		else if(a==5) printf("%d\n", tree.pre(b));
		else if(a==6) printf("%d\n", tree.suc(b));
	}
	return 0;
}

