#include <cstdio>
#include <algorithm>
using namespace std;

#define K(x) key[x]
#define S(x) size[x]
#define C(x, d) ch[x][d]
#define F(x) fa[x]
#define L(x) ch[x][0]
#define R(x) ch[x][1]
#define keytree L(R(root))

const int maxn = 50000;
int size[maxn], key[maxn], fa[maxn], ch[maxn][2], sum[maxn], add[maxn], val[maxn];
int tot, root;
int arr[maxn];

void newnode(int& x, int k, int f) {
	x = ++tot; F(x) = f; S(x) = 1;
	//K(x) = k;
	val[x] = sum[x] = k;
}

void pushup(int x) {
	S(x) = S(R(x)) + S(L(x)) + 1;
	sum[x] = sum[R(x)] + sum[L(x)] + val[x] + add[x];
}

void pushdown(int x) {
	if(add[x]) {
		add[R(x)] += add[x];
		add[L(x)] += add[x];
		sum[R(x)] += add[x] * S(R(x));
		sum[L(x)] += add[x] * S(L(x));
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
	if(!x || k > S(x) || k < 0) return 0;
	pushdown(x);
	int s = S(L(x)) + 1;
	if(s == k) return x;
	if(k < s) return sel(k, L(x));
	return sel(k-s, R(x));
}

void build(int l, int r, int& rt, int f) {
	if(l > r) return;
	int mid = (l+r) >> 1;
	newnode(rt, arr[mid], f);
	build(l, mid-1, L(rt), rt); build(mid+1, r, R(rt), rt);
	pushup(rt);
}

inline void RotateTo(int k,int goal) {//把第k位的数转到goal下边
		int x = root;
		pushdown(x);
		while(S(L(x)) != k) {
			if(k < S(L(x))) {
				x = L(x);
			} else {
				k -= (S(L(x)) + 1);
				x = R(x);
			}
			pushdown(x);
		}
		splay(x, goal);
	}

//int query(int l, int r) {
//	splay(sel(l-1, root), 0);
//	splay(sel(r+1, root), root);
//	return sum[keytree];
//}

//void updata(int l, int r, int _add) {
//	splay(sel(l-1, root), 0);
//	splay(sel(r+1, root), root);
//	sum[keytree] += _add * S(keytree);
//	add[keytree] += _add;
//}

void updata(int l, int r, int _add) {
		RotateTo(l-1, 0);
		RotateTo(r+1, root);
		add[ keytree ] += _add;
		sum[ keytree ] += (long long)_add * size[ keytree ];
	}
	/*询问*/
void query(int l, int r) {
		RotateTo(l-1, 0);
		RotateTo(r+1, root);
		printf("%d\n", sum[keytree]);
	}

inline void init(int n) {/*这是题目特定函数*/
		ch[0][0] = ch[0][1] = fa[0] = size[0] = 0;
		add[0] = sum[0] = 0;
 
		root = 0;
		//为了方便处理边界,加两个边界顶点
		newnode(root, -1, 0);
		newnode(R(root) , -1, root);
		size[root] = 2;
 
 
		for (int i = 0 ; i < n ; i ++) scanf("%d",&arr[i]);
		build(0 , n-1, keytree, R(root));
		pushup(ch[root][1]);
		pushup(root);
	}
//以上一般不修改//////////////////////////////////////////////////////////////////////////////

void Treaval(int x) {
	if(x) {
		Treaval(ch[x][0]);
		printf("结点%2d : 左儿子 %2d | 右儿子 %2d | 父结点 %2d | size = %2d | sum = %2d\n",x,ch[x][0],ch[x][1],fa[x],size[x],sum[x]);
		Treaval(ch[x][1]);
	}
}
void debug() {printf("%d\n",root);Treaval(root);}
//以上Debug

int n, q, t, a, b, c;
int main() {
	scanf("%d", &n);
	init(n);
	//for(int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
	//newnode(root, -1, 0);
	//newnode(R(root), -1, root);
	//S(root) = 2;
	//build(1, n, keytree, R(root));
	//build(1, n, root, 0);
//	debug();
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &t);
		switch(t) {
			case 1:
				scanf("%d%d%d", &a, &b, &c);
				updata(a, b, c);
	//			debug();
				break;
			case 2:
				scanf("%d%d", &a, &b);
				query(a, b);
				break;
		}
	}
	return 0;
}
