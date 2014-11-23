#include <cstdio>
#include <algorithm>
using namespace std;

#define K(x) key[x]
#define S(x) size[x]
#define C(x, d) ch[x][d]
#define F(x) fa[x]
#define L(x) ch[x][0]
#define R(x) ch[x][1]

const int maxn = 50000;
int size[maxn], key[maxn], fa[maxn], ch[maxn][2], tot, root;

void pushup(int x) {
	S(x) = S(R(x)) + S(L(x)) + 1;
}

void rot(int x, int c) {
	int y = F(x);
	C(y, !c) = C(x, c); F(C(x, c)) = y;
	C(x, c) = y; F(x) = F(y);
	if(F(y)) C(F(y), R(F(y)) == y) = x;
	F(y) = x;
	pushup(y);
}

void splay(int x, int y) {
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

void newnode(int& x, int k, int f) {
	x = ++tot; K(x) = k; F(x) = f; S(x) = 1;
}

void insert(int k) {
	int x = root;
	while(C(x, k > K(x))) x = C(x, k > K(x));
	newnode(C(x, k > K(x)), k, x);
	splay(C(x, k > K(x)), 0);
}

int sel(int k, int x) {
	if(!k) return 0;
	int s = S(L(x)) + 1;
	if(s == k) return K(x);
	if(k < s) return sel(k, L(x));
	return sel(k-s, R(x));
}

int ps(int x, int c) {
	x = C(x, c);
	while(C(x, !c)) x = C(x, !c);
	return x;
}

int n, t, ans;

int main() {
	scanf("%d", &n);
	int a, b;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t);
		insert(t);
		a = K(root) - ps(root, 0);
		b = ps(root, 1) - K(root);
		ans += max(a, b);
	}
	printf("%d", ans);
	return 0;
}
