#include <cstdio>
using namespace std;
#define F(rt) rt-> pa
#define K(rt) rt-> key
#define CH(rt, d) rt-> ch[d]
#define C(rt, d) (K(rt) > d ? 0 : 1)
#define NEW(d) new Splay(d)
#define PRE(rt) F(rt) = CH(rt, 0) = CH(rt, 1) = null

int n, ans;

struct Splay {
	Splay* ch[2], *pa;
	int key;
	Splay(int d = 0) : key(d) { ch[0] = ch[1] = pa = NULL; }
};

typedef Splay* tree;
tree null = new Splay, root = null;

void rot(tree& rt, int d) {
	tree k = CH(rt, d^1), u = F(rt); int flag = CH(u, 1) == rt;
	CH(rt, d^1) = CH(k, d); if(CH(k, d) != null) F(CH(k, d)) = rt;
	CH(k, d) = rt; F(rt) = k; rt = k; F(rt) = u;
	if(u != null) CH(u, flag) = k;
}

void splay(tree nod, tree& rt) {
	if(nod == null) return;
	tree pa = F(rt);
	while(F(nod) != pa) {
		if(F(nod) == rt)
			rot(rt, CH(rt, 0) == nod);
		else {
			int d  = CH(F(F(nod)), 0) == F(nod);
			int d2 = CH(F(nod), 0)	  == nod;
			if(d == d2) { rot(F(F(nod)), d); rot(F(nod), d2); }
			else { rot(F(nod), d2); rot(F(nod), d); }
		}
	}
	rt = nod;
}

tree maxmin(tree rt, int d) {
	if(rt == null) return null;
	while(CH(rt, d) != null) rt = CH(rt, d);
	return rt;
}

tree ps(tree rt, int d) {
	if(rt == null) return null;
	rt = CH(rt, d);
	return maxmin(rt, d^1);
}

tree search(tree& rt, int d) {
	if(rt == null) return null;
	tree t = rt;
	while(t != null && K(t) != d) t = CH(t, C(t, d));
	splay(t, rt);
	return t;
}

void insert(tree& rt, int d) {
	tree q = NULL, t = rt;
	while(t != null) q = t, t = CH(t, C(t, d));
	t = new Splay(d);
	PRE(t);
	if(q) F(t) = q, CH(q, C(q, d)) = t;
	else rt = t;
	splay(t, rt);
}

void del(tree& rt) {
	if(rt == null) return;
	tree t = rt;
	if(CH(t, 0) == null) t = CH(rt, 1);
	else {
		t = CH(rt, 0);
		splay(ps(rt, 0), t);
		CH(t, 1) = CH(rt, 1);
		if(CH(rt, 1) != null) F(CH(rt, 1)) = t;
	}
	delete rt;
	F(t) = null;
	rt = t;
}

void init(int key) {
	if(root == null) { root = NEW(key); PRE(root); ans += key; return; }
	insert(root, key);
	tree succ = ps(root, 0), pred = ps(root, 1);
	if(succ == null) { ans += K(pred) - K(root); splay(pred, root); return; }
	if(pred == null) { ans += K(root) - K(succ); splay(succ, root); return; }
	int l = K(root) - K(succ), r = K(pred) - K(root);
	if(l <= r) { ans += l; splay(succ, root); }
	else { ans += r; splay(pred, root); }
}

int main() {
	PRE(null);
	scanf("%d", &n);
	int c;
	for(int i = 0; i < n; ++i) { if(scanf("%d", &c) == EOF) c = 0; init(c); }
	printf("%d\n", ans);
	return 0;
}
