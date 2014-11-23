#include <cstdio>

#define K(x) key[x]
#define S(x) size[x]
#define C(x, d) ch[x][d]
#define F(x) fa[x]
#define L(x) ch[x][0]
#define R(x) ch[x][1]
#define keytree L(R(root))

const int maxn = 222222;
struct SplayTree{
	int size[maxn];
	int ch[maxn][2];
	int fa[maxn];
	int root, top1, top2;
	int ss[maxn], que[maxn];
	
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
	
	inline void RotateTo(int k,int goal) {//把第k位的数转到goal下边
		int x = root;
		pushdown(x);
		while(size[ ch[x][0] ] != k) {
			if(k < size[ ch[x][0] ]) {
				x = ch[x][0];
			} else {
				k -= (size[ ch[x][0] ] + 1);
				x = ch[x][1];
			}
			pushdown(x);
		}
		splay(x,goal);
	}
	inline void erase(int x) {//把以x为祖先结点删掉放进内存池,回收内存
		int father = fa[x];
		int head = 0, tail = 0;
		for (que[tail++] = x ; head < tail ; head ++) {
			ss[top2 ++] = que[head];
			if(ch[ que[head] ][0]) que[tail++] = ch[ que[head] ][0];
			if(ch[ que[head] ][1]) que[tail++] = ch[ que[head] ][1];
		}
		ch[ father ][ ch[father][1] == x ] = 0;
		pushup(father);
	}
	//以上一般不修改//////////////////////////////////////////////////////////////////////////////
	void debug() {printf("%d\n",root);Treaval(root);}
	void Treaval(int x) {
		if(x) {
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d\n",x,ch[x][0],ch[x][1],fa[x],size[x],val[x]);
			Treaval(ch[x][1]);
		}
	}
	//以上Debug
 
 
	//以下是题目的特定函数:
	inline void NewNode(int &x,int c) {
		if (top2) x = ss[--top2];//用栈手动压的内存池
		else x = ++top1;
		ch[x][0] = ch[x][1] = fa[x] = 0;
		size[x] = 1;
 
		val[x] = sum[x] = c;/*这是题目特定函数*/
		add[x] = 0;
	}
 
	//把延迟标记推到孩子
	inline void pushdown(int x) {/*这是题目特定函数*/
		if(add[x]) {
			val[x] += add[x];
			add[ ch[x][0] ] += add[x];
			add[ ch[x][1] ] += add[x];
			sum[ ch[x][0] ] += (long long)size[ ch[x][0] ] * add[x];
			sum[ ch[x][1] ] += (long long)size[ ch[x][1] ] * add[x];
			add[x] = 0;
		}
	}
	//把孩子状态更新上来
	inline void pushup(int x) {
		size[x] = 1 + size[ ch[x][0] ] + size[ ch[x][1] ];
		/*这是题目特定函数*/
		sum[x] = add[x] + val[x] + sum[ ch[x][0] ] + sum[ ch[x][1] ];
	}
 
	/*初始化*/
	inline void makeTree(int &x,int l,int r,int f) {
		if(l > r) return ;
		int m = (l + r)>>1;
		NewNode(x, num[m]);		/*num[m]权值改成题目所需的*/
		makeTree(ch[x][0], l, m - 1, x);
		makeTree(ch[x][1], m + 1, r, x);
		fa[x] = f;
		pushup(x);
	}
	inline void init(int n) {/*这是题目特定函数*/
		ch[0][0] = ch[0][1] = fa[0] = size[0] = 0;
		add[0] = sum[0] = 0;
 
		root = top1 = 0;
		//为了方便处理边界,加两个边界顶点
		NewNode(root, -1);
		NewNode(ch[root][1], -1);
		fa[top1] = root;
		size[root] = 2;
 
 
		for (int i = 0 ; i < n ; i ++) scanf("%d",&num[i]);
		makeTree(keytree, 0, n-1, ch[root][1]);
		pushup(ch[root][1]);
		pushup(root);
	}
	/*更新*/
	inline void update( ) {/*这是题目特定函数*/
		int l, r, c;
		scanf("%d%d%d",&l,&r,&c);
		RotateTo(l-1,0);
		RotateTo(r+1,root);
		add[ keytree ] += c;
		sum[ keytree ] += (long long)c * size[ keytree ];
	}
	/*询问*/
	inline void query() {/*这是题目特定函数*/
		int l, r;
		scanf("%d%d",&l,&r);
		RotateTo(l-1, 0);
		RotateTo(r+1, root);
		printf("%lld\n",sum[keytree]);
	}
 
 
	/*这是题目特定变量*/
	int num[maxn];
	int val[maxn];
	int add[maxn];
	long long sum[maxn];
}spt;
 
 
int main() {
	int n, m, t;
	scanf("%d",&n);
	spt.init(n);
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &t);
		if(t == 2) spt.query();
		else spt.update();
	}
	return 0;
}
