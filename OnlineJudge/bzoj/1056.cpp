#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
const int N=250020, oo=~0u>>1;
map<string, pair<int, int> > rk;
int cnt=0, tot=0;
string nam;

struct node* null;
struct node {
	int key, id;
	string name;
	int size, wei;
	node* ch[2];
	node(int _k=0, int _id=0, string _n="", int _s=1) : key(_k), id(_id), name(_n), size(_s) {
		ch[0]=ch[1]=null; wei=rand();
	}
	inline void pushup() { size=ch[0]->size+ch[1]->size+1; }
}*root;
inline void rot(node* &r, const bool d) {
	node* t=r->ch[!d]; r->ch[!d]=t->ch[d]; t->ch[d]=r;
	r->pushup(); t->pushup();
	if(root==r) root=t;
	r=t;
}
inline void insert(node* &r, const int &key, const int &id) {
	if(r==null) { r=new node(key, id, nam); return; }
	bool d=key>r->key;
	insert(r->ch[d], key, id);
	if(r->ch[d]->wei < r->wei) rot(r, !d);
	else r->pushup();
}
inline void del(node* &r, const int &key, const int &id) {
	if(r==null) return;
	bool d=key>r->key;
	if(key==r->key) {
		if(id==r->id) {
			d=r->ch[0]->wei > r->ch[1]->wei;
			if(r->ch[d]==null) {
				delete(r);
				r=null;
				return;
			}
			rot(r, !d);
			del(r->ch[!d], key, id);
		}
		else del(r->ch[id<r->id], key, id);
	}
	else del(r->ch[d], key, id);
	r->pushup();
}
int getrank(node* r, const int &key, const int &id) {
	if(r==null) return 0;
	if(key==r->key) {
		if(id>r->id) return r->ch[1]->size+getrank(r->ch[0], key, id)+1;
		else if(id<r->id) return getrank(r->ch[1], key, id);
		else return r->ch[1]->size+1;
	}
	if(key>r->key) return getrank(r->ch[1], key, id);
	else return getrank(r->ch[0], key, id)+r->ch[1]->size+1;
}
node* select(node* r, const int k) {
	if(r==null) return null;
	int s=r->ch[1]->size+1;
	if(s==k) return r;
	if(s>k) return select(r->ch[1], k);
	else return select(r->ch[0], k-s);
}
void ins(char *nm) {
	int key;
	string str(nm+1);
	read(key);
	if(rk.count(str)!=0) {
		del(root, rk[str].second, rk[str].first);
		rk.erase(str);
		--tot;
	}
	++cnt; ++tot;
	rk[str]=pair<int, int> (cnt, key);
	nam=str;
	insert(root, key, cnt);
}
void ask1(char *nm) {
	string str(nm+1);
	printf("%d\n", getrank(root, rk[str].second, rk[str].first));
}
void ask2(char *nm) {
	int num=0;
	string str(nm+1);
	for(int i=0; i<str.size(); ++i) num=num*10+str[i]-'0';
	int t=min(tot-num+1, 10);
	for(int i=0; i<t; ++i) {
		printf("%s", select(root, num+i)->name.c_str());
		if(i!=t-1) printf(" ");
	}
	puts("");
}
inline void init() {
	null=new node(0, 0, "", 0); null->ch[0]=null->ch[1]=null; null->wei=oo;
	root=null;
}
int main() {
	init();
	int n=getint();
	char str[30];
	while(n--) {
		scanf("%s", str);
		if(str[0]=='+') ins(str);
		else {
			if(str[1]>='A'&&str[1]<='Z') ask1(str);
			else ask2(str);
		}
	}
	return 0;
}

