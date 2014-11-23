#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 205, maxm = 205, inf = ~0u >> 1;
int V[maxn], head[maxn], next[maxm], cap[maxn][maxn], p[maxn];
int q[maxn], front, rear;
int n, m;

int min(const int& a, const int& b) { return a < b ? a : b; }

int EK(int s, int t) {
    int flow = 0, u, v, e, aug;
    while(1) {
        memset(p, 0, sizeof(p));
        q[front = rear = 0] = s;
        while(front <= rear) {
            u = q[front++];
            for(e = head[u]; e; e = next[e]) {
                v = V[e];
                if(cap[u][v] > 0 && !p[v]) {
                    q[++rear] = v;
                    p[v] = u;
                }
            }
            if(p[t] != 0) break;
        }
        if(p[t] == 0) break;
        aug = inf;
        for(v = t, u = p[v]; v != s; v = u, u = p[u]) aug = min(aug, cap[u][v]);
        for(v = t, u = p[v]; v != s; v = u, u = p[u]) {
            cap[u][v] -= aug;
            cap[v][u] += aug;
        }
        flow += aug;
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
        cap[u][v] += c;
    }
}

int main() {
    init();
    printf("%d\n", EK(1, n));
    return 0;
}
