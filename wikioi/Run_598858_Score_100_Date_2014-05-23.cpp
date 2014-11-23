#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 205, inf = ~0u >> 1;
int cap[maxn][maxn], p[maxn];
int q[maxn], front, rear, a[maxn];
int n, m;

int min(const int& a, const int& b) { return a < b ? a : b; }

int EK(int s, int t) {
    int flow = 0, u, v;
    while(1) {
        memset(a, 0, sizeof(a));
        q[front = rear = 0] = s;
        a[s] = inf;
        while(front <= rear) {
            u = q[front++];
            for(int v = 1; v <= n; ++v) if(cap[u][v] > 0 && !a[v]) {
                q[++rear] = v; p[v] = u;
                a[v] = min(a[u], cap[u][v]);
            }
        }
        if(a[t] == 0) break;
        for(v = t; v != s; v = p[v]) {
            cap[p[v]][v] -= a[t];
            cap[v][p[v]] += a[t];
        }
        flow += a[t];
    }
    return flow;
}

void init() {
    scanf("%d%d", &m, &n);
    int u, v, c;
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        cap[u][v] += c;
    }
}

int main() {
    init();
    printf("%d\n", EK(1, n));
    return 0;
}
