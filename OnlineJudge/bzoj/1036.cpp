#include <cstdio>
#include <iostream>
using namespace std;
#define dbg(x) cout << #x << "=" << x << endl
#define read(x) x=getint()
#define print(x) printf("%d", x)
#define max(a,b) ((a)>(b)?(a):(b))

const int oo=~0u>>1;
inline int getint() { char c; int ret=0, k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }
const int N=30010, M=100005;
int ihead[N], inext[M], to[M], cnt, q[N], front, tail, n, m;
bool vis[N];

struct node* null;
struct node {
	node* fa, *ch[2];
	int w, sum, mx;
	bool d() { return fa->ch[1]==this; }
	bool check() { return fa->ch[0]!=this && fa->ch[1]!=this; }
	void setc(node* c, bool d) { ch[d]=c; c->fa=this; }
	void pushup() { 
		sum=w+ch[0]->sum+ch[1]->sum;
		mx=max(w, max(ch[0]->mx, ch[1]->mx));
	}
}*nd[N];

inline void rot(node* r) {
	node* fa=r->fa; bool d=r->d();
	if(fa->check()) r->fa=fa->fa;
	else fa->fa->setc(r, fa->d());
	fa->setc(r->ch[!d], d);
	r->setc(fa, !d);
	fa->pushup();
}

inline void splay(node* r) {
	while(!r->check())
		if(r->fa->check()) rot(r);
		else r->d()==r->fa->d()?(rot(r->fa), rot(r)):(rot(r), rot(r));
	r->pushup();
}

inline node* access(node* fa) {
	node* c=null;
	for(; fa!=null; c=fa, fa=fa->fa) {
		splay(fa);
		fa->setc(c, 1);
		fa->pushup();
	}
	return c;
}

inline void bfs() {
	vis[1]=1; int u, v, i;
	front=tail=0; q[tail++]=1;
	while(front!=tail) {
		u=q[front++];
		for(i=ihead[u]; i; i=inext[i]) if(!vis[v=to[i]]) {
			vis[v]=1;
			nd[v]->fa=nd[u];
			q[tail++]=v;
		}
	}
}

inline void add(const int &u, const int &v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; to[cnt]=u;
}

int main() {
	null=new node; null->fa=null->ch[0]=null->ch[1]=null; null->w=null->sum=0; null->mx=oo+1;
	read(n);
	int u, v, t;
	for(int i=1; i<n; ++i) {
		read(u); read(v);
		add(u, v);
	}
	int w;
	for(int i=1; i<=n; ++i) {
		nd[i]=new node;
		read(w);
		nd[i]->w=w;
		nd[i]->ch[0]=nd[i]->ch[1]=nd[i]->fa=null;
	}
	bfs();
	char c[10];
	node* lca=null;
	read(m);
	int ans;
	for(int i=0; i<m; ++i) {
		scanf("%s", c);
		if(c[0]=='C') {
			read(u); read(t);
			splay(nd[u]);
			nd[u]->w=t;
			nd[u]->pushup();
		}
		else if(c[0]=='Q') {
			read(u); read(v);
			access(nd[u]);
			lca=access(nd[v]);
			splay(nd[u]);
			if(nd[u]==lca) {
				if(c[1]=='M') ans=max(lca->w, lca->ch[1]->mx);
				else ans=lca->w + lca->ch[1]->sum;
			}
			else {
				if(c[1]=='M') ans=max(max(lca->w, nd[u]->mx), lca->ch[1]->mx);
				else ans=lca->w + lca->ch[1]->sum + nd[u]->sum;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
