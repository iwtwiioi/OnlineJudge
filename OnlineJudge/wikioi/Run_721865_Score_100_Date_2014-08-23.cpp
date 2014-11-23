#include <cstdio>
#include <set>
using namespace std;
int main() {
    int n, m, t;
    scanf("%d%d", &n, &m);
    set<int> s;
    for(int i=1; i<=n; ++i) scanf("%d", &t), s.insert(t);
    for(int i=1; i<=m; ++i) scanf("%d", &t), s.count(t)?puts("YES"):puts("NO");
 	return 0;   
}