#include <cstdio>
#include <cstdlib>
using namespace std;
#define lowbit(x) (x&-x)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int oo=~0u>>1, N=50005;
int a[N], cnt;

struct node {
	node* ch[2];
	int key, size, wei, cnt;
	node() { ch[0]=ch[1]=NULL; key=size=cnt=0; wei=rand(); }
	void pushup() { size=ch[0]->size+ch[1]->size+cnt; }
}*null;
struct Treap {
	node* root;
	Treap() { root=null; }
	void rot(node* &rt, bool d) {
		node* c=rt->ch[!d]; rt->ch[!d]=c->ch[d]; c->ch[d]=rt;
		rt->pushup(); c->pushup();
		if(root==rt) root=c;
		rt=c;
	}
	node* newnode(const int &key) {
		node* ret=new node;
		ret->key=key; ret->size=ret->cnt=1;
		ret->ch[0]=ret->ch[1]=null;
		return ret;
	}
	void insert(const int &key, node* &rt) {
		if(rt==null) { rt=newnode(key); return; }
		if(key==rt->key) { rt->cnt++; rt->size++; return; }
		bool d=key>rt->key;
		insert(key, rt->ch[d]);
		if(rt->wei>rt->ch[d]->wei) rot(rt, !d);
		rt->pushup();
	}
	void remove(const int &key, node* &rt) {
		if(rt==null) return;
		int d=key>rt->key;
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
	int rank(const int &key) {
		int ret=0, s;
		for(node* t=root; t!=null;) {
			s=t->ch[0]->size+t->cnt;
			if(key>t->key) ret+=s, t=t->ch[1];
			else t=t->ch[0];
		}
		return ret;
	}
	int suc(const int &key) {
		int ret=oo+1;
		for(node* t=root; t!=null;) 
			if(key>t->key) ret=t->key, t=t->ch[1];
			else t=t->ch[0];
		return ret;
	}
	int pre(const int &key) {
		int ret=oo;
		for(node* t=root; t!=null;) 
			if(key<t->key) ret=t->key, t=t->ch[0];
			else t=t->ch[1];
		return ret;
	}
}*line[N], *nod[N], *q[N];

void getrange(int l, int r) {
	cnt=0;
	int r1=r;
	while(l<=r1) {
		if(r1-lowbit(r1)+1>=l) {
			q[cnt++]=line[r1];
			r1-=lowbit(r1);
		}
		else {
			q[cnt++]=nod[r1];
			r1--;
		}
	}
}

int getrank(const int &key) {
	int ret=0;
	for(int i=0; i<cnt; ++i)
		ret+=q[i]->rank(key);
	return ret;
}

int getans(int l, int r, int k) {
	getrange(l, r);
	int left=oo+1, right=oo, s;
	for(int i=0; i<cnt; ++i) {
		node* t=q[i]->root;
		while(t!=null) {
			if(t->key<left) {
				t=t->ch[1];
				continue;
			}
			if(t->key>right) {
				t=t->ch[0];
				continue;
			}
			s=getrank(t->key);
			if(s==k-1) return t->key;
			if(s<k-1) {
				left=t->key;
				t=t->ch[1];
			}
			else {
				right=t->key;
				t=t->ch[0];
			}
		}
	}
	return left;
}

int getsuc(int l, int r, const int &key) {
	getrange(l, r);
	int ret=oo+1, t;
	for(int i=0; i<cnt; ++i) {
		t=q[i]->suc(key);
		ret=max(ret, t);
	}
	return ret;
}

int getpre(int l, int r, const int &key) {
	getrange(l, r);
	int ret=oo, t;
	for(int i=0; i<cnt; ++i) {
		t=q[i]->pre(key);
		ret=min(ret, t);
	}
	return ret;
}

int main() {
	null=new node; null->wei=oo; null->ch[0]=null->ch[1]=null;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		line[i]=new Treap;
		nod[i]=new Treap;
		for(int j=i-lowbit(i)+1; j<=i; ++j)
			line[i]->insert(a[j], line[i]->root);
		nod[i]->insert(a[i], nod[i]->root);
	}
	int c, l, r, k;
	while(m--) {
		scanf("%d", &c);
		if(c==1) {
			scanf("%d%d%d", &l, &r, &k);
			getrange(l, r);
			printf("%d\n", getrank(k)+1);
		}
		else if(c==2) {
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", getans(l, r, k));
		}
		else if(c==3) {
			scanf("%d%d", &l, &k);
			for(int i=l; i<=n; i+=lowbit(i)) {
				line[i]->remove(a[l], line[i]->root);
				line[i]->insert(k, line[i]->root);
			}
			a[l]=k;
			nod[l]->root->key=k;
		}
		else if(c==4) {
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", getsuc(l, r, k));
		}
		else if(c==5) {
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", getpre(l, r, k));
		}
	}
	return 0;
}

