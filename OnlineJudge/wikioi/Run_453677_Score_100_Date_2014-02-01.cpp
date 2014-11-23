#include <cstdio>
#include <cmath>
using namespace std;
#define NEW(d) new Splay(d)

int n, ans;

struct Splay {
	Splay* ch[2];
	int key;
	Splay(int d = 0) : key(d) { ch[0] = ch[1] = NULL; }
	int cmp(int d) {
		if(d == key) return -1;
		return key > d ? 0 : 1;
	}
}*root[2] = {NULL, NULL};

int who;

typedef Splay* tree;

void rot(tree& rt, int d) {
	tree k = rt-> ch[d^1]; rt-> ch[d^1] = k-> ch[d]; k-> ch[d] = rt; rt = k;
}

void splay(tree& rt, int d) {
	if(rt == NULL) return;
	int k = rt-> cmp(d);
	if(k != -1) {
		tree p = rt-> ch[k];
		if(p != NULL) {
			int k2 = p-> cmp(d);
			if(k2 != -1) {
				splay(p-> ch[k2], d);
				if(k == k2) rot(rt, k^1); else rot(rt-> ch[k], k);
			}
		}
		rot(rt, k^1);
	}
}

//d = 0 : succ, d = 1 : pred
tree ps(tree rt, int d) {
	rt = rt-> ch[d];
	if(rt == NULL) return NULL;
	while(rt-> ch[d^1] != NULL) rt = rt-> ch[d^1];
	return rt;
}

void insert(tree& rt, int d) {
	if(rt == NULL) { rt = NEW(d); splay(root[who], d); }
	else {
		if(rt-> key > d) insert(rt-> ch[0], d);
		else insert(rt-> ch[1], d);
	}
}

void del(tree& rt) {
	tree t;
	if(rt-> ch[0] == NULL) t = rt-> ch[1];
	else {
		t = rt-> ch[0];
		splay(t, ps(rt, 0)-> key);
		t-> ch[1] = rt-> ch[1];
	}
	delete rt;
	rt = t;
}

void init(int key, int d) {
	if(root[d^1] == NULL) { who = d; insert(root[who], key); return; }
	who = d^1;
	insert(root[who], key);
	tree succ = ps(root[who], 0), pred = ps(root[who], 1);
	int l = 0, r = 0;
	if(succ != NULL) l = root[who]-> key - succ-> key;
	if(pred != NULL) r = pred-> key - root[who]-> key;
	del(root[who]);
	if(succ != NULL && (pred == NULL || l <= r)) {
		ans = (ans + l) % 1000000;
		splay(root[who], succ-> key);
		del(root[who]);
	}
	else if(pred != NULL && (succ == NULL || r < l)) {
		ans = (ans + r) % 1000000;
		splay(root[who], pred-> key);
		del(root[who]);
	}
}

int main() {
	scanf("%d", &n);
	int c, b;
	for(int i = 0; i < n; ++i) { scanf("%d%d", &c, &b); init(b, c); }
	printf("%d", ans);
	return 0;
}
