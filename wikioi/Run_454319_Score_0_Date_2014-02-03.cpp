#include <cstdio>
using namespace std;

#define NEW(d) new Splay(d)

struct Splay {
	Splay* ch[2], *pa;
	int key;
	Splay(int d = 0) : key(d) { ch[0] = ch[1] = pa = NULL; }
	int cmp(int d) {
		if(key == d) return -1;
		return key > d ? 0 : 1;
	}
}*root = NULL;

int ok = 1, who, ans, n, cnt[2];

typedef Splay* tree;

void rot(tree rt, int d) {
	tree k = rt-> ch[d^1];
	rt-> ch[d^1] = k-> ch[d];
	k-> ch[d] = rt;
	k-> pa = rt-> pa;
	if(rt-> ch[d^1] != NULL) rt-> ch[d^1] = rt;
	if(rt-> pa != NULL) {
		if(rt-> pa-> ch[0] == rt) rt-> pa-> ch[0] = k;
		else rt-> pa-> ch[1] = k;
	}
	rt-> pa = k;
	if(rt == root) root = k;
}

void splay(tree& rt, tree nod) {
	if(nod == NULL) return;
	while(nod-> pa != rt-> pa) {
		if(nod-> pa-> pa == rt-> pa)
			rot(rt, nod == rt-> ch[0]);
		else {
			//找到方向
			int d = (nod-> pa == nod-> pa-> pa-> ch[0]);
			int d2 = (nod == nod-> pa-> ch[0]);
			//方向相同，先转父亲的父亲，再转父亲
			if(d == d2) { rot(nod-> pa-> pa, d); rot(nod-> pa, d2); }
			//相反，先转父亲，在转父亲的父亲
			else { rot(nod-> pa, d2); rot(nod-> pa, d); }
		}
	}
}

//d=0: min d=1: max
tree maxmin(tree rt, int d) {
	if(rt == NULL) return NULL;
	while(rt-> ch[d] != NULL) rt = rt-> ch[d];
	return rt;
}

tree search(tree& rt, int d) {
	tree ret = rt;
	while(ret != NULL && ret-> key != d) if(ret-> key > d) ret = ret-> ch[0]; else ret = ret-> ch[1];
	if(rt != NULL) splay(rt, ret);
	else return NULL;
	return ret;
}

void insert(tree& rt, int d) {
	if(rt == NULL) { rt = NEW(d); return; }
	tree t = NULL, q = rt;
	while(q != NULL) t = q, q = (q-> key > d ? q-> ch[0] : q-> ch[1]);
	q = NEW(d);
	q-> pa = t;
	int c = (t-> key > d ? 0 : 1);
	t-> ch[c] = q;
	splay(rt, q);
}

tree ps(tree rt, int d) {
	if(rt == NULL || rt-> ch[d] == NULL) return NULL;
	rt = rt-> ch[d];
	while(rt-> ch[d^1] != NULL) rt = rt-> ch[d^1];
	return rt;
}

void del() {
	tree& rt = root;
	tree t;
	if(rt-> ch[0] == NULL) t = rt-> ch[1];
	else {
		t = rt-> ch[0];
		splay(t, ps(rt, 0));
		t-> ch[1] = rt-> ch[1];
	}
	delete rt;
	rt = t;
}

void init(int key, int d) {
	if(root == NULL || who == d) { insert(root, key); who = d; cnt[d]++; return; }
	insert(root, key);
	tree succ = ps(root, 0), pred = ps(root, 1);
	if(succ == NULL) { ans += pred-> key - root-> key; del(); return; }
	if(pred == NULL) { ans += root-> key - succ-> key; del(); return; }
	int l = root-> key - succ-> key, r = pred-> key - root-> key;
	del();
	if(l <= r) { ans = (ans + l) % 1000000; splay(root, succ); del(); }
	else { ans = (ans + r) % 1000000; splay(root, pred); del(); }
	if(root == NULL) who = d;
}

int main() {
	scanf("%d", &n);
	int c, b;
	for(int i = 1; i <= n; ++i) { scanf("%d%d", &c, &b); init(b, c); }
	printf("%d", ans);
	return 0;
}
