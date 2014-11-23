#include <cstdio>
using namespace std;

#define NEW(d) new Splay(d);

int ans = 0;

struct Splay {
	Splay* ch[2];
	int key;
	Splay(int d = 0) : key(d) { ch[0] = ch[1] = NULL; }
	int cmp(int d) {
		if(key == d) return -1;
		return key > d ? 0 : 1;
	}
}*root = NULL;

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
				if(k == k2) rot(rt, k^1);
				else rot(rt-> ch[k], k);
			}
		}
		rot(rt, k^1);
	}
}

void insert(tree& rt, int d) {
	if(rt == NULL) { rt = NEW(d); splay(root, d); }
	else {
		if(rt-> key > d) insert(rt-> ch[0], d);
		else insert(rt-> ch[1], d);
	}
}

tree ps(tree rt, int d) {
	if(rt == NULL || rt-> ch[d] == NULL) return NULL;
	rt = rt-> ch[d];
	while(rt-> ch[d^1] != NULL) rt = rt-> ch[d^1];
	return rt;
}

void init(int key) {
	insert(root, key);
	int l = 0, r = 0;
	tree succ = ps(root, 0), pred = ps(root, 1);
	if(succ != NULL) { l = root-> key - succ-> key; splay(root, succ-> key); }
	if(pred != NULL) { r = pred-> key - root-> key; splay(root, pred-> key); }
	if(succ != NULL && (pred == NULL || l <= r)) ans += l;
	else if(pred != NULL && (succ == NULL || r < l)) ans += r;
}

int main() {
	int n, key;
	scanf("%d", &n);
	insert(root, key);
	ans += key;
	for(int i = 2; i <= n; ++i) { scanf("%d", &key); init(key); }
	printf("%d", ans);
	return 0;
}
