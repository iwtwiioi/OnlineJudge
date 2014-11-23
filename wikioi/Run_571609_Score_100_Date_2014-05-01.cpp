#include <cstdio>
using namespace std;

#define L(x) x-> ch[0]
#define R(x) x-> ch[1]
#define C(x, a) x-> ch[a]
#define F(x) x-> f
#define K(x) x-> k
#define S(x) x-> s
#define PRE(x) R(x) = L(x) = F(x) = null

struct Splay {
	struct nod {
		nod *ch[2], *f;
		int k, s;
	};

	typedef nod* tree;
	tree null, root;

	Splay() { newnode(null); S(null) = 0; root = null; }

	void newnode(tree& r, int k = 0) {
		r = new nod; PRE(r); K(r) = k; S(r) = 1;
	}

	bool isnull(const tree& r) {
		if(r == null) return true;
		return false;
	}

	void pushup(tree r) {
		S(r) = S(L(r)) + S(R(r)) + 1;
	}

	void pushdown(tree r) {

	}

	void rot(tree x, int c) {
		tree y = F(x);
		pushdown(y); pushdown(x);
		C(y, !c) = C(x, c); if(!isnull( C(x, c) )) F(C(x, c)) = y;
		F(x) = F(y); if(!isnull(F(y))) C(F(y), R(F(y)) == y) = x;
		C(x, c) = y; F(y) = x;
		pushup(y); pushup(x);
	}

	void splay(tree t, tree& r) {
		tree u = F(r);
		while(F(t) != u) {
			if(F(t) == r)
				rot(t, L(r) == t);
			else {
				int d1 = L(F(F(t))) == F(t);
				int d2 = L(F(t))    == t;
				if(d1 == d2) {
					rot(F(t), d1); rot(t, d2);
				}
				else {
					rot(t, d2);    rot(t, d1);
				}
			}
		}
		pushup(t);
		r = t;
	}

	tree select(int k, tree r) {
		pushdown(r);
		int s = S(L(r)) + 1;
		if(s == k) return r;
		if(s > k) return select(k, L(r));
		return select(k-s, R(r));
	}

	int Rank(int k, tree r) {
		pushdown(r);
		int s = S(L(r)) + 1;
		if(k == K(r)) return s;
		if(K(r) > k) return Rank(k, L(r));
		return s + Rank(k, R(r));
	}

	tree Find(int k) {
		tree r = root;
		while(!isnull(r) && K(r) != k) r = C(r, k > K(r));
		return r;
	}

	void Ins(int k) {
		tree q = NULL, t = root;
		while(!isnull(t)) q = t, t = C(t, k > K(t));
		newnode(t, k);
		if(q == NULL) root = t;
		else F(t) = q, C(q, k > K(q)) = t;
		splay(t, root);
	}

	void Del(tree t) {
		if(isnull(t)) return;
		splay(t, root);
		tree q;
		if(L(t) == null) q = R(t);
		else {
			splay(select(1, root), L(root));
			q = L(t); R(q) = R(t);
		}
		F(q) = null;
		delete root;
		root = q;
	}

	bool find(int k) {
		return !isnull(Find(k));
	}

	void ins(int k) {
		Ins(k);
	}

	void del(int t) {
		Del(Find(t));
	}

	tree sel(int k) {
		return select(k, root);
	}

	int rank(int k) {
		return Rank(k, root);
	}
	
	
	
	tree maxmin(tree rt, int d) {
	if(rt == null) return null;
	while(C(rt, d) != null) rt = C(rt, d);
	return rt;
}
	tree ps(tree rt, int d) {
		if(rt == null) return null;
		rt = C(rt, d);
		return maxmin(rt, d^1);
	}
	
	

}T;

int n, ans;
void init(int key) {
	if(T.root == T.null) { T.ins(key); ans += key; return; }
	T.ins(key);
	Splay::tree succ = T.ps(T.root, 0), pred = T.ps(T.root, 1);
	if(succ == T.null) { ans += K(pred) - K(T.root); T.splay(pred, T.root); return; }
	if(pred == T.null) { ans += K(T.root) - K(succ); T.splay(succ, T.root); return; }
	int l = K(T.root) - K(succ), r = K(pred) - K(T.root);
	if(l <= r) { ans += l; T.splay(succ, T.root); }
	else { ans += r; T.splay(pred, T.root); }
}

int main() {
	scanf("%d", &n);
	int c;
	for(int i = 0; i < n; ++i) { if(scanf("%d", &c) == EOF) c = 0; init(c); }
	printf("%d\n", ans);
	return 0;
}
