#include <cstdio>
#include <set>
using namespace std;
int a[100009], md=100007;
void ins(const int &x) { for(int k=x%md; a[k]!=x; ++k) if(!a[k]) { a[k]=x; return; } }
int sea(const int &x) { for(int k=x%md; a[k]!=x; ++k) if(!a[k]) return 0; return 1; }
int main() {
    int n, m, t;
    scanf("%d%d", &n, &m);
    set<int> s;
    for(int i=1; i<=n; ++i) scanf("%d", &t), ins(t);
    for(int i=1; i<=m; ++i) scanf("%d", &t), sea(t)?puts("YES"):puts("NO");
 	return 0;   
}