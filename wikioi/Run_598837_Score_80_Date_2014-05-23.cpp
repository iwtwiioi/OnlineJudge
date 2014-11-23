#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2005, maxm = 2005, inf = ~0u >> 1;
int V[maxn], head[maxn], next[maxm], cap[maxn][maxn], p[maxn];
int q[maxn], front, rear, a[maxn];
int n, m;

int min(const int& a, const int& b) { return a < b ? a : b; }

int EK(int s, int t) {
    int flow = 0, u, v, e;
    while(1) {
        memset(a, 0, sizeof(int)*(n+1));
        memset(p, 0, sizeof(int)*(n+1));
        q[front = rear = 0] = s;
        a[s] = inf;
        while(front <= rear) {
            u = q[front++];
            for(e = head[u]; e; e = next[e]) {
                v = V[e];
                if(cap[u][v] > 0 && !a[v]) {
                    q[++rear] = v;
                    p[v] = u;
                    a[v] = min(a[u], cap[u][v]);
                }
            }
            if(p[t] != 0) break;
        }
        if(a[t] == 0) break;
        for(v = t, u = p[v]; v != s; v = u, u = p[u]) {
            cap[u][v] -= a[t];
            cap[v][u] += a[t];
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
        next[i] = head[u];
        head[u] = i;
        V[i] = v;
        cap[u][v] = c;
    }
}

int main() {
    init();
    printf("%d\n", EK(1, n));
    return 0;
}
