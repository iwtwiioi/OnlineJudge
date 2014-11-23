#include <cstdio>
using namespace std;
const int N=10005, oo=~0u>>1;
#define lowbit(x) (x&-x)
struct node {
    node* ch[2], *fa;
    int key, size;
    node() { ch[0]=ch[1]=fa=0; key=size=0; }
    void pushup() { size=ch[0]->size+ch[1]->size+1; }
    bool d() { return fa->ch[1]==this; }
    void setc(node* c, bool d) { ch[d]=c; c->fa=this; }
}*null;
 
struct Splay {
    node* root;
    Splay() { root=null; }
    void rot(node* rt) {
        node* fa=rt->fa; bool d=rt->d();
        fa->fa->setc(rt, fa->d());
        fa->setc(rt->ch[!d], d);
        rt->setc(fa, !d);
        fa->pushup();
        if(root==fa) root=rt;
    }
    node* newnode(const int &key) {
        node* ret=new node();
        ret->key=key; ret->size=1;
        ret->ch[0]=ret->ch[1]=ret->fa=null;
        return ret;
    }
    void splay(node* rt, node* fa) {
        while(rt->fa!=fa) {
            if(rt->fa->fa==fa) rot(rt);
            else rt->d()==rt->fa->d()?(rot(rt->fa), rot(rt)):(rot(rt), rot(rt));
        }
        rt->pushup();
    }
    void insert(const int& key) {
        if(root==null) { root=newnode(key); return; }
        node* t=root;
        while(t->ch[key>t->key]!=null) t=t->ch[key>t->key];
        node* c=newnode(key);
        t->setc(c, key>t->key);
        t->pushup();
        splay(c, null);
    }
    void remove(const int &key) {
        node* t=root;
        while(t!=null && t->key!=key) t=t->ch[key>t->key];
        if(t==null) return;
        splay(t, null);
        node* rt=root->ch[0];
        if(rt==null) rt=root->ch[1];
        else {
            node* m=rt->ch[1];
            while(m!=null && m->ch[1]!=null) m=m->ch[1];
            if(m!=null) splay(m, root);
            rt=root->ch[0];
            rt->setc(root->ch[1], 1);
        }
        delete root;
        root=rt;
        root->fa=null;
        if(root!=null) root->pushup();
    }
    int rank(const int& key) {
        node* t=root;
        int ret=0;
        while(t!=null) {
            if(t->key<key) {
                ret+=t->ch[0]->size+1;
                t=t->ch[1];
            }
            else t=t->ch[0];
        }
        return ret;
    }
}*line[N], *nod[N], *q[N];
 
int cnt;
int getrank(int key) {
    int ret=0;
    for(int i=0; i<cnt; ++i)
        ret+=q[i]->rank(key);
    return ret;
}
int getans(int k, int l, int r) {
    int r1=r, s;
    cnt=0;
    while(l<=r1) {
        if(l<=r1-lowbit(r1)+1) {
            q[cnt++]=line[r1];
            r1-=lowbit(r1);
        }
        else {
            q[cnt++]=nod[r1];
            r1--;
        }
    }
    int left=oo+1, right=oo;
    for(int i=0; i<cnt; ++i) {
        node* p=q[i]->root;
        while(p!=null) {
            if(p->key<left) {
                p=p->ch[1];
                continue;
            }
            if(p->key>right) {
                p=p->ch[0];
                continue;
            }
            s=getrank(p->key);
            if(s==k-1) return p->key;
            if(s<k-1) {
                left=p->key;
                p=p->ch[1];
            }
            else {
                right=p->key;
                p=p->ch[0];
            }
        }
    }
    return left;
}
 
void init() {
    null=new node(); null->ch[0]=null->ch[1]=null->fa=null;
}
int arr[N];
 
int main() {
    int n, m;
    init();
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &arr[i]);
        line[i]=new Splay;
        nod[i]=new Splay;
        for(int j=i-lowbit(i)+1; j<=i; ++j)
            line[i]->insert(arr[j]);
        nod[i]->insert(arr[i]);
    }
    char str[3];
    int a, b, c;
    while(m--) {
        scanf("%s", str);
        if(str[0]=='Q') {
            scanf("%d%d%d", &a, &b, &c);
            printf("%d\n", getans(c, a, b));
        }
        else {
            scanf("%d%d", &a, &b);
            c=a;
            while(c<=n) {
                line[c]->remove(arr[a]);
                line[c]->insert(b);
                c+=lowbit(c);
            }
            nod[a]->root->key=b;
            arr[a]=b;
        }
    }
    return 0;
}