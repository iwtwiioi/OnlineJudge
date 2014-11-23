#include <cstdio>
using namespace std;

#define K(x) key[x]
#define S(x) size[x]
#define C(x, d) ch[x][d]
#define F(x) fa[x]
#define L(x) ch[x][0]
#define R(x) ch[x][1]
#define keytree L(R(root))
#define LL long long

const int maxn = 222222;
int size[maxn], key[maxn], fa[maxn], ch[maxn][2], add[maxn];
LL sum[maxn];
int tot, root;
int arr[maxn];

void newnode(int& x, int k, int f) {
	x = ++tot; F(x) = f; S(x) = 1;
	K(x) = sum[x] = k;
}

void pushup(int x) {
	S(x) = S(R(x)) + S(L(x)) + 1;
	sum[x] = sum[R(x)] + sum[L(x)] + K(x) + add[x];
}

void pushdown(int x) {
	if(add[x]) {
		K(x) += add[x];
		add[R(x)] += add[x];
		add[L(x)] += add[x];
		sum[R(x)] += (LL)add[x] * (LL)S(R(x));
		sum[L(x)] += (LL)add[x] * (LL)S(L(x));
		add[x] = 0;
	}
}

void rot(int x, int c) {
	int y = F(x);
	pushdown(y); pushdown(x);
	C(y, !c) = C(x, c); F(C(x, c)) = y;
	C(x, c) = y; F(x) = F(y); F(y) = x;
	if(F(x)) C(F(x), R(F(x)) == y) = x;
	pushup(y);
}

void splay(int x, int y) {
	if(!x) return;
	pushdown(x);
	while(F(x) != y) {
		if(F(F(x)) == y) rot(x, L(F(x)) == x);
		else {
			int d1 = L(F(F(x))) == F(x);
			int d2 = L(F(x)) == x;
			if(d1 == d2) { rot(F(x), d1); rot(x, d2); }
			else { rot(x, d2); rot(x, d1); }
		}
	}
	pushup(x);
	if(!y) root = x;
}

void insert(int k) {
	int x = root;
	while(C(x, k > K(x))) x = C(x, k > K(x));
	newnode(C(x, k > K(x)), k, x);
	splay(C(x, k > K(x)), 0);
}

int sel(int k, int x) {
	for(pushdown(x); S(L(x)) != k; pushdown(x))
		if(k < S(L(x))) x = L(x);
		else k -= (S(L(x)) + 1), x = R(x);
	return x;
}

void build(int l, int r, int& rt, int f) {
	if(l > r) return;
	int mid = (l+r) >> 1;
	newnode(rt, arr[mid], f);
	build(l, mid-1, L(rt), rt); build(mid+1, r, R(rt), rt);
	pushup(rt);
}

void query() {
	int l, r;
	scanf("%d%d", &l, &r);
	splay(sel(l-1, root), 0);
	splay(sel(r+1, root), root);
	printf("%lld\n", sum[keytree]);
}

void updata() {
	int l, r, _add;
	scanf("%d%d%d", &l, &r, &_add);
	splay(sel(l-1, root), 0);
	splay(sel(r+1, root), root);
	sum[keytree] += (LL)_add * (LL)S(keytree);
	add[keytree] += (LL)_add;
}

int n, q, t;

void init() {
	for(int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
	newnode(root, -1, 0);
	newnode(R(root), -1, root);
	S(root) = 2;
	build(1, n, keytree, R(root));
	pushup(R(root));
	pushup(root);
}

int main() {
	scanf("%d", &n);
	init();
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &t);
		if(t == 1) updata();
		else query();
	}
	return 0;
}
