#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cassert>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

map<string, int> mp;
typedef long long ll;
const int N=105, M=100005;
const ll eps=1e9;
int n, m, ID, a[N], flag, tot, db;
char s[15];
struct node { node *l, *r; bool f, opt; int s; node() { l=r=NULL; f=opt=0; s=0; } }*root=NULL;
struct dat { int s; bool f, opt; dat() { s=0; f=opt=0; } }b[M];
int getid(char *st, int len) {
	string s(st, len);
	if(mp[s]) return mp[s];
	mp[s]=++ID;
	return ID;
}
ll cal(node *x) {
	if(x==NULL || flag) return 0;
	if(!x->opt) {
		if(x->f) return a[x->s];
		return x->s;
	}
	ll l=cal(x->l), r=cal(x->r), ret=0;
	int opt=x->s;
	if(flag) return 0;
	if(opt=='/' && r==0) { flag=1; return 0; }
	if(opt=='+') ret=l+r;
	if(opt=='-') ret=l-r;
	if(opt=='*') ret=l*r;
	if(opt=='/') ret=l/r;
	if(abs(ret)>eps) { flag=1; return 0; }
	return ret;
}
void build(int l, int r, node *&x) {
	// if(db>1) return;
	// ++db;
	// assert(l<=r);
	if(l==r) {
		x=new node();
		x->f=b[l].f;
		x->s=b[l].s;
		return;
	}
	int p=0, c1=-1, c2=-1;
	for1(i, l, r) {
		if(!b[i].opt) continue;
		if(b[i].s=='(') ++p;
		else if(b[i].s==')') --p;
		else if(!p && (b[i].s=='+' || b[i].s=='-')) c1=i;
		else if(!p && (b[i].s=='*' || b[i].s=='/')) c2=i;
	}
	if(c1==-1) c1=c2;
	if(c1==-1) { build(l+1, r-1, x); return; }
	//puts("here"); dbg(c1);
	x=new node();
	build(l, c1-1, x->l); build(c1+1, r, x->r);
	x->opt=1;
	x->s=b[c1].s;
}
int main() {
	read(n); read(m);
	for1(i, 1, n) {
		scanf("%s", s);
		getid(s, strlen(s));
	}
	char c=getchar(); while(c=='\n'||c=='\r'||c==' ') c=getchar();
	while(c!='\n') {
		if(c>='0' && c<='9') {
			int r=0;
			while(c>='0' && c<='9') r=r*10+c-'0', c=getchar();
			b[++tot].s=r;
		}
		else if((c>='A' && c<='Z') || (c>='a' && c<='z')) {
			int len=0;
			while((c>='A' && c<='Z') || (c>='a' && c<='z')) s[len++]=c, c=getchar();
			s[len]='\0';
			b[++tot].s=getid(s, len);
			b[tot].f=1;
		}
		else if(c!='\n') {
			b[++tot].opt=1;
			b[tot].s=c;
			c=getchar();
		}
	}
	build(1, tot, root);
	while(m--) {
		for1(i, 1, n) read(a[i]);
		flag=0;
		int ans=cal(root);
		if(flag) puts("Error!");
		else printf("%d\n", ans);
	}
	return 0;
}