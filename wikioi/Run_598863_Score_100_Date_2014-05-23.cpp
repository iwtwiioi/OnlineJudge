#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 205, inf = ~0u >> 1;
int cap[maxn][maxn], p[maxn];
int q[maxn], front, rear;
int n, m;

int min(const int& a, const int& b) { return a < b ? a : b; }

int EK(int s, int t) {
    int flow = 0, u, v, aug;
    while(1) {
        memset(p, 0, sizeof(p));
        q[front = rear = 0] = s;
        while(front <= rear) {
            u = q[front++];
            for(int v = 1; v <= n; ++v) if(cap[u][v] > 0 && !p[v]) q[++rear] = v, p[v] = u;
        }
        if(p[t] == 0) break;
        aug = inf;
        for(v = t; v != s; v = p[v]) aug = min(aug, cap[p[v]][v]);
        for(v = t; v != s; v = p[v]) cap[p[v]][v] -= aug, cap[v][p[v]] += aug;
        flow += aug;
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
